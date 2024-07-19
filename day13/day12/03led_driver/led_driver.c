// 头文件 
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/io.h>

#define  GPIOA_BASE_ADDR  0xC001A000
#define  GPIOB_BASE_ADDR  0xC001B000
#define  GPIOE_BASE_ADDR  0xC001E000

int major = 0;
int retval = 0;
unsigned int *gpioa_p = NULL;
unsigned int *gpiob_p = NULL;
unsigned int *gpioe_p = NULL;
/*
 * k_buf[0] = 1 : 红灯 
 * k_buf[0] = 2 : 绿灯 
 * k_buf[0] = 3 : 蓝灯 
 *
 * k_buf[1] = 1 : 输出高
 * k_buf[1] = 0 : 输出低
 * */

char k_buf[2] = "";


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
	// copy_from_user
	retval = copy_from_user(k_buf, u_buf, sizeof(k_buf));
	if (retval != 0) 
	{
		printk("user copy data to kernel faild!\n");
		return -1;
	}
	switch(k_buf[0]) {
		case 1:  // 红灯
			if (k_buf[1] == 1) {
				// gpioa28引脚输出高电平
				*gpioa_p = *gpioa_p | (1 << 28);
			} else if (k_buf[1] == 0){
				// gpioa28引脚输出低电平
				*gpioa_p = *gpioa_p & (~(1 << 28));			
			}
			break;
		case 2:
			if (k_buf[1] == 1) {
				// gpioe13引脚输出高电平
				*gpioe_p = *gpioe_p | (1 << 13);	
			} else if (k_buf[1] == 0){
				// gpioe13引脚输出高电平
				*gpioe_p = *gpioe_p & (~(1 << 13));	
			}
			break;
		case 3:
			if (k_buf[1] == 1) {
				// gpiob12引脚输出高电平
				*gpiob_p = *gpiob_p | (1 << 12);
			} else if (k_buf[1] == 0){
				// gpiob12引脚输出高电平
				*gpiob_p = *gpiob_p & (~(1 << 12));	
			}
			break;
	}
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
	
	// 红灯
	gpioa_p = ioremap(GPIOA_BASE_ADDR, 40);
	if (gpioa_p == NULL) 
	{
		printk("memery failed!\n");
		return -EFAULT;
	}
	// 设置为GPIOA28引脚为GPIO功能
	*(gpioa_p + 9) = *(gpioa_p + 9) & (~(0x3 << 24)); 
	// 设置GPIOA28引脚为输出功能 
	*(gpioa_p + 1) = *(gpioa_p + 1) | (1 << 28);
	// gpioa28引脚输出低电平
	*gpioa_p = *gpioa_p & (~(1 << 28));			

	// 绿灯 
	gpioe_p = ioremap(GPIOE_BASE_ADDR, 40);
	if (gpioe_p == NULL) 
	{
		printk("memery failed!\n");
		return -EFAULT;
	}
	// 设置为GPIOE13引脚为GPIO功能
	*(gpioe_p + 8) = *(gpioe_p + 8) & (~(0x3 << 26));
	// 设置GPIOE13引脚为输出功能 
	*(gpioe_p + 1) = *(gpioe_p + 1) | (1 << 13);
	// gpioe13引脚输出高电平
	*gpioe_p = *gpioe_p & (~(1 << 13));	

	// 蓝灯
	gpiob_p = ioremap(GPIOB_BASE_ADDR, 40);
	if (gpiob_p == NULL) 
	{
		printk("memery failed!\n");
		return -EFAULT;
	}
	// 设置为GPIOB12引脚为GPIO功能
	*(gpiob_p + 8) = *(gpiob_p + 8) & (~(0x3 << 24));
	*(gpiob_p + 8) = *(gpiob_p + 8) | (0x2 << 24);
	// 设置GPIOB12引脚为输出功能 
	*(gpiob_p + 1) = *(gpiob_p + 1) | (1 << 12);
	// gpiob12引脚输出高电平
	*gpiob_p = *gpiob_p & (~(1 << 12));	
	
	return 0;
}
// 告诉内核驱动程序的入口函数是demo_init
module_init(led_init);

// 出口函数  __exit:给编译器使用
static void __exit led_exit(void) 
{ // 释放资源
	printk(KERN_ERR "%s-%s:%d\n", __FILE__, __func__, __LINE__);
	
	iounmap(gpiob_p);
	iounmap(gpioe_p);
	iounmap(gpioa_p);
	// 注销字符设备驱动 
	unregister_chrdev(major,"myled");
}
// 告诉内核驱动程序的出口函数是demo_exit
module_exit(led_exit);

//许可证  遵循GPL的开源协议
MODULE_LICENSE("GPL");






