// fsync.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 7月  7 14:21:22 2015 (+0800)
// Last-Updated: 二 7月  7 14:30:58 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 3
// URL: http://wuhongyi.cn 

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include <string.h>
#include <iostream>

// 函数fsync的作用是将缓冲区的数据写入到磁盘。与sync函数不同的是，这个函数可以指定打开文件的编号，执行以后会返回一个值。这个函数的使用方法如下所示。
// int fsync(int fd);
// 参数fd是open函数打开文件时返回的编号。函数如果执行成功，则返回0，否则返回-1。在使用这个函数时，需要在文件前面包含下面的头文件。
// #include<unistd.h>
// 函数可能发生下面这些错误，可以用errno捕获错误。
// EBADF：参数fd不是一个正确的文件打开编号或者文件不能写入。
// EIO：发生了I/O错误。前面的章节已经讲述过I／O错误。
// EROFS或EINVAL：fd是一个特殊的文件，不能够写入内容。

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
  if(fsync(fd)==0)
    {
      printf("fsync function done.\n");
    }
  else
    {
      printf("fsync function failed. \n");
    }
  close(fd);

  return 0;
}


// 
// fsync.cc ends here
