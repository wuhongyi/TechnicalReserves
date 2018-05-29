<!-- README.md --- 
;; 
;; Description: 
;; Author: Hongyi Wu(吴鸿毅)
;; Email: wuhongyi@qq.com 
;; Created: 三 9月 21 20:16:53 2016 (+0800)
;; Last-Updated: 五 9月 23 15:09:56 2016 (+0800)
;;           By: Hongyi Wu(吴鸿毅)
;;     Update #: 19
;; URL: http://wuhongyi.cn -->

# 消息队列

Linux系统中有两个宏定义：  
**MSGMAX**，以字节为单位，定义了一条消息的最大长度。
**MSGMNB**，以字节为单位，定义了一个队列的最大长度。

消息队列就是消息的一个链表，它允许一个或多个进程向它写消息，一个或多个进程从中读消息。具有一定的 FIFO 的特性，但是可实现消息的随即查询。这些消息存在于内核中，由“队列ID”来标识。

## 消息队列属性

```cpp
struct msqid_ds{
 struct ipc_perm_msg_perm;
 msgqnum_t msg_qnum;  //of messages on queue
 sglen_t msg_qbytes; //max of bytes on queue
 Ppd_t msg_lspid; //pid of last msgsnd()
 pid_t msg_lrpid; //pid of last msgrcv() 
 time_t msg_stime; //last msgsnd time
 time_t msg_ctime; //last-change time
}
```

## 打开或创建消息队列

```cpp
#include <sys/msg.h>
int msgget(key_t key,int flag);
```

返回值：成功返回消息队列ID，出错返回-1

- flag:  IPC_CREAT（创建） , IPC_EXCL（如果文件存在则出错） , 权限组合（RWX 0777）


## 消息队列操作

```cpp
#include <sys/msg.h>
int msgctl(int msgid,int cmd,struct msqid_ds *buf);
```

返回值：成功返回0，出错返回-1

- msgid: msggetn返回的ID号
- cmd:
	- IPC_STAT 获取消息队列的属性
	- IPC_SET 设置属性
	- IPC_RMID 删除队列

## 发送消息（存消息）

```cpp
#include <sys/msg.h>
int msgsnd(int msgqid,const void *ptr,size_t nbytes,int flag);
```

返回值：成功返回0，出错返回-1

结构体一般定义为以下形式

ptr:
```cpp
struct mymesg{
 long mtype; //positive message type 优先权 取小于这个绝对值的最小值
 char mtext[512]; //message data of length nbytes
}
```

flag： IPC_NOWWAIT  表示非等待

## 接受消息（取消息）

```cpp
#include <sys/msg.h>
ssize_t msgrcv(int msgqid,void *ptr,size_t nbytes,long type,int flag);
```

返回：成功返回消息的数据部分长度，出错返回-1。

- type = 0:获得消息队列中第一个消息
- type > 0:获得消息队列中类型为type的第一个消息
- type < 0:获得消息队列中小于或等于type绝对值的消息(类型最小的)


----

# 共享内存

共享内存区域是被多个进程共享的一部分物理内存。如果多个进程都把该内存区域映射到自己的虚拟地址空间，则这些进程就都可以直接访问该共享内存区域，从而可以通过该区域进行通信。

共享内存是进程间共享数据的一种最快的方法，一个进程向共享内存区域写入数据，共享这个内存区域的所有进程就可以立刻看到其中的内容。

共享内存实现分为两个步骤：  
- 创建共享内存，使用shmget函数。
- 映射共享内存，将这段创建的共享内存映射到具体的进程空间去，使用shmat函数。


## 共享内存段属性

```cpp
struct shmid_ds{
	struct ipc_perm shm_perm;
	size_t  shm_segsz;				/*size of segment in bytes*/
	pid_t  shm_lpid;				/*pid of last shmop()*/
	pid_t  shm_cpid;				/*pid of creator*/
	shmatt_t shm_nattch;			/*number of current attaches*/
	time_t shm_atime;				/*last-attach time*/
	time_t shm_dtime;				/*last-detach time*/
	time_t shm_ctime;				/*last-change time*/
}
```

## 创建共享内存对象

```cpp
#incldue <sys/shm.h>
int shmget(key_t key,size_t size,int shmflg);
```

返回值：如果成功，返回共享内存段标识符。如果失败，则返回-1。

原型:errno  
EINVAL		无效的内存段大小
EEXIST		内存段已经存在，无法创建
EIDRM		内存段已经被删除
EACCES		权限不够
ENOMEM		没有足够的内存来创建内存段


## 映射共享内存

shmat




服务端进程：  
- 服务进程调用shmget建立共享内存对象
- 同时制定大小及访问许可
- 服务进程将共享内存对象的标识符通知客户进程
- 服务进程附加共享内存对象
- 获得共享内存在该进程空间中的地址
- 服务进程通过该地址访问该共享内存


客户端进程：  
- 客户进程获得共享内存对象的标识符
- 客户进程附加共享内存对象
- 获得共享内存在该进程空间中的地址
- 客户进程通过改地址访问该共享内存

----

# 信号量

进程利用信号量获得共享资源步骤：  
- 测试控制该资源的信号量
- 若信号量为正，则进程可以使用该资源
	- 使用资源时，进程将该信号量减1
	- 不再使用资源时，进程将该信号量值加1
- 若信号量为0，则进程进入睡眠状态


## 信号量集属性

```cpp
struct semid_ds{
	struct ipc_perm   sem_perm;
	unsigned short    sem_nsems;			/*of semaphores in set*/
	time_t					sem_otime;			/*last semop time*/
	time_t					sem_ctime;			/*last change time*/
} 
```

## 创建信号量集

```cpp
#incldue <sys/sem.h>
int semget(key_t key,int nsems,int flag);
```

返回值：成功返回信号量集ID，出错返回-1。

nsems：信号量集中信号量的个数

flag:	IPC_CREAT,IPC_EXCL,权限组合


## 信号集控制

```cpp
#include <sys/sem.h>
int semctl(int semid,int semnum,int cmd,.../*union semun arg*/)
```


```cpp
union semum{
	int 				val;
	struct  semid_ds	buf;
	usigned short		*array;
}
```

通过cmd参数设定对信号量要执行的操作:
IPC_STAT			获取信号量集的属性
IPC_SET			设置信号量集的属性
IPC_RMID			删除信号量集
GETVAL				返回semnum信号量的值
SETVAL				设置semnum信号量的值
GETTALL			获取所有信号量的值
SETALL				设置所有信号量的初始值


## 信号量集的操作

```cpp
#include <sys/sem.h>
int semop(int semid,struct sembuf *semop,size_t  nops);
```

返回：成功返回0，出错返回-1。

```cpp
struct	sembuf{
	unsigned short		sem_num;		/*member in set*/
	short					sem_op;		/*operation(negative,0,positive)*/
	short					sem_flg;		/*IPC_NOWAIT,SEM_UNDO*/
}
```

- 基于基本信号量的up和down操作(PV操作)
- 可用于进程间的互斥和同步





<!-- README.md ends here -->
