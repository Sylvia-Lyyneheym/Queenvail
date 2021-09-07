/*file结构体*/
/*系统中每个打开的文件在内核中都有一个相应的struct file结构体*/
/*它在打开文件时由内核创建，并传递给在文件上进行操作的任何函数*/
struct file{
	struct file_operations *f_op;//和文件关联的操作
	mode_t f_mode;				 //文件读写权限
	struct dentry *f_dentry;	 //与文件关联的目录入口结构
	struct *private_data;		 //文件私有数据
}

/*inode结构体*/
/*VFS inode包含文件访问权限、拥有者、组、大小、生成时间、访问时间*/
/*最后修改时间等信息。是文件系统连接任何子目录、文件的桥梁*/
struct inode {
	umode_t i_mode;      //inode的权限
	uid_t i_uid;		 //inode拥有者
	gid_t i_gid;		 //inode所属群组id
	dev_t i_rdev;		 //设备文件，设备号
	struct cdev *i_cdev; //字符设备对应为cdev结构体指针
}

struct bus_type {
	struct bus_attribute 		*bus_attrs;//总线属性
	struct device_attribute 	*dev_attrs;//设备属性
	struct driver_attribute 	*drv_attrs;//驱动属性
	/*设备驱动匹配函数(match)*/
	int(*match)(struct device *dev, struct device_driver *dev);
};

/*设备驱动结构体*/
struct device_driver {
	const char 						*name;			//设备驱动的名字
	struct bus_type 				*bus;			//设备驱动所属总线

	struct module 					*owner;			//设备驱动自身模块
	const char 						*mod_name;		//驱动模块名字

	const struct of_device_id 		*of_match_table;//DTS属性相关
	int (*probe)(struct device *dev);			//注册操作接口 创建设备文件

	int (*remove)(struct device *dev);				//销毁设备
	const struct attribute_group 	*groups;		//创建簇设备时需要

	const struct dev_pm_ops 		*pm;			//与设备的电源管理相关
}

/*设备结构体*/
struct device {
	struct device 				*parent;		//指向父设备的指针
	struct bus_type 			*bus;			//所属的总线
	struct device_driver 		*driver;		//对应的驱动
	struct device_node 			*of_node;		//相关的设备树节点
	dev_t 						devt;			//设备号
}
