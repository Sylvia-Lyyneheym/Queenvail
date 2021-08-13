#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/device.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/platform_device.h>

static struct platform_device test_dev = {
	.name = "testdev",
	.id = -1,
};

typedef void conversion_func_t(char *dest, const char *src);

static int __init test_dev_init(void)
{
	printk(KERN_DEBUG ": device init.\n");
	platform_device_register(&test_dev);
	return 0;
}

/*static void string_keep(char *dest, const char *src)
{
	while ((*dest++ = *src++));
}

static void string_to_upper(char *dest, const char *src)
{
	while ((*dest++ = toupper(*src++)));
}
*/
static void __exit test_dev_exit(void)
{
	printk(KERN_DEBUG ": device exit.\n");
	platform_device_unregister(&test_dev);
}

module_init(test_dev_init);
module_exit(test_dev_exit);

MODULE_LICENSE("GPL");
