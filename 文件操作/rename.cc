// rename.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 7月  7 18:29:08 2015 (+0800)
// Last-Updated: 二 7月  7 18:36:59 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 3
// URL: http://wuhongyi.cn 

#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#include <string.h>
#include <iostream>

// 在Linux系统中，移动文件有两种方式。一种方式是在同一个分区中移动文件。这种文件移动方式相当于把文件进行重命名。另一种方式是在不同分区之间移动文件。本小节只讲前一种文件移动方式。
// 在同一个分区中移动文件可以用rename函数。该函数的使用方式如下所示。
// int rename(char *oldpath, char *newpath);
// 本节讲述一个实例，使用rename函数移动一个文件。将/root/a.txt文件移到到/tmp目录中，文件名为b.txt。在使用这个函数时，需要注意对错误信息的处理。

int main(int argc, char *argv[])
{
  
  extern int errno;

  char buf[1024];  
  getcwd(buf, 1024);  
  printf("The current directory is :%s \n", buf); 
  std::string file="/a.txt";
  std::string path=buf;
  std::string path1=path;
  std::string newpath=path;
  path=path+file;
  path1=path1+"/a11.txt";
  newpath=newpath+"/b.txt";

  std::cout<<path<<std::endl;

  if(rename(path.c_str(),newpath.c_str())==0)
    {
      printf("the file %s was moved to %s .\n",path.c_str(),newpath.c_str());	
    }
  else
    {
      printf("can't move the file %s .\n",path.c_str());	
      printf("errno：%d\n",errno);
      printf("ERR  ：%s\n",strerror(errno));
    }
  
  if(rename(path1.c_str(),newpath.c_str())==0)
    {
      printf("the file %s was moved to %s .\n",path1.c_str(),newpath.c_str());	
    }
  else
    {
      printf("can't move the file %s .\n",path1.c_str());	
      printf("errno：%d\n",errno);
      printf("ERR  ：%s\n",strerror(errno));
    }

  return 0;
}


// 
// rename.cc ends here
