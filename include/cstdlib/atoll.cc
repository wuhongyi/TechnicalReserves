// atoll.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 6月 22 17:15:46 2015 (+0800)
// Last-Updated: 一 6月 22 17:16:17 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

//C++11

// long long int atoll ( const char * str );

// Convert string to long long integer
// Parses the C-string str interpreting its content as an integral number, which is returned as a value of type long long int.

// This function operates like atol to interpret the string, but produces numbers of type long long int (see atol for details on the interpretation process).

/* atoll example */
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoll */

int main ()
{
  long long int lli;
  char buffer[256];
  printf ("Enter a long number: ");
  fgets (buffer, 256, stdin);
  lli = atoll(buffer);
  printf ("The value entered is %lld. Its double is %lld.\n",lli,lli*2);
  return 0;
}

// 
// atoll.cc ends here
