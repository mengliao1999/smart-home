
# KERNEL_DIR := /lib/modules/$(shell uname -r)/build
KERNEL_DIR := /home/hqyj/kernel/kernel-3.4.39/

CURRENT_DIR := $(shell pwd)


all:
	make -C $(KERNEL_DIR) M=$(CURRENT_DIR) modules 
	arm-none-linux-gnueabi-gcc beep_app.c -o beep_app
clean:
	make -C $(KERNEL_DIR) M=$(CURRENT_DIR) clean 
	rm beep_app

obj-m += beep_driver.o


