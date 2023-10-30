#include <linux/module.h>
#include <linux/io.h>

static unsigned long from = 0xfc;
static unsigned long num = 4;
static const char *name = "lab2";

static int __init lab2_io_mem_init(void)
{
	request_mem_region(from, num, name);
	return 0;
}


static void __exit lab2_io_mem_exit(void)
{
	release_region(from, num);
}

module_init(lab2_io_mem_init);
module_exit(lab2_io_mem_exit);
MODULE_LICENSE("GPL");