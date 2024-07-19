// 头文件 
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

int major = 0;
int led_open (struct inode *inode, struct file *fp)
{
	printk(KERN_ERR "%s-%s:%d\n", __FILE__, __func__, __LINE__);
	return 0;
}
ssize_t led_read (struct file *fp, char __user *u_buf, size_t size, loff_t *offset)
{
	printk(KERN_ERR "%s-%s:%d\n", __FILE__, __func__, __LINE__);
	return 0;
}
ssize_t led_write (struct file *fp, const char __user *u_buf, size_t size, loff_t *offset)
{
	printk(KERN_ERR "%s-%s:%d\n", __FILE__, __func__, __LINE__);
	return 0;
}
int led_close (struct inode *inode, struct file *fp)
{
	printk(KERN_ERR "%s-%s:%d\n", __FILE__, __func__, __LINE__);
	return 0;
}
//定义操作方法结构体，并进行初始化
struct file_operations fops = {
	.open = led_open,
	.read = led_read,
	.write = led_write,
	.release = led_close, 
};


// 入口函数  __init:给编译器使用
static int __init led_init(void) 
{ // 申请资源
	printk(KERN_ERR "%s-%s:%d\n", __FILE__, __func__, __LINE__);
	// 注册led灯的字符设备驱动 
	major = register_chrdev(0, "myled", &fops);
	if (major < 0) {
		printk("registe char device failed!\n");
		return -EBUSY;
	}
	return 0;
}
// 告诉内核驱动程序的入口函数是demo_init
module_init(led_init);

// 出口函数  __exit:给编译器使用
static void __exit led_exit(void) 
{ // 释放资源
	printk(KERN_ERR "%s-%s:%d\n", __FILE__, __func__, __LINE__);
	
	// 注销字符设备驱动 
	unregister_chrdev(major,"myled");
}
// 告诉内核驱动程序的出口函数是demo_exit
module_exit(led_exit);

//许可证  遵循GPL的开源协议
MODULE_LICENSE("GPL");






