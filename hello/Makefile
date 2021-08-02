PWD :=$(shell pwd)
KERNELVER :=$(shell uname -r)

obj-m :=hello.o

.PHONY : hello clean

hello:
	make -C /lib/modules/$(KERNELVER)/build M=$(PWD) modules

clean: 
	make -C /lib/modules/$(KERNELVER)/build M=$(PWD) clean
