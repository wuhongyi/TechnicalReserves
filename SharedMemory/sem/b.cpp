// b.cpp --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 6月 21 13:55:37 2016 (+0800)
// Last-Updated: 二 6月 21 13:58:08 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 4
// URL: http://wuhongyi.cn 

// -lpthread
#include "sem_sync.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main()
{
  int val;
  sem_t *sem_a_task_is_free;
  sem_t *sem_b_task_is_free;

  sem_a_task_is_free = sem_open(SEM_A_TASK_IS_FREE, O_CREAT, 0644, 0);
  sem_b_task_is_free = sem_open(SEM_B_TASK_IS_FREE, O_CREAT, 0644, 1);
  if (sem_a_task_is_free == SEM_FAILED || sem_b_task_is_free == SEM_FAILED)
    {
      perror("unable to create semaphore");
      sem_unlink(SEM_B_TASK_IS_FREE);
      exit(-1);
    }

  //while (1 == 1)
  {
    printf("\nrun b_task......\n");
    sem_getvalue(sem_a_task_is_free, &val);
    printf("The sem is %d\n", val);
    sleep(1);
    //sem_post(sem_b_task_is_free);
    printf("send->sem_b_task_is_free\n");
    printf("\nwaite a_task_is_free\n");
    sem_getvalue(sem_a_task_is_free, &val);
    printf("The sem 2 is %d\n", val);
    sem_wait(sem_a_task_is_free);
    sem_getvalue(sem_a_task_is_free, &val);
    printf("The sem 3 is %d\n", val);
    printf("recv<-a_task_is_free\n");
  }

  sem_close(sem_a_task_is_free);
  sem_close(sem_b_task_is_free);

  sem_unlink(SEM_B_TASK_IS_FREE);

  return 0;
}
// 
// b.cpp ends here
