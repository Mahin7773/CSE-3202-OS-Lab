#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

int param_var =0;
module_param(param_var,int,S_IRUSR|S_IWUSR);
int hello_init(void){
     
     printk(KERN_ALERT "TEST: Hello world\n");
	int i=0;
	for(i=0;i<5;i++)
     printk(KERN_ALERT "%d",param_var);
     return 0;
}

void hello_exit(void){

     printk(KERN_ALERT "TEST: Good bye\n"); 
}

module_init(hello_init);
module_exit(hello_exit);
