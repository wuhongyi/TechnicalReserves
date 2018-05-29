// sem_sync.hpp --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 6月 21 13:52:04 2016 (+0800)
// Last-Updated: 二 6月 21 13:52:18 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

#ifndef _SEM_SYNC_H_
#define _SEM_SYNC_H_
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
  
char SEM_A_TASK_IS_FREE[]= "a_task_is_free";
char SEM_B_TASK_IS_FREE[]= "b_task_is_free";

#endif

// 
// sem_sync.hpp ends here
