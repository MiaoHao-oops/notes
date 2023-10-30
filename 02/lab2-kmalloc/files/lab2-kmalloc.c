#include <linux/module.h>
#include <linux/slab.h>


static int __init lab2_kmalloc_init(void)
{
	char *kaddr_1K = NULL;
	char *kaddr_8K = NULL;
	pr_info("lab2-kmalloc init\n");
	kaddr_1K = kmalloc((1 * 1024),GFP_KERNEL);
	pr_info("kaddr_1K : %p\n",kaddr_1K);
	kaddr_8K = kmalloc((8 * 1024),GFP_KERNEL);
	pr_info("kaddr_8K : %p\n",kaddr_8K);
    
	return 0;
}

static void __exit lab2_kmalloc_exit(void)
{
	pr_info("lab2-kmalloc exit\n");
}

module_init(lab2_kmalloc_init);
module_exit(lab2_kmalloc_exit);
MODULE_LICENSE("GPL");
