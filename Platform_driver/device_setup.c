#include<linux/module.h>
#include<linux/platform_device.h>

#include "platform_device.h"

/* 
override the print format
*/

#undef pr_fmt
#define pr_fmt(fmt) "%s: " fmt, __func__

/* 
	Release the pcdev structure which is present as the platform_device struct member
*/
static void pcdev_release(struct device *dev)
{
	pr_info("Device releaseed");
}

struct pcdev_platfrom_data pcdev_data[2] = {
	[0] = {.size=512, .perm=RDWR, .serial_number= "PCDEVABC11111"},
	[1] = {.size=512, .perm=RDWR, .serial_number= "PCDEVXYZ22222"}
};
struct platform_device platform_dev1 = {
				.name = "pseudo-platform-device", 
				.id = 0,
				.dev = {
						.platform_data = &pcdev_data[0], 
						.release = pcdev_release
						}
				};

struct platform_device platform_dev2 = {
				.name = "pseudo-platform-device", 
				.id = 1,
				.dev = {
						.platform_data = &pcdev_data[1],
						.release = pcdev_release
						}
				};

static int __init pcdev_platform_init(void)
{
	platform_device_register(&platform_dev1);
	platform_device_register(&platform_dev2);
	pr_info("Device setup loaded\n");
	return 0;
}

static void __exit pcdev_platform_exit(void)
{
	platform_device_unregister(&platform_dev1);
	platform_device_unregister(&platform_dev2);
	pr_info("Device setup removed\n");
}

module_init(pcdev_platform_init)
module_exit(pcdev_platform_exit)
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Platform Driver module");
MODULE_AUTHOR("SHIVA");