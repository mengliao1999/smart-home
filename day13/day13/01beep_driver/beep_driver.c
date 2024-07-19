#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/io.h>
#include <linux/uaccess.h>
#include <linux/device.h>

#define  GPIOC_BASE_ADDR  0xC001C000

int major = 0;
unsigned int *gpioc_p = NULL;
int retval = 0;
/*cmd = 0 蜂鸣器不响
 *cmd > 0 蜂鸣器响
 * */
unsigned char cmd = 0;

struct class *cls = NULL;
struct device *dev = NULL;

int beep_open (struct inode * inode, struct file *fp)
{
	return 0;
}
ssize_t beep_read(struct file *fp, char __user *u_buf, size_t size, loff_t *offset)
{

	return 0;
}
ssize_t beep_write (struct file *fp, const char __user *u_buf, size_t size, loff_t *offset)
{
	retval = copy_from_user(&cmd,u_buf,size);
	if (retval != 0) {
		return retval;
	}
	if( cmd == 0) {
		*gpioc_p = *gpioc_p & (~(0x1 << 14));
	} else {
		*gpioc_p = *gpioc_p | (1 << 14);
	}

	return 0;
}
int beep_close (struct inode *inode, struct file *fp)
{
	
	return 0;
}
struct file_operations fops = {
	.open = beep_open,
	.read = beep_read,
	.write = beep_write,
	.release = beep_close,
};


static int __init beep_init(void)
{
	// 注册字符设备
	major = register_chrdev(0, "mybeep", &fops);
	if(major < 0) {
		printk("register failed!\n");
		return -EIO;
	}

	// 物理地址到虚拟地址之间的映射
	gpioc_p = ioremap(GPIOC_BASE_ADDR, 40);
	if (gpioc_p == NULL) 
	{
		printk("memery failed!\n");
		return -EFAULT;
	}
	// gpio功能 
	*(gpioc_p + 8) = *(gpioc_p + 8) & (~(0x3 << 28));
	*(gpioc_p + 8) = *(gpioc_p + 8) | (0x1 << 28);
	// 输出功能 
	*(gpioc_p + 1) = *(gpioc_p + 1) | (0x1 << 14);
	// 输出低电平
	*(gpioc_p) = *(gpioc_p) & (~(0x1 << 14));
	
	// 创建class 
	cls = class_create(THIS_MODULE, "mybeep");
	if(IS_ERR(cls)) {
		printk("class create failed!\n");
		return PTR_ERR(cls);
	}
	// 创建设备文件 
	dev = device_create(cls, NULL, MKDEV(major, 0), NULL, "mybeep");
	if(IS_ERR(dev)) {
		printk("device create failed!\n");
		return PTR_ERR(dev);
	}


	return 0;
}

static void __exit beep_exit(void)
{
	device_destroy(cls,MKDEV(major,0));
	class_destroy(cls);
	iounmap(gpioc_p);
	unregister_chrdev(major, "mybeep");
}
module_init(beep_init);
module_exit(beep_exit);
MODULE_LICENSE("GPL");


