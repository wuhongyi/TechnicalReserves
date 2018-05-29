// tolower.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 6月 22 16:44:22 2015 (+0800)
// Last-Updated: 一 6月 22 16:44:46 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// int tolower ( int c );

// Convert uppercase letter to lowercase
// Converts c to its lowercase equivalent if c is an uppercase letter and has a lowercase equivalent. If no such conversion is possible, the value returned is c unchanged.

// Notice that what is considered a letter may depend on the locale being used; In the default "C" locale, an uppercase letter is any of: A B C D E F G H I J K L M N O P Q R S T U V W X Y Z, which translate respectively to: a b c d e f g h i j k l m n o p q r s t u v w x y z.

// In other locales, if an uppercase character has more than one correspondent lowercase character, this function always returns the same character for the same value of c.

// In C++, a locale-specific template version of this function (tolower) exists in header <locale>.

/* tolower example */
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
    putchar (tolower(c));
    i++;
  }
  return 0;
}

// 
// tolower.cc ends here
