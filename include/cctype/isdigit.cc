// isdigit.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 6月 22 16:33:49 2015 (+0800)
// Last-Updated: 一 6月 22 16:34:17 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// int isdigit ( int c );

// Check if character is decimal digit
// Checks whether c is a decimal digit character.

// Decimal digits are any of: 0 1 2 3 4 5 6 7 8 9

// For a detailed chart on what the different ctype functions return for each character of the standard ASCII character set, see the reference for the <cctype> header.

// In C++, a locale-specific template version of this function (isdigit) exists in header <locale>.

/* isdigit example */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main ()
{
  char str[]="1776ad";
  int year;
  if (isdigit(str[0]))
  {
    year = atoi (str);
    printf ("The year that followed %d was %d.\n",year,year+1);
  }
  return 0;
}

// 
// isdigit.cc ends here
