// isprint.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 6月 22 16:37:41 2015 (+0800)
// Last-Updated: 一 6月 22 16:38:04 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// int isprint ( int c );

// Check if character is printable
// Checks whether c is a printable character.

// A printable character is a character that occupies a printing position on a display (this is the opposite of a control character, checked with iscntrl).

// For the standard ASCII character set (used by the "C" locale), printing characters are all with an ASCII code greater than 0x1f (US), except 0x7f (DEL).

// isgraph returns true for the same cases as isprint except for the space character (' '), which returns true when checked with isprint but false when checked with isgraph.

// For a detailed chart on what the different ctype functions return for each character of the standard ANSII character set, see the reference for the <cctype> header.

// In C++, a locale-specific template version of this function (isprint) exists in header <locale>.

/* isprint example */
#include <stdio.h>
#include <ctype.h>
int main ()
{
  int i=0;
  char str[]="first line \n second line \n";
  while (isprint(str[i]))
  {
    putchar (str[i]);
    i++;
  }
  return 0;
}

// 
// isprint.cc ends here
