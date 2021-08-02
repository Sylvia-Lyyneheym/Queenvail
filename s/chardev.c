#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/fs.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>

#define DEV_MEM_SIZE 512

char device_buffer [DEV_MEM_SIZE];
dev_t device_number;
struct cdev pcd_cdev;
static struct class *pcd_class;
struct file_operations pcd_fops;
static int __init pcd_driver_init(void)
{
	/* 1. 动态申请设备号*/
	alloc_chrdev_region(&device_number, 0, 1, "pcd");

	/* 2. 初始化设备*/
	cdev_init(&pcd_cdev, &pcd_fops);

	/* 3. 注册一个设备到VFS(cdev结构)*/
	pcd_cdev.owner = THIS_MODULE;
	cdev_add(&pcd_cdev, device_number, 1);

	/* 4. 创建一个类并注册到内核，创建设备节点 */
	pcd_class = class_create(THIS_MODULE, "pcd");
	device_create(pcd_class, NULL, device_number, NULL, "pcd");
	printk(KERN_INFO "pcd_dirver_init\n");
	return 0;
}

static void __exit pcd_driver_exit(void)
{
	unregister_chrdev_region(&device_number, 1);
	cdev_del(&pcd_cdev);
	printk(KERN_INFO "pcd_driver_exit\n");
}

module_init(pcd_driver_init);
module_exit(pcd_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("TS");
MODULE_DESCRIPTION("A Psuedo char driver!");
