// fcntl.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 7月  7 16:56:47 2015 (+0800)
// Last-Updated: 二 7月  7 17:00:06 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include <string.h>
#include <iostream>

// 函数fcntl的作用是对一个文件进行锁定。与flock函数不同的是，fcntl可以设定对文件的某一部分进行锁定。该函数的使用方法如下所示。
// int fcntl(int fd , int cmd);
// int fcntl(int fd,int cmd,long arg);
// int fcntl(int fd,int cmd,struct flock *lock);
// 这个函数的参数列表有多种形式。在编译时，会自动与参数进行匹配。参数fd是open函数打开文件时返回的文件编号。cmd是系统定义的一些整形常量，用来设置文件的打开方式:
// F_DUPFD用来查找大于或等于参数arg的最小且仍未使用的文件描述词，并且复制参数fd的文件描述词。执行成功则返回新复制的文件描述词。新描述符与fd共享同一文件表项，但是新描述符有它自己的一套文件描述符标志，其中FD_CLOEXEC文件描述符标志被清除。请参考dup2()。
// F_GETFD取得close-on-exec旗标。若此旗标的FD_CLOEXEC位为0，代表在调用exec()相关函数时文件将不会关闭。
// F_SETFD 设置close-on-exec 旗标。该旗标以参数arg 的FD_CLOEXEC位决定。
// F_GETFL 取得文件描述词状态旗标，此旗标为open（）的参数flags。
// F_SETFL 设置文件描述词状态旗标，参数arg为新旗标，但只允许O_APPEND、O_NONBLOCK和O_ASYNC位的改变，其他位的改变将不受影响。
// F_GETLK 取得文件锁定的状态。
// F_SETLK 设置文件锁定的状态。此时flcok 结构的l_type 值必须是F_RDLCK、F_WRLCK或F_UNLCK。如果无法建立锁定，则返回-1，错误代码为EACCES 或EAGAIN。
// F_SETLKW F_SETLK 作用相同，但是无法建立锁定时，此调用会一直等到锁定动作成功为止。若在等待锁定的过程中被信号中断时，会立即返回-1，错误代码为EINTR。
// 参数lock指针
// 参数lock指针为flock 结构指针，定义如下
// struct flock
// {
// short int l_type;
// short int l_whence;
// off_t l_start;
// off_t l_len;
// pid_t l_pid;
// };
// l_type 有三种状态:
// F_RDLCK 建立一个供读取用的锁定
// F_WRLCK 建立一个供写入用的锁定
// F_UNLCK 删除之前建立的锁定
// l_whence 也有三种方式:
// SEEK_SET 以文件开头为锁定的起始位置。
// SEEK_CUR 以目前文件读写位置为锁定的起始位置
// SEEK_END 以文件结尾为锁定的起始位置。
// l_start 表示相对l_whence位置的偏移量，两者一起确定锁定区域的开始位置。
// l_len表示锁定区域的长度，若果为0表示从起点(由l_whence和 l_start决定的开始位置)开始直到最大可能偏移量为止。即不管在后面增加多少数据都在锁的范围内。
// 返回值 成功则返回0，若有错误则返回-1，错误原因存于errno.

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
  struct flock fl;
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
  fl.l_type=F_RDLCK;
  fl.l_whence=SEEK_SET;
  fl.l_start=2;
  fl.l_len=10;
  fl.l_pid=15;
  if(fcntl(fd,F_SETLKW,&fl)==0)
    {
      printf("some string of the file was locked.\n");	
    }
  else
    {
      printf("locked error.\n");
      printf("errno：%d\n",errno);
      printf("ERR  ：%s\n",strerror(errno));
    }
  close(fd);


  return 0;
}


// 
// fcntl.cc ends here
