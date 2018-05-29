// fuwuduan.cpp --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 6月 21 15:20:40 2016 (+0800)
// Last-Updated: 二 6月 21 15:28:18 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 3
// URL: http://wuhongyi.cn 

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
      printf("usage:shm_open<pathname>\n");
      return -1;
    }

  shm_id=shm_open(argv[1],O_RDWR|O_CREAT,0644);/*第一步：创建共享内存区*/
  if (shm_id==-1)
    {
      printf( "open shared memory error.errno=%d,desc=%s.\n", errno, strerror(errno));
      return -1;
    }

  ftruncate(shm_id,100);/*第二步：调整共享内存区大小，shmid问shm_open的返回值*/
  sem=sem_open(argv[1],O_CREAT,0644,0);/*创建信号量*/
  if (sem==SEM_FAILED)
    {
      printf( "open semaphore error.errno=%d,desc=%s.\n", errno, strerror(errno));
      return -1;
    }

  ptr=(char*)mmap(NULL,100,PROT_READ|PROT_WRITE,MAP_SHARED,shm_id,0);/*第三步：连接共享内存区*/
  strcpy(ptr,"\0");

  sem_wait(sem);/*第四步：申请信号量*/
  printf("server : %s\n",ptr);/*输入共享内存区内容*/
  strcpy(ptr,"\0");/*清空共享内存区*/

  sem_unlink(argv[1]);/*第五步：删除信号量*/
  shm_unlink(argv[1]);/*第六步：删除共享内存区*/

  return 0;
}

// 
// fuwuduan.cpp ends here
