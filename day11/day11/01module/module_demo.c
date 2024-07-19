// 头文件 
#include <linux/init.h>
#include <linux/module.h>

// 入口函数  __init:给编译器使用
static int __init demo_init(void) 
{ // 申请资源
	printk(KERN_ERR "%s-%s:%d\n", 
				__FILE__, __func__, __LINE__);
	return 0;
}
// 告诉内核驱动程序的入口函数是demo_init
module_init(demo_init);

// 出口函数  __exit:给编译器使用
static void __exit demo_exit(void) 
{ // 释放资源
	printk(KERN_ERR "%s-%s:%d\n", 
				__FILE__, __func__, __LINE__);

}
// 告诉内核驱动程序的出口函数是demo_exit
module_exit(demo_exit);

//许可证  遵循GPL的开源协议
MODULE_LICENSE("GPL");






