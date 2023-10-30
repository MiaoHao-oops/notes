
#include <linux/module.h> 
#include <linux/vmalloc.h>

static int __init lab2_vmalloc_init(void){
	char *vaddr_8K;
	char *vaddr_1M;
	char *vaddr_64M;
	
	pr_info("lab2-vmalloc init\n");
	vaddr_8K = vmalloc(8 * 1024);
	vaddr_1M = vmalloc(1 * 1024 * 1024);
	vaddr_64M = vmalloc(64 * 1024 * 1024);
	pr_info("vaddr_8K: %p\n", vaddr_8K);
	pr_info("vaddr_1M: %p\n", vaddr_1M);
	pr_info("vaddr_64M: %p\n", vaddr_64M);

	return 0;
}

static void __exit lab2_vmalloc_exit(void){
 
	printk(KERN_ALERT"lab2-vmalloc exit\n");
 
}
 
module_init(lab2_vmalloc_init);
module_exit(lab2_vmalloc_exit);
MODULE_LICENSE("GPL");


