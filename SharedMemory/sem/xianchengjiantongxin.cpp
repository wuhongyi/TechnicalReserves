// xianchengjiantongxin.cpp --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 6月 21 15:01:28 2016 (+0800)
// Last-Updated: 二 6月 21 15:03:33 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 2
// URL: http://wuhongyi.cn 

// g++ xianchengjiantongxin.cpp -lpthread -o 123

/***********
编程实现 进程的同步与互斥
 
题目:有父亲/儿子/女儿三人和一个盘子.
当盘子为空的时候,父亲 随机往盘子里放香蕉或苹果;
儿子和女儿马上取该水果,但儿子只拿苹果,女儿只拿香蕉
父亲共放20次.
编程模拟实现!
*************/
#include<stdio.h>
#include <errno.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>
//#include <process.h>//for windows
 
#define OPEN_FLAG O_RDWR|O_CREAT
#define OPEN_MODE 00777
#define INIT_V    0
 
static sem_t *sem_apple = NULL;
static sem_t *sem_banana = NULL;
 
 
int fatherdo(){
  int i=20;
  while(i-->0){
    printf("[%u]father put %s \n",i,i%2==0 ?"Apple":"Banana");
    if(i%2==0){
      sem_post(sem_apple);
    }else{
      sem_post(sem_banana);
    }
    sleep(1);
  }
  //删掉在系统创建的信号量
  sem_unlink("sem_apple");
  sem_unlink("sem_banana");
  //彻底销毁打开的信号量
  sem_close(sem_apple);
  sem_close(sem_banana);
  return 0;
}
int sondo(){
  sleep(2);
  int i=10;
  while(i-->0){
    //P操作
    sem_wait(sem_apple);
    printf("[%u]Son:I get an apple,father!\n\n",i);
  }
  return 0;
}
int daughterdo(){
  sleep(2);
  int i=10;
  while(i-->0){
    //P操作
    sem_wait(sem_banana);
    printf("[%u]Daughter:I get an bnana,father!\n\n",i);
  }
  return 0;
}
int main(){
  printf("Program begin:\n\n");
 
  //创建2个命名信号量
  sem_apple  = sem_open("sem_apple", OPEN_FLAG, OPEN_MODE, INIT_V); 
  sem_banana = sem_open("sem_banana", OPEN_FLAG, OPEN_MODE, INIT_V); 
  pid_t pid=-1;
  pid=fork();
  if(-1==pid){
    perror("Failed fork()!");return 1;
  }else if(pid==0){
    //子进程 儿子
    sondo();
  }else if(pid>0){
    pid=fork();
    if(-1==pid){
      perror("Failed fork()!");return 1;
    }else if(pid==0){
      //子进程女儿
      daughterdo();
    }else if(pid>0){
      //主进程
      fatherdo();
      printf("Program End...\n\n");
    }
  }
  printf("[%d <= %d]Three Process are end!\n",getpid(),getppid());
  return 0;
}

// 
// xianchengjiantongxin.cpp ends here
