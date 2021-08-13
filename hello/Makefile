#申明变量&变量赋值
#用shell调用外部指令
#用函数获取路径和版本号使其更有移植性和兼容性
#不需要更改内部内容，多数情况下只需要修改头部的定义
PWD :=$(shell pwd)
KERNELVER :=$(shell uname -r)

#目标文件以模块的方式编译（-m）
obj-m :=hello.o

#.PHONY向make说明伪目标
.PHONY : hello clean

#编译规则
hello:
	make -C /lib/modules/$(KERNELVER)/build M=$(PWD) modules

#清楚规则（make clean）
clean: 
	make -C /lib/modules/$(KERNELVER)/build M=$(PWD) clean
