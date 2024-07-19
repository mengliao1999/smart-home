

# ubuntu系统对应的linux内核的目录
KERNEL_DIR:=/lib/modules/$(shell uname -r)/build 
# 当前目录 
CURRENT_DIR:=$(shell pwd) 

all:
	@ # 模块化编译驱动代码
	make -C $(KERNEL_DIR) M=$(CURRENT_DIR) modules 
clean:
	@ # 清除中间文件
	make -C $(KERNEL_DIR) M=$(CURRENT_DIR) clean 

obj-m += module_demo.o














