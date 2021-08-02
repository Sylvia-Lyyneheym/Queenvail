KERNELVER :=$(shell uname -r)
PWD :=$(shell pwd)

obj-m = chardev.o

.PHONY : hello clean
hello:
	make -C /lib/modules/$(KERNELVER)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KERNELVER)/build M=$(PWD) clean
