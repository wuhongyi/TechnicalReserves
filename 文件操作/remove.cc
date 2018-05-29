// remove.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 7月  7 09:07:37 2015 (+0800)
// Last-Updated: 二 7月  7 09:14:27 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 2
// URL: http://wuhongyi.cn 

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <errno.h>//错误定义
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

// 函数remove的作用是从删除一个文件。这个函数的使用方法如下所示。
// int remove(char *pathname);
// 参数remove是一个字符串，表示需要删除的目录。文件删除成功则返回0，否则返回-1。要使用这个函数需要在程序的最前面包含下面的头文件。
// #include <stdio.h>
// 函数remove在删除文件时，可以发生权限不足或目录不存在的问题。可能产生的错误，需要在程序中设置errno来捕获错误信息。


int main(int argc, char *argv[])
{
  extern int errno;

  char buf[1024];  
  getcwd(buf, 1024);  
  printf("The current directory is :%s \n", buf); 
  std::string file="/test.txt";
  std::string path=buf;
  path=path+file;
  std::cout<<path<<std::endl;

  if(remove(path.c_str())==0)
    {
      printf("Deleted file %s.\n",path.c_str());	
    }
  else
    {
      printf("cant't delete the file %s.\n",path.c_str());
      printf("errno：%d\n",errno);
      printf("ERR  ：%s\n",strerror(errno));
    }

  return 0;
}

// 
// remove.cc ends here
