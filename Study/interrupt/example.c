/*GIC*/
/*SGI -> ID(0~15)    */
/*PPI -> ID(16~31)   只可发送到绑定的CPU上*/

/*SPI -> ID(32~1019) 可发送到任何一个CPU上*/
/*设定中断触发的CPU核，一般为CPU0*/
extern int irq_set_affinity (unsigned int irq, const struct cpumask *m);
/*将中断设置到CPUi上*/
irq_set_affinity(irq, cpumask_of(i));

/*申请irq，request_irq()*/
int request_irq(unsigned int irq, irq_handler_t handler, unsigned long flags,
		const char *name, void *dev);
/*irq 申请的硬件中断号*/
/*handler 向系统登记的中断处理函数*/
/*irq flags 是中断处理的属性，指定中断的触发方式和处理方式*/
/*一般设置为设备的设备结构体或者NULL*/
/*request_irq()返回0表示成功，返回-EINVAL表示中断号无效或处理函数指针为NULL*/
/*返回-EBUSY表示中断已被占用且不能共享*/

int devm_request_irq(struct device *dev, unsigned int irq, irq_handler_t handler,
unsigned long irqflags, const char *devname, void *dev_id);
/*devm_开头的API申请内核“managed？”资源，一般不需要出错处理和显式的释放*/
/*ex1*/

/*顶半部handler的类型irq_handler_t的定义为*/
typedef irqreturn_t (*irq_handler_t)(int, void *);
typedef int irqreturn_t;

/*释放irq，free_irq()*/
void free_irq(unsigned int irq, void *dev_id);

/*以下三个函数用于屏蔽中断源*/
void disable_irq(int irq);//立即返回，若在n号中断调用，会引起系统死锁
void disable_irq_nosyne(int irq);//等待中断处理完成
void enable_irq(int irq);

/* 屏蔽本CPU内所有中断*/
#define local_irq_save(flags)//把中断状态保存在flags中
void local_irq_disable(void);//直接禁止中断不保存

/*恢复中断*/
#define local_irq_restore(flags)
void local_irq_enable(void);
/*以上local为本CPU内*/

/*tasklet*/
void my_tasklet_func(unsigned long);//处理函数定义
DECLARE_TASKLET(my_tasklet, my_tasklet_func, data);
/*定义一个tasklet结构my_tasklet, 与my_tasklet_func(data)函数相关*/

/*在需要调度时，用以下函数调用*/
tasklet_schedule(&my_tasklet);
