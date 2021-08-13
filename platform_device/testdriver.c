#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/device.h>
#include<linux/cdev.h>
#include<linux/platform_device.h>

static int major;
static struct class *test_class;

static int test_open (struct inode *node, struct file *filp)
{
	
	return 0;
}

static int test_release (struct inode *node, struct file *filp)
{
	return 0;
}

static struct file_operations test_fops = {
	.owner 		= THIS_MODULE,
	.open 		= test_open,
//	.read 		= test_read,
//	.write 		= test_write,
	.release 	= test_release,
};

static int test_probe(struct platform_device *pdev)
{
	printk("enter probe.\n");

	major = register_chrdev(0, "testdev", &test_fops);

	test_class = class_create(THIS_MODULE, "testdev");
	device_create(test_class, NULL, MKDEV(major, 0), NULL, "test");

	return 0;
}

static int test_remove(struct platform_device *pdev)
{
	printk("enter remove.\n");
	
	unregister_chrdev(major, "testdev");
	device_destroy(test_class, MKDEV(major, 0));
	class_destroy(test_class);

	return 0;
}

struct platform_driver test_drv = {
	.driver = {
		.name 		= "testdev",
	},
	.probe  = test_probe,
	.remove = test_remove,
};

static int __init test_drv_init(void)
{
	platform_driver_register(&test_drv);
	return 0;
}

static void __exit test_drv_exit(void)
{
	platform_driver_unregister(&test_drv);
}


module_init(test_drv_init);
module_exit(test_drv_exit);

MODULE_LICENSE("GPL");
