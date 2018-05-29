// iscntrl.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 6月 22 16:31:40 2015 (+0800)
// Last-Updated: 一 6月 22 16:32:51 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 2
// URL: http://wuhongyi.cn 

// int iscntrl ( int c );

// Check if character is a control character
// Checks whether c is a control character.

// A control character is a character that does not occupy a printing position on a display (this is the opposite of a printable character, checked with isprint).

// For the standard ASCII character set (used by the "C" locale), control characters are those between ASCII codes 0x00 (NUL) and 0x1f (US), plus 0x7f (DEL).

// For a detailed chart on what the different ctype functions return for each character of the standard ANSII character set, see the reference for the <cctype> header.

// In C++, a locale-specific template version of this function (iscntrl) exists in header <locale>.


/* iscntrl example */
#include <stdio.h>
#include <ctype.h>
int main ()
{
  int i=0;
  char str[]="first line \n second line \n";
  while (!iscntrl(str[i]))
  {
    putchar (str[i]);
    i++;
  }
  return 0;
}


// 
// iscntrl.cc ends here
