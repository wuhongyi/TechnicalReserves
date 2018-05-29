// creat.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 7月  7 08:58:47 2015 (+0800)
// Last-Updated: 二 7月  7 09:06:51 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 4
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

// 函数creat的作用是在目录中建立一个空文件，该函数的使用方法如下所示。
// int creat(char * pathname, mode_t mode);
// 函数的参数pathname表示需要建立文件的文件名和目录名。mode表示这个文件的权限。文件创建成功时返回创建文件的编号，否则整返回-1。
// 使用这个函数时，需要在程序的前面包含下面三个头文件。
// #include<sys/types.h>
// #include<sys/stat.h>
// #include<fcntl.h>

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

  if(creat(path.c_str(),0766)==-1)//与创建目录不同的是当再次运行这个程序时也能创建同名的文件。这时新创建的文件会覆盖以前的文件。
    {
      printf("cant't create the file %s.\n",path.c_str());
      printf("errno：%d\n",errno);
      printf("ERR  ：%s\n",strerror(errno));
    }
  else
    {   	  
      printf("created file %s.\n",path.c_str());	
    }

  return 0;
}



// 
// creat.cc ends here
