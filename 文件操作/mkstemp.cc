// mkstemp.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 7月  7 09:15:35 2015 (+0800)
// Last-Updated: 二 7月  7 13:27:58 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 6
// URL: http://wuhongyi.cn 

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>//strerror

// 所谓临时文件，指的是程序运行时为了存储中间数据建立的文件。计算机重启时，这些文件会自动删除。如果在程序运行时，需要把文件短时间的写到磁盘上，可以使用mkstemp函数创建一个临时文件。mkstemp函数的使用方法如下所示。
// int mkstemp(char *template);
// 参数template表示需要建立临时文件的文件名字符串。文件名字符串中最后六个字符必须是XXXXXX。mkstemp函数会以可读写模式和0600权限来打开该文件。如果文件不存在则会建立这个文件。返回值是打开文件的编号，如果文件建立不成功，则返回-1。

int main(int argc, char *argv[])
{
  extern int errno;
  char path[]="wutemp-XXXXXX";
   
  if(mkstemp(path)!=-1)
    {
      printf("created temp file %s.\n",path);	
    }
  else
    {
      printf("cant't create temp file %s.\n",path);
      printf("errno：%d\n",errno);
      printf("ERR  ：%s\n",strerror(errno));
    }  

  return 0;
}


// 
// mkstemp.cc ends here
