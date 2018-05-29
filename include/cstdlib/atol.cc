// atol.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 6月 22 17:14:34 2015 (+0800)
// Last-Updated: 一 6月 22 17:15:06 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// long int atol ( const char * str );

// Convert string to long integer
// Parses the C-string str interpreting its content as an integral number, which is returned as a value of type long int.

// The function first discards as many whitespace characters (as in isspace) as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many base-10 digits as possible, and interprets them as a numerical value.

// The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

// If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed and zero is returned.

/* atol example */
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atol */

int main ()
{
  long int li;
  char buffer[256];
  printf ("Enter a long number: ");
  fgets (buffer, 256, stdin);
  li = atol(buffer);
  printf ("The value entered is %ld. Its double is %ld.\n",li,li*2);
  return 0;
}

// 
// atol.cc ends here
