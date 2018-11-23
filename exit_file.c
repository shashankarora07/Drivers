#include "header.h"

static void __exit mychar_exit(void)
{
	cdev_del(&c_device);
	device_destroy(device_class, device_major);
	device_class(device_class);
	unregister_chrdev_region(device_major, 1);

	printk(KERN_INFO "driver is out");
}
module_exit(mychar_exit);
