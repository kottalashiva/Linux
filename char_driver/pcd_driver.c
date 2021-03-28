#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/cdev.h>

#include<linux/device.h>
#include<linux/uaccess.h>

#define SUCCESS 0
#undef pr_fmt
#define pr_fmt(fmt) "%s: " fmt,  __func__
#define MEM_SIZE 512

char buffer[MEM_SIZE];
int fileInUse = 0;
dev_t device_number; //Holds the device number.
struct class *pcd_class; // Global variable for the device class
struct cdev pcd_dev; // Global variable for the character device structure



int pcd_open(struct inode *inode, struct file *filep)
{
	if(fileInUse == 1 )
		return -EBUSY;
	pr_info("Opening the file\n");
	fileInUse = 1;

	return SUCCESS;
}

int pcd_read(struct file *filep, char __user *buff, size_t count, loff_t *fpos)
{
	printk(KERN_INFO "Driver: Read()\n");
	pr_info("Current file position = %lld\n", *fpos);
	if((*fpos + count) > MEM_SIZE)
		count = MEM_SIZE - *fpos;
	if(copy_to_user(buff, buffer[*fpos], count))
		return -EFAULT;
	*fpos += count;
	pr_info("Number of bytes sucessfully read %u\n", count);
	pr_info("user buffer is %s", buff);
	pr_info("storage buffer is %s", buffer);
	pr_info("storage buffer is %s", buffer[*fpos]);
	return count;
}

int pcd_write(struct file *filep, char __user *buff, size_t count, loff_t *fpos)
{
	printk(KERN_INFO "Driver: write()\n");
	pr_info("Write requested for %u bytes", count);
	pr_info("Current file posistion = %lld\n", *fpos);
	if((*fpos + count) > MEM_SIZE)
		count = MEM_SIZE - *fpos;
	if(copy_from_user(&buffer[*fpos], buff, count))
		return -EFAULT;
	*fpos = *fpos +  count;
	pr_info("Number of bytes successfully written = %u\n", count);
	pr_info("update file position= %lld\n", *fpos);
	return count;
}

int pcd_lseek(struct file *filep,loff_t *fpos, int whence)
{
	printk(KERN_INFO "Driver: lseek()\n");
	return 0;
}

int pcd_release(struct inode *inode)
{
	if(fileInUse == 1)
		fileInUse = 0;

	pr_info("file closed");	
	return SUCCESS;
}

const struct file_operations pcd_fops= {
		.open = pcd_open,
		.write = pcd_write,
		.read = pcd_read,
		.llseek = pcd_lseek,
		.release = pcd_release,
		.owner  = THIS_MODULE,
	};

static int __init test_init(void)
{

	pr_info("Init Module\n");	
	// create device number
	alloc_chrdev_region(&device_number, 0, 1, "PCD");

	// Device Class crate This will be created as /sys/dev/PCD_CLASS folder.
	pcd_class = class_create(THIS_MODULE, "PCD_CLASS");
	
	// Device Class crate This will be created under /sys/dev/deviceNum folder.
	device_create(pcd_class, NULL, device_number, NULL, "PCD");
	
	// make char dev device registration with VFS
	cdev_init(&pcd_dev, &pcd_fops);
	pcd_dev.owner=THIS_MODULE;
	cdev_add(&pcd_dev, device_number, 3);

	return 0;
}

static void test_cleanup(void)
{
	pr_info("Clean up module\n");
}


MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Char Driver module");
MODULE_AUTHOR("SHIVA");

module_init(test_init);
module_exit(test_cleanup);
