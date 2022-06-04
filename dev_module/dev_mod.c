#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ananthm1254");
MODULE_DESCRIPTION("Registers a device nr.");

static int driver_open(struct inode *device_file, struct file *instance)
{
	printk("dev - open was called!\n");
	return 0;
}


static int driver_close(struct inode *device_file, struct file *instance)
{
	printk("dev - close was called!\n");
	return 0;
}

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = driver_open,
	.release = driver_close
};

#define MYMAJOR 40

static int __init hello_init(void)
{
	int retval;
	printk("Hello World!\n");
	retval = register_chrdev(MYMAJOR, "dev_mod", &fops);
	if (retval == 0)
		printk("dev = device number Major : %d, Minor %d\n", MYMAJOR, 0);
	else if (retval > 0)
		printk("dev = device number Major : %d, Minor %d\n", MYMAJOR, 0);
	else
		printk("no device registered\n");
	return 0;
}

static void __exit hello_exit(void)
{	
	unregister_chrdev(MYMAJOR, "dev_mod");
	printk("Goodbye, World!\n");
}

module_init(hello_init);
module_exit(hello_exit);
