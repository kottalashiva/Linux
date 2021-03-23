#include<linux/module.h>
#include<linux/platform_device.h>
#include<linux/init.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/device.h>
#include<linux/uaccess.h>
#include "platform_device.h"


#undef pr_fmt
#define pr_fmt(fmt) "%s: " fmt, __func__

int pcd_open(struct inode *inode, struct file *filep)
{
	pr_info( "Driver: open()\n");
	return 0;
}

int pcd_read(struct file *filep, char __user *buff, size_t count, loff_t *fpos)
{
	pr_info( "Driver: Read()\n");
	return 0;
}

int pcd_write(struct file *filep, char __user *buff, size_t count, loff_t *fpos)
{
	pr_info( "Driver: write()\n");
	return 0;
}

int pcd_lseek(struct file *filep,loff_t *fpos, int whence)
{
	pr_info( "Driver: lseek()\n");
	return 0;
}

int pcd_release(struct inode *inode)
{
	pr_info( "Driver: relase\n");
	return 0;
}

const struct file_operations pcd_fops= {
		.open = pcd_open,
		.write = pcd_write,
		.read = pcd_read,
		.llseek = pcd_lseek,
		.release = pcd_release,
		.owner  = THIS_MODULE,
	};

/*
Called when platform device is name is scanned
*/
int pcd_platform_driver_probe(struct platform_device *pdev)
{
	pr_info("Device detected\n");
	return 0;
}

/*
Called when platform device is removed
*/
int pcd_platform_driver_remove(struct platform_device *pdev)
{
	pr_info("Device removed\n");
	return 0;
}
struct platform_driver pcd_platform_driver = {
		.probe = pcd_platform_driver_probe,
		.remove = pcd_platform_driver_remove,
		.driver = {
			.name = "pseudo-platform-device"
		}
};

static int __init pcdev_platform_init(void)
{
	platform_driver_register(&pcd_platform_driver);	
	return 0;
}

static void __exit pcdev_platform_exit(void)
{
	platform_driver_unregister(&pcd_platform_driver);
}



MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("platform Driver module");
MODULE_AUTHOR("SHIVA");

module_init(pcdev_platform_init);
module_exit(pcdev_platform_exit);