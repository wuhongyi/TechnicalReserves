// read.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 7月  7 13:50:50 2015 (+0800)
// Last-Updated: 二 7月  7 13:53:37 2015 (+0800)
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

// 函数read可以从一个打开的文件中读取字符串。这个函数的使用方法如下所示。
// ssize_t read(int fd,void *buf ,size_t count);
// 在参数列表中，fd表示已经打开文件的编号。buf是一个空指针，读取的内容会返回到这个指针指向的字符串。count表示需要读取字符的个数。返回值表示实例读取到的字符的个数。如果返回值为0，表示已经到达文件末尾或文件中没有内容供读取。在读文件时，文件的读写位置会随着读取到的字节移动。

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
  int size;
  char s[100];
  fd=open(path.c_str(),O_RDONLY);
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
   
  size=read(fd,s,sizeof(s));
  close(fd);
  printf("%s\n",s);
  printf("%d\n",size);
  close(fd);  

  return 0;
}


// 
// read.cc ends here
