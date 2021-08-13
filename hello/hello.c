#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

/*安装模块*/
static int hello_init(void)
{
	printk(KERN_INFO "Hello Word\n");//信息“Hello Word”
	return 0;
}

/*卸载模块*/
static void hello_exit(void)
{
	printk(KERN_INFO "Good Bye\n");//信息“Good Bye”
}

module_init(hello_init);//指定模块安装->hello_init
module_exit(hello_exit);//指定模块卸载->hello_exit

MODULE_LICENSE("GPL");//遵循规则
MODULE_AUTHOR("TSBSP");//作者
MODULE_DESCRIPTION("Hello World Module");//模块描述

