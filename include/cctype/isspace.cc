// isspace.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 6月 22 16:40:20 2015 (+0800)
// Last-Updated: 一 6月 22 16:40:52 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// int isspace ( int c );

// Check if character is a white-space
// Checks whether c is a white-space character.

// For the "C" locale, white-space characters are any of:
// ' '	(0x20)	space (SPC)
// '\t'	(0x09)	horizontal tab (TAB)
// '\n'	(0x0a)	newline (LF)
// '\v'	(0x0b)	vertical tab (VT)
// '\f'	(0x0c)	feed (FF)
// '\r'	(0x0d)	carriage return (CR)

// Other locales may consider a different selection of characters as white-spaces, but never a character that returns true for isalnum.

// For a detailed chart on what the different ctype functions return for each character of the standard ASCII character set, see the reference for the <cctype> header.

// In C++, a locale-specific template version of this function (isspace) exists in header <locale>.

/* isspace example */
#include <stdio.h>
#include <ctype.h>
int main ()
{
  char c;
  int i=0;
  char str[]="Example sentence to test isspace\n";
  while (str[i])
  {
    c=str[i];
    if (isspace(c)) c='\n';
    putchar (c);
    i++;
  }
  return 0;
}

// 
// isspace.cc ends here
