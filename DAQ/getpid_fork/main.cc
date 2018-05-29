// main.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 三 5月 18 19:18:59 2016 (+0800)
// Last-Updated: 三 5月 18 19:22:18 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 2
// URL: http://wuhongyi.cn 

// getpid函数与fork函数都是与进程有关的函数。
// getpid函数原型为： pid_t getpid(void);
// 函数返回值为当前进程的PID。

// fork函数原型为： pid_t fork(void);
// 函数返回值有三种情况：
// 在子进程中返回0
// 在父进程中返回子进程ID，一般大于0。
// 出错时返回-1

// 意思很明确，尽管如此，却还是有几个地方容易让人误解。

// 第一：子进程与父进程共享哪些数据？哪些程序？
// 这里有一个很简单的例子，比如在fork之前的printf语句，会不会被子进程打印？答案是不会，因为该语句已被执行。而在fork之前的数据，却会复制到子进程中。

// 第二：子进程难道与父进程完全一样吗？
// 　在没有执行exec之前，确实是一样的，只不过fork在父子进程中的返回值是不一样的。可以通过这个特性使用if语句改变程序执行顺序。

// 第三：子进程的父进程消失以后，子进程归谁管？
// 由一个进程号为1的家伙代管，据说这家伙叫init进程，非常博爱，是所有孤儿进程的父进程，所谓孤儿进程，就是找不到产生自己的父进程的子进程。有些乱，但真相就是这样的。

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  pid_t tmp5;
  pid_t tmp;

  tmp5=getpid();
  printf("parent pid %d\n",tmp5);   /* 返回当前进程的进程ID */

  pid_t tmp4=getppid();
  printf("%d's parent pid is %d\n",tmp,tmp4); /* 返回调用当前进程的进程ID */

  tmp=fork();

  if(tmp < 0)
    {
      printf("error happans in fork\n");
      exit(1);
    }
  else
    {
      if(0== tmp)
	{ /* 子进程 fork 返回值为0 */

	  printf("\n\n");
	  printf("tmp == %d\n, is child process\n",tmp);

	  pid_t tmp1=getpid();
	  printf("child id is: %d\n",tmp1);

	  pid_t tmp2=getppid();
	  printf("%d's parent id is: %d\n",tmp1,tmp2);   /*  getppid的返回值tmp2可能为1，或者tmp3,取决于进程调度 */
	}
      else
	{  /* 父进程fork 返回值为子进程id */
	  printf("\n\n");
	  printf("tmp == %d\n, tmp is child pid\n",tmp);
	  pid_t tmp3=getpid();
	  printf("parent pid  is %d\n",tmp3);   /* 获取当前进程id，应该与程序最早打印的进程id 值相同  */
	  sleep(10);          /* 假设没有sleep(10)这一句，父进程立即执行完毕后消失，而子进程可能后于它消失，成为孤儿进程 */
	}
    }
  return 0;
}

// 
// main.cc ends here
