// isblank.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 6月 22 16:17:32 2015 (+0800)
// Last-Updated: 一 6月 22 16:18:05 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

//C++11

// int isblank ( int c );

// Check if character is blank
// Checks whether c is a blank character.

// A blank character is a space character used to separate words within a line of text.

// The standard "C" locale considers blank characters the tab character ('\t') and the space character (' ').

// Other locales may consider blank a different selection of characters, but they must all also be space characters by isspace.

// For a detailed chart on what the different ctype functions return for each character of the standard ASCII character set, see the reference for the <cctype> header.

// In C++, a locale-specific template version of this function (isblank) exists in header <locale>.

// Compatibility note: Standardized in C99 (C++11).

/* isblank example */
#include <stdio.h>
#include <ctype.h>
int main ()
{
  char c;
  int i=0;
  char str[]="Example sentence to test isblank\n";
  while (str[i])
  {
    c=str[i];
    if (isblank(c)) c='\n';
    putchar (c);
    i++;
  }
  return 0;
}

// 
// isblank.cc ends here
