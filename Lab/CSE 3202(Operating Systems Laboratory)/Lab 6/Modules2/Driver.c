// tail -f /var/log/syslog

#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h> /* For the character driver support */

int hello_open(struct inode *pinode, struct file *pfile)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return 0;
}

ssize_t hello_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return 0;
}

ssize_t hello_write(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
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

static void hello_init(void){
     
     printk(KERN_ALERT "TEST: Hello world\n");

/* Register with the kernel and indicate that we are registering a character device driver */

     register_chrdev(240 /* Major number */,
                      "Simple char driver" /* Driver name */,
                       &hello_file_operations/* File operations */);
     
     return 0;
}

static void hello_exit(void){

     printk(KERN_ALERT "TEST: Good bye\n"); 

/* Unregister the character device driver */

     unregister_chrdev(240,"Simple char driver");

}

module_init(hello_init);
module_exit(hello_exit);
