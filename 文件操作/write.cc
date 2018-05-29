// write.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 7月  7 13:35:33 2015 (+0800)
// Last-Updated: 二 7月  7 13:49:47 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 5
// URL: http://wuhongyi.cn 

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include <string.h>
#include <iostream>

// 文件读写指的是从文件中读写信息或将信息写入到文件中。文件读取是使用read函数来实现的。文件保存是通过write函数来实例的。在进行文件保存的操作时，只是在文件的缓冲区中操作，可能没有立即写入的到文件中。需要使用sync或fsynx函数相缓冲区中的数据写入到文件中。

// 函数write可以把一个字符串写入到一个已经打开的文件中。这个函数的使用方法如下所示。
// ssize_t write (int fd,void * buf,size_t count);
// 在参数列表中，fd是已经打开文件的文件号。buf是需要写入的字符串。count是一个整形数，表示需要写入的字符个数。size_t是一个相当于整形的数据类型，表示需要写入的字节的数目。将字符串写入文件以后，文件读的写位置也会随之移动。
// 如果写入成功，write函数会返回实际写入的字节数。发生错误发生时则返回-1，可以用errno来捕获发生的错误。可能发生的错误如下所示。

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
   fd=open(path.c_str(),O_RDWR|O_CREAT,00700);
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
   close(fd);  
   printf("Done");

  return 0;
}


// 
// write.cc ends here
