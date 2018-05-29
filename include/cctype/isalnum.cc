// isalnum.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 6月 22 16:14:01 2015 (+0800)
// Last-Updated: 一 6月 22 16:15:45 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 2
// URL: http://wuhongyi.cn 

// int isalnum ( int c );

// Check if character is alphanumeric
// Checks whether c is either a decimal digit or an uppercase or lowercase letter.

// The result is true if either isalpha or isdigit would also return true.

// Notice that what is considered a letter may depend on the locale being used; In the default "C" locale, what constitutes a letter is what returns true by either isupper or islower.

// For a detailed chart on what the different ctype functions return for each character of the standard ANSII character set, see the reference for the <cctype> header.

// In C++, a locale-specific template version of this function (isalnum) exists in header <locale>.


/* isalnum example */
#include <stdio.h>
#include <ctype.h>
int main ()
{
  int i;
  char str[]="c3po...";
  i=0;
  while (isalnum(str[i])) i++;
  printf ("The first %d characters are alphanumeric.\n",i);
  return 0;
}

// 
// isalnum.cc ends here
