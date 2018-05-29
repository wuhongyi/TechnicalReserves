// isalpha.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 6月 22 16:15:56 2015 (+0800)
// Last-Updated: 一 6月 22 16:16:48 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 2
// URL: http://wuhongyi.cn 

// int isalpha ( int c );

// Check if character is alphabetic
// Checks whether c is an alphabetic letter.

// Notice that what is considered a letter depends on the locale being used; In the default "C" locale, what constitutes a letter is only what returns true by either isupper or islower.

// Using other locales, an alphabetic character is a character for which isupper or islower would return true, or another character explicitly considered alphabetic by the locale (in this case, the character cannot be iscntrl, isdigit, ispunct or isspace).

// For a detailed chart on what the different ctype functions return for each character of the standard ANSII character set, see the reference for the <cctype> header.

// In C++, a locale-specific template version of this function (isalpha) exists in header <locale>.

/* isalpha example */
#include <stdio.h>
#include <ctype.h>
int main ()
{
  int i=0;
  char str[]="C++";
  while (str[i])
  {
    if (isalpha(str[i])) printf ("character %c is alphabetic\n",str[i]);
    else printf ("character %c is not alphabetic\n",str[i]);
    i++;
  }
  return 0;
}

// 
// isalpha.cc ends here
