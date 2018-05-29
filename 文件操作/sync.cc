// sync.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 7月  7 14:29:21 2015 (+0800)
// Last-Updated: 二 7月  7 14:30:08 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include <string.h>
#include <iostream>


// 所谓缓冲区，是Linux系统对文件的一种处理方式。在对文件进行写操作时，并没有立即把文件写入到磁盘，而是把文件写入到缓冲区中。如果需要把文件立即写入到磁盘，可以用sync函数。用这个函数强制写入缓冲区数据的好处是保证数据有同步。这个函数的使用方法如下所示。
// int sync(void)
// 这个函数会对当前程序打开的所有文件进行处理，将缓冲区中的内容写入到文件。函数没有参数，返回值为0。这个函数一般不会产生错误。要使用这个函数，需要在程序中包含下面的头文件。
// #include<unistd.h>

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

  int fd;
  char s[]="hello ,Linux.\nI've leart C program for two weeks.\n";

  fd=open(path.c_str(),O_WRONLY|O_CREAT);
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
  write(fd,s,sizeof(s));
  sync();
  printf("sync function done. \n");
  close(fd);

  return 0;
}

// 
// sync.cc ends here
