// open.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 7月  7 10:04:35 2015 (+0800)
// Last-Updated: 二 7月  7 13:27:28 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 4
// URL: http://wuhongyi.cn 

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#include <iostream>


// 文件的打开指的是从磁盘中找到一个文件，返回一个整形的打开文件顺序编号。打开的文件处于可读可写状态。文件的关闭指的是释放打开的文件，使文件处于不可读写的状态。
// 函数open的作用是打开一个文件，使文件处于可读写的状态。这个函数的使用方法如下所示。
// int open(char *pathname, int flags);
// int open(char *pathname,int flags, mode_t mode);
// 函数的参数列表中，pathname表示要打开文件的路径字符串。参数flags是系统定义的一些整形常数，表示文件的打开方式。Flags的可选值如下所示。
// O_RDONLY：以只读方式打开文件。
// O_WRONLY：以只写方式打开文件。
// O_RDWR：以可读写方式打开文件。
// 打开文件时，如果没有这个文件则会自动新建一个文件。在新建文件时需要设置新建文件权限。系统为参数mode定义了下面这些常数，可以直接使用这些常数来设置文件的权限。这些权限设置只有在建立新文件时才会有效。 
// S_IRWXU：00700权限，该文件所有者具有可读可写可执行的权限。
// S_IRUSR或S_IREAD：00400权限，该文件所有者具有可读取的权限。
// S_IWUSR或S_IWRITE：00200 权限，该文件所有者具有可写入的权限。
// S_IXUSR或S_IEXEC：00100 权限，该文件所有者具有可执行的权限。
// S_IRWXG：00070权限，该文件用户组具有可读可写及可执行的权限。
// 调用这个函数时，如果正确的打开了这个文件，则返回这个文件的打开编号。如果打开失败则返回0。使用这个函数之前需要在程序的最前面包含下面这些头文件。
// #include<sys/types.h>
// #include<sys/stat.h>
// #include<fcntl.h>

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

  int fd,fd1;
  fd=open(path.c_str(),O_WRONLY,0766);
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
   
  fd1=open(path.c_str(),O_WRONLY|O_CREAT,0766);
  if(fd1!=-1)
    {
      printf("opened file %s  .\n",path.c_str());	
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
// open.cc ends here
