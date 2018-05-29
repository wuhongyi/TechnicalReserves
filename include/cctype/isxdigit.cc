// isxdigit.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 6月 22 16:43:19 2015 (+0800)
// Last-Updated: 一 6月 22 16:43:44 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// int isxdigit ( int c );

// Check if character is hexadecimal digit
// Checks whether c is a hexdecimal digit character.

// Hexadecimal digits are any of: 0 1 2 3 4 5 6 7 8 9 a b c d e f A B C D E F

// For a detailed chart on what the different ctype functions return for each character of the standard ANSII character set, see the reference for the <cctype> header.

// In C++, a locale-specific template version of this function (isxdigit) exists in header <locale>.

/* isxdigit example */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main ()
{
  char str[]="ffff";
  long int number;
  if (isxdigit(str[0]))
  {
    number = strtol (str,NULL,16);
    printf ("The hexadecimal number %lx is %ld.\n",number,number);
  }
  return 0;
}

// 
// isxdigit.cc ends here
