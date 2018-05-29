// islower.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 6月 22 16:36:40 2015 (+0800)
// Last-Updated: 一 6月 22 16:37:14 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// int islower ( int c );

// Check if character is lowercase letter
// Checks whether c is a lowercase letter.

// Notice that what is considered a letter may depend on the locale being used; In the default "C" locale, a lowercase letter is any of: a b c d e f g h i j k l m n o p q r s t u v w x y z.

// Other locales may consider a different selection of characters as lowercase characters, but never characters that returns true for iscntrl, isdigit, ispunct or isspace.

// For a detailed chart on what the different ctype functions return for each character of the standard ANSII character set, see the reference for the <cctype> header.

// In C++, a locale-specific template version of this function (islower) exists in header <locale>.

/* islower example */
#include <stdio.h>
#include <ctype.h>
int main ()
{
  int i=0;
  char str[]="Test String.\n";
  char c;
  while (str[i])
  {
    c=str[i];
    if (islower(c)) c=toupper(c);
    putchar (c);
    i++;
  }
  return 0;
}

// 
// islower.cc ends here
