/*                                                     
 * $Id: hello.c,v 1.5 2004/10/26 03:32:21 corbet Exp $ 
 */                                                    
#include <linux/init.h>
#include <linux/module.h>

//globals
int howmany=0;
char *whom=NULL;	


MODULE_LICENSE("Dual BSD/GPL");
module_param(howmany, int, S_IRUGO);
module_param(whom, charp, S_IRUGO);


static int hello_init(void)
{
	printk(KERN_ALERT "hello  world \n");
	printk(KERN_ALERT "module is up \n");
	printk(KERN_ALERT "howmany=%d \n", howmany);
	printk(KERN_ALERT "whom=%s \n", whom);
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "bye bye \n");
	printk(KERN_ALERT "module is down \n");
	return ;
}

module_init(hello_init);
module_exit(hello_exit);
