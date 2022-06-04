#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("ananthm1254");

static int __init hello_init(void)
{
	printk("Hello World!\n");
	return 0;
}

static void __exit hello_exit(void)
{
	printk("Goodbye, World!\n");
}

module_init(hello_init);
module_exit(hello_exit);
