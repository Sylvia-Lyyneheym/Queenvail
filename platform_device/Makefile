#this is test by platform_device
KERNELVER := $(shell uname -r)
PWD := $(shell pwd)

obj-m += testdevice.o
obj-m += testdriver.o

.PHONY : make clean

make:
	make -C /lib/modules/$(KERNELVER)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KERNELVER)/build M=$(PWD) clean
