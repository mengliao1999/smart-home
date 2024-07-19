

# ubuntu系统对应的linux内核的目录
# KERNEL_DIR:=/lib/modules/$(shell uname -r)/build 

# 开发板对应内核源码目录
KERNEL_DIR := /home/hqyj/kernel/kernel-3.4.39/

# 当前目录 
CURRENT_DIR:=$(shell pwd) 

all:
	@ # 模块化编译驱动代码
	make -C $(KERNEL_DIR) M=$(CURRENT_DIR) modules 
	arm-none-linux-gnueabi-gcc led_app.c -o led_app 
clean:
	@ # 清除中间文件
	make -C $(KERNEL_DIR) M=$(CURRENT_DIR) clean 
	rm led_app

obj-m += led_driver.o














