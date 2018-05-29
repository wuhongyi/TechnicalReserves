// flock.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 7月  7 14:26:45 2015 (+0800)
// Last-Updated: 二 7月  7 16:53:46 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 6
// URL: http://wuhongyi.cn 

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<sys/file.h>//flock
#include <fcntl.h>
#include <errno.h>

#include <string.h>
#include <iostream>

// 在访问一个文件时，可以用flock函数对文件进行锁定。防止其他用户同时访问这个文件发生数据不一致的情况。这个函数的使用方法如下所示。
// int flock(int fd,int operation);
// 在参数列表中，fd是open函数打开文件时返回的打开序号。operation是系统定义的一些整形常量，可能的取值和含义如下所示。
// LOCK_SH：建立共享锁定，其他的程序可以同时访问这一个文件。多个程序可同时对同一个文件作共享锁定。
// LOCK_EX：建立互斥锁定，其他用户不能同时访问这一个文件。一个文件同时只有一个互斥锁定。单一文件不能同时建立共享锁定与互斥锁定。
// LOCK_UN 解除文件锁定状态。 
// LOCK_NB 无法建立锁定时，此操作可不被阻断，马上返回进程。通常与LOCK_SH或LOCK_EX做OR（|）组合。
// 当文件锁定成功时会返回0，否则返回-1 。

int main(int argc, char *argv[])
{
  
  extern int errno;

  char buf[1024];  
  getcwd(buf, 1024);  
  printf("The current directory is :%s \n", buf); 
  std::string file="/testwrite.txt";
  std::string path=buf;
  path=path+file;
  std::cout<<path<<std::endl;

  int fd,i;

  fd=open(path.c_str(),O_WRONLY|O_CREAT);
  if(fd!=-1)
    {
      printf("opened file %s  .\n",path.c_str());
      printf("please input a number to lock the file.\n");
      scanf("%d",&i);
      if(flock(fd,LOCK_EX)==0)
	{
	  printf("the file was locked.\n");	
	}
      else
	{
	  printf("the file was not locked.\n");		
	}
      printf("please input a number to unlock the file.\n");
      scanf("%d",&i);
      if(flock(fd,LOCK_UN)==0)
	{
	  printf("the file was unlocked.\n");	
	}
      else
	{
	  printf("the file was not unlocked.\n");		
	}
      close(fd);	
    }
  else
    {
      printf("cant't open file %s.\n",path.c_str());
      printf("errno：%d\n",errno);
      printf("ERR  ：%s\n",strerror(errno));
    }

  return 0;
}


// 
// flock.cc ends here
