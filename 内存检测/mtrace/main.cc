// main.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 五 7月 24 13:35:15 2015 (+0800)
// Last-Updated: 五 7月 24 13:54:14 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 6
// URL: http://wuhongyi.cn 

// export MALLOC_TRACE=mytrace.log
// g++ main.cc -o 123
// ./123
// mtrace 123 mytrace.log 


// g++ -g main.cc -o 123
// ./123
// mtrace 123 wutrace.log
// 如果你编译的时候没有使用-g的选项，那么Caller这个地方就不会出现代码的信息，而是一串二进制的地址信息。

#include <mcheck.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *hello;
  setenv("MALLOC_TRACE", "wutrace.log", 1);
  mtrace();
  hello = (char*) malloc(20);
  sprintf(hello,"nhello world!");
  return 1;
} 


// 
// main.cc ends here


