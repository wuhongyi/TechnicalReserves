// lessk.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 7月  7 14:10:28 2015 (+0800)
// Last-Updated: 二 7月  7 14:18:23 2015 (+0800)
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

// 每一个已打开的文件都有一个读写位置。当打开文件时通常读写位置是指向文件开头，若是以附加的方式打开文件，则读写位置会指向文件末尾。read或write函数读写文件时，读写位置会随相应移动。可以用lseek函数在文件内容中的位置上面移动，这样就可以在文件中不同的位置进行上读写。这个函数的使用方法如下所示。
// off_t lseek(int fd,off_t offset ,int whence);
// 在参数列表中，fd表示用open函数打开的文件返回编号。参数offset是根据参数whence来移动读写位置的位移数。whence为系统定义的常量，可能有下面这些可能赋值:
// SEEK_SET 参数offset即为新的读写位置。
// SEEK_CUR 以目前的读写位置往后增加offset个位移量。 
// SEEK_END 将读写位置指向文件末尾后再增加offset个位移量。

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
  char s[100]="";

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
   
  size=read(fd,s,3);    
  printf("%d  :",size);
  printf("%s\n",s);
  
  size=read(fd,s,3); 
  printf("%d  :",size);
  printf("%s\n",s);
   
  lseek(fd,8,SEEK_SET);
  size=read(fd,s,3);
  printf("%d  :",size);
  printf("%s\n",s);

  lseek(fd,0,SEEK_SET);
  size=read(fd,s,3);
  printf("%d  :",size);
  printf("%s\n",s);
         
  close(fd); 

  return 0;
}


// 
// lessk.cc ends here
