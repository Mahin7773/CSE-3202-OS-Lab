#include <linux/init.h>
#include <linux/module.h>

static void hello_init(void){
     
     printk(KERN_ALERT "TEST: Hello world\n");
     
}

static void hello_exit(void){

     printk(KERN_ALERT "TEST: Good bye\n"); 
}

module_init(hello_init);
module_exit(hello_exit);
