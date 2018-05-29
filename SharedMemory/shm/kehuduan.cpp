// kuhuduan.cpp --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 6月 21 15:22:03 2016 (+0800)
// Last-Updated: 二 6月 21 15:27:28 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 3
// URL: http://wuhongyi.cn 

// g++ kehuduan.cpp -lpthread  -lrt -o 123
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>
#include <errno.h>

int main(int argc,char **argv)
{
  int shm_id;
  char *ptr;
  sem_t *sem;

  if (argc!=2)
    {
      printf("usage:shm_open <pathname>\n");
      return -1;
    }

  shm_id=shm_open(argv[1],O_RDWR,0);/*第一步：打开共享内存区*/
  if (shm_id==-1)
    {
      printf( "open shared memory error.errno=%d,desc=%s.\n", errno, strerror(errno));
      return -1;
    }
  else
    {
      printf( "open shared memory ok.\n");
    }

  sem=sem_open(argv[1],0);/*打开信号量*/
  if (sem==SEM_FAILED)
    {
      printf( "open semaphore error.errno=%d,desc=%s.\n", errno, strerror(errno));
      return -1;
    }
  else
    {
      printf( "open semaphore ok.\n");
    }

  ptr=(char*)mmap(NULL,100,PROT_READ|PROT_WRITE,MAP_SHARED,shm_id,0);/*连接共享内存区*/

  fgets(ptr,10,stdin);/*从键盘读入数据到共享内存区*/
  printf("user : %s",ptr);

  sem_post(sem);/*释放信号量*/

  return 0;
}

// 
// kuhuduan.cpp ends here
