// main1.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 五 7月 24 15:30:35 2015 (+0800)
// Last-Updated: 三 8月 10 13:42:31 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 3
// URL: http://wuhongyi.cn 

// g++ -g main1.cc -o 123
// valgrind --tool=memcheck ./123

// valgrind --tool=memcheck --leak-check=yes --show-reachable=yes ./wu

//使用未初始化的内存
#include <stdio.h>
#include <stdlib.h> 

int main(void)
{
  char *p; 

  char c = *p; 

  printf("\n [%c]\n",c); 

  return 0;
}

// 
// main1.cc ends here
