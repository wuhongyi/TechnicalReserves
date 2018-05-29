<!-- README.md --- 
;; 
;; Description: 
;; Author: Hongyi Wu(吴鸿毅)
;; Email: wuhongyi@qq.com 
;; Created: 二 6月 21 14:00:24 2016 (+0800)
;; Last-Updated: 二 6月 21 14:58:57 2016 (+0800)
;;           By: Hongyi Wu(吴鸿毅)
;;     Update #: 8
;; URL: http://wuhongyi.cn -->

# linux 系统文件操作sem_open, sem_close, sem_post, sem_wait

信号灯分为有名信号灯和内存信号灯

## Posix有名信号灯

### posix有名信号灯函数

函数sem\_open创建一个新的有名信号灯或打开一个已存在的有名信号灯。有名信号灯总是既可用于线程间的同步，又能用于进程间的同步。

```
sem_open

名称:：
sem_open
功能：
创建并初始化有名信号灯
头文件：
#include <semaphore.h>
函数原形：
sem_t *sem_open(const char *name,int oflag,/*mode_t mode,unsigned int value*/);
参数：
name   信号灯的外部名字
oflag   选择创建或打开一个现有的信号灯
mode 权限位
value 信号灯初始值
返回值：
成功时返回指向信号灯的指针，出错时为SEM_FAILED
      
oflag参数能是0、O_CREAT（创建一个信号灯）或O_CREAT|O_EXCL（如果没有指定的信号灯就创建），如果指定了O_CREAT，那 么第三个和第四个参数是需要的；其中mode参数指定权限位，value参数指定信号灯的初始值，通常用来指定共享资源的书面。该初始不能超过 SEM_VALUE_MAX，这个常值必须低于为32767。二值信号灯的初始值通常为1，计数信号灯的初始值则往往大于1。
   如果指定了O_CREAT（而没有指定O_EXCL），那么只有所需的信号灯尚未存在时才初始化他。所需信号灯已存在条件下指定O_CREAT不是个错 误。该标志的意思仅仅是“如果所需信号灯尚未存在，那就创建并初始化他”。不过所需信号灯等已存在条件下指定O_CREAT|O_EXCL却是个错误。
   sem_open返回指向sem_t信号灯的指针，该结构里记录着当前共享资源的数目。
```

```cpp
/*semopen.c*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> /* For O_* constants */
#include <sys/stat.h> /* For mode constants */
#include <semaphore.h>

int main(int argc,char**argv)
{
sem_t *sem;

if(argc!=2)
{
printf(“please input a file name!＼n”);
exit(1);
}
sem=sem_open(argv[1],O_CREAT,0644,1);
exit(0);
}
```

----

```
sem_close

名称:：
sem_close
功能：
关闭有名信号灯
头文件：
#include 
函数原形：
int sem_close(sem_t *sem);
参数：
sem 指向信号灯的指针
返回值：
若成功则返回0，否则返回-1。
```

一个进程终止时，内核还对其上仍然打开着的所有有名信号灯自动执行这样的信号灯关闭操作。不论该进程是自愿终止的还是非自愿终止的，这种自动关闭都会发生。但应注意的是关闭一个信号灯并没有将他从系统中删除。这就是说，Posix有名信号灯至少是随内核持续的：即使当前没有进程打开着某个信号灯，他的值仍然保持。

----

```
sem_unlink

名称:：
sem_unlink
功能：
从系统中删除信号灯
头文件：
#include 
函数原形：
int sem_unlink(count char *name);
参数：
name   信号灯的外部名字
返回值：
若成功则返回0，否则返回-1。
```

有名信号灯使用sem\_unlink从系统中删除。每个信号灯有一个引用计数器记录当前的打开次数，sem\_unlink必须等待这个数为0时才能把name所指的信号灯从文件系统中删除。也就是要等待最后一个sem\_close发生。

```cpp
int main(int argc,char**argv)
{
sem_t *sem;
int val;
if(argc!=2)
{
printf(“please input a file name!＼n”);
exit(1);
}
if((sem_unlink(argv[1]))!=0)
perror(“sem_unlink”);
else
printf(“success”);
exit(0);
}
```

em\_unlink会马上删除指定的信号量名，但要等到所有打开该信号量的进程关闭该信号量后才删除该信号。详细地说，当进程创建一个有名信号量，会在/dev/shm下生成一个sem.xxx的文件，所有打开该信号量的进程（包括创建它的进程）都会增加该文件的引用计数，并且这个计数由内核管理。当调用sem\_unlink时，/dev/shm下的sem.xxx文件会马上被删除，但是信号量本身并没有被删除，所有已打开该信号量的进程仍能正常使用它。直到所有打开该信号量的进程关闭该信号量后，内核才真正删除信号量。因此，信号量跟sem.xxx并不是共存亡的。

```cpp
/* sem_create.cpp */
#include <iostream>
#include <fcntl.h>		   /* For O_* constants */
#include <sys/stat.h>		/* For mode constants */
#include <semaphore.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>
int main()
{
  sem_t *psem = sem_open( "/sem_test",O_CREAT,S_IRWXU,1 );
  if ( SEM_FAILED == psem )
  {
    std::cout << "sem_open fail:" << strerror(errno) << std::endl;
    return 0;
  }
  int sval = 0;
  sem_getvalue( psem,&sval );
  std::cout << "sleep now ....value is " << sval << std::endl;
  sleep( 30 );
  sem_getvalue( psem,&sval );
  std::cout << "wake up ....value is " << sval << std::endl;
  sem_post( psem );
  sem_getvalue( psem,&sval );
  std::cout << "raise value and try again ....value is " << sval << std::endl;
  sem_close( psem );
}
/**
 *
 * sem_destruct.cpp
 */
#include <iostream>
#include <fcntl.h>		   /* For O_* constants */
#include <sys/stat.h>		/* For mode constants */
#include <semaphore.h>
#include <cerrno>
#include <cstring>
int main()
{
  sem_t *psem = sem_open( "/sem_test",O_CREAT,S_IRWXU,1 );
  if ( SEM_FAILED == psem )
  {
    std::cout << "sem_open fail:" << strerror(errno) << std::endl;
    return 0;
  }
  std::cout << "decrease value and remove sem now..." << std::endl;
  sem_wait ( psem );
  sem_close( psem );
  sem_unlink( "/sem_test" );
  std::cout << "sem should remove from /dev/shm,but not really remove" << std::endl;
}
```

```
分别编译上面的文件：

g++ -pthread -o sem_create sem_create.cpp
g++ -pthread -o sem_destruct sem_destruct.cpp
先运行sem_create，再运行sem_destruct这时个可以看到输出为：

可以看到，即使sem_destruct从/dev/shm把信号量删除了，ls /dev/shm也确认对应的文件删除了。但是经过sleep的sem_create进程在wake up后仍能对信号量进行操作。

可以看到，有名信号量一旦打开后，跟名字并没有多大关系。下面再来测试有名信号量调用sem_unlink但仍有进程在使用，这时另外一个进程又要创建同名信号量的情况
```

```cpp
/**
  *
  * sem_again.cpp
  */
#include <iostream>
#include <fcntl.h>		   /* For O_* constants */
#include <sys/stat.h>		/* For mode constants */
#include <semaphore.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>
int main()
{
  sem_t *psem = sem_open( "/sem_test",O_CREAT|O_EXCL,S_IRWXU,1 );
  if ( SEM_FAILED == psem )
  {
    std::cout << "sem_open fail:" << strerror(errno) << std::endl;
    return 0;
  }
  int sval = 0;
  sem_getvalue( psem,&sval );
  //std::cout << "sleep now ....value is " << sval << std::endl;
  //sleep( 30 );
  
  sem_getvalue( psem,&sval );
  std::cout << "value is " << sval << std::endl;
  sem_post( psem );
  sem_getvalue( psem,&sval );
  std::cout << "raise value and try again ....value is " << sval << std::endl;
  sem_close( psem );
  sem_unlink( "/sem_test" );
}
```

在sem\_again中特意使用了O\_CREATE|O\_EXCL标志，如果已存在同名信号量，则创建失败。但从上面的结果来看，创建成功并且互不干扰。也就是说，一个有名信号量，在打开并调用sem\_unlink后可以当作无名信号量来使用(但这时新的进程还想使用该信号量，不可能了)。


----
 
```
sem_getvalue

名称:：
sem_getvalue
功能：
测试信号灯
头文件：
#include 
函数原形：
int sem_getvalue(sem_t *sem,int *valp);
参数：
sem 指向信号灯的指针
返回值：
若成功则返回0，否则返回-1。
sem_getvalue在由valp指向的正数中返回所指定信号灯的当前值。如果该信号灯当前已上锁，那么返回值或为0，或为某个负数，其绝对值就是等待该信号灯解锁的线程数。
``` 

----

```
sem_wait/sem_trywait

名称:：
sem_wait/sem_trywait
功能：
等待共享资源
头文件：
#include 
函数原形：
int sem_wait(sem_t *sem); 
int sem_trywait(sem_t *sem);
参数：
sem 指向信号灯的指针
返回值：
若成功则返回0，否则返回-1。
```

我们能用sem\_wait来申请共享资源，sem\_wait函数能测试所指定信号灯的值，如果该值大于0，那就将他减1并即时返回。我们就能使用申请来的 共享资源了。如果该值等于0，调用线程就被进入睡眠状态，直到该值变为大于0，这时再将他减1，函数随后返回。sem\_wait操作必须是原子的。 sem\_wait和sem\_trywait的差别是：当所指定信号灯的值已是0时，后者并不将调用线程投入睡眠。相反，他返回一个EAGAIN错误。

----
 
```
sem_post

名称:：
sem_post
功能：
挂出共享资源
头文件：
#include 
函数原形：
int sem_post(sem_t *sem);
int sem_getvalue(sem_t *sem,int *valp);
参数：
sem 指向信号灯的指针
返回值：
若成功则返回0，否则返回-1。
```

当一个线程使用完某个信号灯时，他应该调用sem\_post来告诉系统申请的资源已用完。本函数和sem_wait函数的功能正好相反，他把所指定的信号灯的值加1，然后唤醒正在等待该信号灯值变为正数的任意线程。

---

## 关于posix有名信号灯使用的几点注意

我们要注意以下几点：

- Posix有名信号灯的值是随内核持续的。也就是说，一个进程创建了一个信号灯，这个进程结束后，这个信号灯还存在，并且信号灯的值也不会改动。
- 当持有某个信号灯锁的进程没有释放他就终止时，内核并不给该信号灯解锁。
- posix有名信号灯应用于多线程

```cpp
void *thread_function(void *arg); /*线程入口函数*/
void print(pid_t); /*共享资源函数*/
sem_t *sem; /*定义Posix有名信号灯*/
int val; /*定义信号灯当前值*/

int main(int argc,char *argv[])
{
int n=0;

if(argc!=2)
{
printf(“please input a file name!＼n”);
exit(1);
}
sem=sem_open(argv[1],O_CREAT,0644,3); /*打开一个信号灯*/

while(n++循环创建5个子线程，使他们同步运行*/
{
if（（pthread_create(&a_thread,NULL,thread_function,NULL)）!=0）
       {
         perror(“Thread creation failed”);
         exit(1);
      }
}
pthread_join(a_thread,NULL);
sem_close(bin_sem);
sem_unlink(argv[1]);
}

void *thread_function(void *arg)
{
sem_wait(sem); /*申请信号灯*/
print(); /*调用共享代码段*/
sleep(1); 
sem_post(sem); /*释放信号灯*/
printf(“I’m finished,my tid is %d＼n”,pthread_self());
}

void print()
{
printf(“I get it,my tid is %d＼n”,pthread_self());
sem_getvalue(sem,&val);
printf(“Now the value have %d＼n”,val);
}

// 程式用循环的方法建立5个线程，然后让他们调用同一个线程处理函数thread_function，在函数里我们利用信号量来限制访问共享资源的线程数。共享资源我们用print函数来代表，在真正编程中他有能是个终端设备（如打印机）或是一段有实际意义的代码。
```

- posix有名信号灯应用于多进程

下面就是应用Posix有名信号灯的一个小程序。用它来限制访问共享代码的进程数目。

```cpp
void print(pid_t);
sem_t *sem; /*定义Posix有名信号灯*/
int val; /*定义信号灯当前值*/

int main(int argc,char *argv[])
{
int n=0;

if(argc!=2)
{
printf(“please input a file name!\n”);
exit(1);
}
sem=sem_open(argv[1],O_CREAT,0644,2); /*打开一个信号灯, 初值设为2*/

while(n++循环创建5个子进程，使它们同步运行*/
{
if(fork()==0) 
{
       sem_wait(sem); /*申请信号灯*/
       print(getpid()); /*调用共享代码段*/
       sleep(1); 
       sem_post(sem); /*释放信号灯*/
       printf(“I’m finished,my pid is %d\n”,getpid());
       return 0; 
}
}
wait(); /*等待所有子进程结束*/
sem_close(sem);
sem_unlink(argv[1]);
exit(0);
}

void print(pid_t pid)
{
printf(“I get it,my pid is %d\n”,pid);
sem_getvalue(sem,&val);
printf(“Now the value have %d\n”,val);
}
```

----

## 基于内存的信号灯

前面已经介绍了Posix有名信号灯。这些信号灯由一个name参数标识，它通常指代文件系统中的某个文件。然而Posix也提供基于内存的信号灯，它们由应用程序分配信号灯的内存空间，然后由系统初始化它们的值。

```
名称:：
sem_init/sem_destroy
功能：
初始化/关闭信号等
头文件：
#include 
函数原形：
int sem_init(sem_t *sem,int shared,unsigned int value);
int sem_getvalue(sem_t *sem);
参数：
sem 指向信号灯的指针
shared   作用范围
value 信号灯初始值
返回值：
若成功则返回0，否则返回-1。
```

基于内存的信号灯是由sem\_init初始化的。sem参数指向必须由应用程序分配的sem\_t变量。如果shared为0，那么待初始化的信号灯是在同 一进程的各个线程共享的，否则该信号灯是在进程间共享的。当shared为零时，该信号灯必须存放在即将使用它的所有进程都能访问的某种类型的共享内存 中。跟sem\_open一样，value参数是该信号灯的初始值。

   使用完一个基于内存的信号灯后，我们调用sem\_destroy关闭它。除了sem\_open和sem\_close外，其它的poisx有名信号灯函数都可以用于基于内存的信号灯。

注意：posix基于内存的信号灯和posix有名信号灯有一些区别，我们必须注意到这些:

- sem_open不需要类型与shared的参数，有名信号灯总是可以在不同进程间共享的。
- sem_init不使用任何类似于O_CREAT标志的东西，也就是说，sem_init总是初始化信号灯的值。因此，对于一个给定的信号灯，我们必须小心保证只调用一次sem_init。
- sem_open返回一个指向某个sem_t变量的指针，该变量由函数本身分配并初始化。但sem_init的第一个参数是一个指向某个sem_t变量的指针，该变量由调用者分配，然后由sem_init函数初始化。
- posix有名信号灯是通过内核持续的，一个进程创建一个信号灯，另外的进程可以通过该信号灯的外部名（创建信号灯使用的文件名）来访问它。 posix基于内存的信号灯的持续性却是不定的，如果基于内存的信号灯是由单个进程内的各个线程共享的，那么该信号灯就是随进程持续的，当该进程终止时它 也会消失。如果某个基于内存的信号灯是在不同进程间同步的，该信号灯必须存放在共享内存区中，这要只要该共享内存区存在，该信号灯就存在。
- 基于内存的信号灯应用于线程很麻烦（待会你会知道为什么），而有名信号灯却很方便，基于内存的信号灯比较适合应用于一个进程的多个线程。

下面是posix基于内存的信号灯实现一个进程的各个线程间的互次。

```cpp
// –lpthread
void *thread_function(void *arg); /*线程入口函数*/
void print(void); /*共享资源函数*/

sem_t bin_sem; /*定义信号灯*/
int value; /*定义信号量的灯*/

int main()
{
int n=0;
pthread_t a_thread; 

if((sem_init(&bin_sem,0,2))!=0) /*初始化信号灯，初始值为2*/
{
perror(“sem_init”);
exit(1);
}
while(n++循环创建5个线程*/
{
if((pthread_create(&a_thread,NULL,thread_function,NULL))!=0) 
{
perror(“Thread creation failed”);
exit(1);
}
}
pthread_join(a_thread,NULL);/*等待子线程返回*/
}

void *thread_function(void *arg)
{
sem_wait(&bin_sem); /*等待信号灯*/
print();
sleep(1);
sem_post(&bin_sem); /*挂出信号灯*/
printf(“I finished,my pid is %d\n”,pthread_self());
pthread_exit(arg);
}

void print()
{
printf(“I get it,my tid is %d\n”,pthread_self());
sem_getvalue(&bin_sem,&value); /*获取信号灯的值*/
printf(“Now the value have %d\n”,value);
}
```

posix基于内存的信号灯和有名信号灯基本是一样的，上面的几点区别就可以了。 


下面的程序并不能得到我们想要的结果。

```cpp
void print(pid_t);
sem_t *sem; /*定义Posix有名信号灯*/
int val; /*定义信号灯当前值*/

int main(int argc,char *argv[])
{
int n=0;

sem=sem_open(argv[1],O_CREAT,0644,3); /*打开一个信号灯*/
sem_getvalue(sem,&val); /*查看信号灯的值*/
printf(“The value have %d\n”,val);

while(n++循环创建5个子进程，使它们同步运行*/
{
if(fork()==0) 
{
       sem_wait(sem); /*申请信号灯*/
       print(getpid()); /*调用共享代码段*/
       sleep(1); 
       sem_post(sem); /*释放信号灯*/
       printf(“I’m finished,my pid is %d\n”,getpid());
       return 0; 
}
wait(); /*等待所有子进程结束*/
return 0;
}

void print(pid_t pid)
{
printf(“I get it,my pid is %d\n”,pid);
sem_getvalue(sem,&val);
printf(“Now the value have %d\n”,val);
}
```

问题在于sem信号灯不在共享内存区中。fork出来的子进程通常不共享父进程的内存空间。子进程是在父进程内存空间的拷贝上启动的，它跟共享内存不是一回事。


<!-- README.md ends here -->
