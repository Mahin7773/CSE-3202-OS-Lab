#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/fs.h> /* For the character driver support */
#include <linux/uaccess.h>
MODULE_LICENSE("Dual BSD/GPL");

char *mybuffer;
int hello_open(struct inode *pinode, struct file *pfile)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return 0;
}

ssize_t hello_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
    printk(KERN_ALERT "Received %s %d %d\n",buffer,length,offset);	
    return 0;
}

ssize_t hello_write(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{printk(KERN_ALERT "length %d \n",length);
	printk(KERN_ALERT "Received %s %d \n",buffer,length);
    return length;
}

int hello_close(struct inode *pinode, struct file *pfile)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return 0;
}

/* To hold the file operations performed on this device */

struct file_operations hello_file_operations = {
    .owner = THIS_MODULE,
    .open  = hello_open,
    .read  = hello_read,
    .write = hello_write,
    .release = hello_close,       
};

static int hello_init(void){
     
     printk(KERN_ALERT "TEST: Hello world\n");

/* Register with the kernel and indicate that we are registering a character device driver */

     register_chrdev(240 /* Major number */,
                      "SimpleDriver" /* Driver name */,
                       &hello_file_operations/* File operations */);

	mybuffer=kmalloc(1,GFP_KERNEL);
	memset(mybuffer,'\0',1);
     
     return 0;
}

static void hello_exit(void){

     printk(KERN_ALERT "TEST: Good bye\n"); 

/* Unregister the character device driver */

     unregister_chrdev(240,"SimpleDriver");
if(mybuffer){
kfree(mybuffer);
}
}

module_init(hello_init);
module_exit(hello_exit);
