// close.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 7月  7 13:30:11 2015 (+0800)
// Last-Updated: 二 7月  7 13:33:15 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 2
// URL: http://wuhongyi.cn 

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include <string.h>
#include <iostream>

// 函数close的作用是关闭一个已经打开的文件。使用完文件后需要则可使用close函数关闭该文件，这个操作会让数据写回磁盘，并释放该文件所占用的资源。该函数的使用方法如下所示。
// int close(int fd);
// 参数fd是用open函数打开文件时返回的打开序号。如果成功关闭文件则返回0，发生错误则返回-1。在进程结束时，系统会自动关闭已打开的文件，但仍建议在程序中关闭文件，并检查返回值是否正确。在关闭文件时，可能返回EBADF错误，表示需要关闭的文件号不存在。

int main(int argc, char *argv[])
{
  
  extern int errno;

  char buf[1024];  
  getcwd(buf, 1024);  
  printf("The current directory is :%s \n", buf); 
  std::string file="/testopen.txt";
  std::string path=buf;
  path=path+file;
  std::cout<<path<<std::endl;

  int fd;
  fd=open(path.c_str(),O_RDONLY ,0766);
  if(fd!=-1)
    {
      printf("opened file %s  .\n",path.c_str());	
    }
  else
    {
      printf("cant't open file %s.\n",path.c_str());
      printf("errno：%d\n",errno);
      printf("ERR  ：%s\n",strerror(errno));
    }
   
  if(close(fd)==0)
    {
      printf("closed.\n");
    }
  else
    {
      printf("close file %s error.\n",path.c_str());
      printf("errno：%d\n",errno);
      printf("ERR  ：%s\n",strerror(errno));
    }  
   
  if(close(1156)==0)
    {
      printf("closed.\n");
    }
  else
    {
      printf("close file %s error.\n",path.c_str());
      printf("errno：%d\n",errno);
      printf("ERR  ：%s\n",strerror(errno));
    }


  return 0;
}



// 
// close.cc ends here
