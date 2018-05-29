// a.cpp --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 6月 21 13:52:40 2016 (+0800)
// Last-Updated: 二 6月 21 13:56:33 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 3
// URL: http://wuhongyi.cn 

// -lpthread 
#include "sem_sync.hpp"
#include <stdlib.h>
#include <stdio.h>

int main()
{
  sem_t *sem_a_task_is_free;
  sem_t *sem_b_task_is_free;
  int val;

  sem_a_task_is_free = sem_open(SEM_A_TASK_IS_FREE, O_CREAT, 0644, 1);
  sem_b_task_is_free = sem_open(SEM_B_TASK_IS_FREE, O_CREAT, 0644, 0);
  if (sem_a_task_is_free == SEM_FAILED || sem_b_task_is_free == SEM_FAILED)
    {
      perror("unable to create semaphore");
      sem_unlink(SEM_A_TASK_IS_FREE);
      exit(-1);
    }

  //while (1 == 1)
  {
    printf("run a task......\n");
    getchar();

    sem_getvalue(sem_a_task_is_free, &val);
    printf("The sem is %d\n", val);
    sem_post(sem_a_task_is_free);
    sem_getvalue(sem_a_task_is_free, &val);
    printf("The sem after sem post is %d\n", val);
    printf("send->a_task_is_free\n");
        
    printf("\nwaite sem_b_task_is_free\n");
    //sem_wait(sem_b_task_is_free);
    printf("recv<-sem_b_task_is_free\n");
  }

  sem_close(sem_a_task_is_free);
  sem_unlink(SEM_A_TASK_IS_FREE);

  return 0;
}

// 
// a.cpp ends here
