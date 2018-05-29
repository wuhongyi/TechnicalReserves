// mainCopy.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 7月  7 18:41:21 2015 (+0800)
// Last-Updated: 日 3月  6 00:01:10 2016 (+0800)
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

// 在C程序中，没有直接复制一个文件的函数。如果需要复制一个文件，可以分别打开原文件和目标文件。依次从原文件中读取一定长度的内容，然后写入到新文件中。下面的程序是使用这种方法进行文件复制的实例。

int main(int argc, char *argv[])
{
  
  extern int errno;

  char buf[1024];  
  getcwd(buf, 1024);  
  printf("The current directory is :%s \n", buf); 
  std::string file="/a.txt";
  std::string path=buf;
  std::string newpath=path;
  path=path+file;
  newpath=newpath+"/b.txt";

  int fd,fd2,size,i=1;
  char buffer[100];
  struct flock fl;
  fd=open(path.c_str(),O_RDONLY);
  fd2=open(newpath.c_str(),O_WRONLY|O_CREAT);
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
  for(;i!=0;)
    { 
   		
      i=read(fd,buffer,sizeof(buffer));
      if(i==-1)
	{
	  break; 
	}
      else
	{
	  write(fd2,buffer,sizeof(buffer));
	}
    }
  printf("file was copied.\n");
  close(fd);
  close(fd2);


  return 0;
}


// 
// mainCopy.cc ends here
