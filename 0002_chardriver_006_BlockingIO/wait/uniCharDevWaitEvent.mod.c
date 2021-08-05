#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x8cab6321, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xe46c6bf7, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x63c2fa45, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0xbdf7fa88, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0xdc09968f, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xe43ca4b0, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x5a28158e, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0xedfc8419, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x6d8a9912, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0xcba6ffe1, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x1cf52aa9, __VMLINUX_SYMBOL_STR(cdev_alloc) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0x46f583d5, __VMLINUX_SYMBOL_STR(module_refcount) },
	{ 0xe45f60d8, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x4f8b5ddb, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0x75bb675a, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0x4292364c, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0xa56d356, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0xa1c76e0a, __VMLINUX_SYMBOL_STR(_cond_resched) },
	{ 0x62fcd40d, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "48A32D54D455BF129CC7ADA");
