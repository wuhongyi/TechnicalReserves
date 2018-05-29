// ispunct.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 6月 22 16:38:38 2015 (+0800)
// Last-Updated: 一 6月 22 16:39:14 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// int ispunct ( int c );

// Check if character is a punctuation character
// Checks whether c is a punctuation character.

// The standard "C" locale considers punctuation characters all graphic characters (as in isgraph) that are not alphanumeric (as in isalnum).

// Other locales may consider a different selection of characters as punctuation characters, but in any case they are isgraph but not isalnum.

// For a detailed chart on what the different ctype functions return for each character of the standard ANSII character set, see the reference for the <cctype> header.

// In C++, a locale-specific template version of this function (ispunct) exists in header <locale>.

/* ispunct example */
#include <stdio.h>
#include <ctype.h>
int main ()
{
  int i=0;
  int cx=0;
  char str[]="Hello, welcome!";
  while (str[i])
  {
    if (ispunct(str[i])) cx++;
    i++;
  }
  printf ("Sentence contains %d punctuation characters.\n", cx);
  return 0;
}

// 
// ispunct.cc ends here
