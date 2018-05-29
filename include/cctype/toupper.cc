// toupper.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 6月 22 16:45:09 2015 (+0800)
// Last-Updated: 一 6月 22 16:45:32 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// int toupper ( int c );

// Convert lowercase letter to uppercase
// Converts c to its uppercase equivalent if c is a lowercase letter and has an uppercase equivalent. If no such conversion is possible, the value returned is c unchanged.

// Notice that what is considered a letter may depend on the locale being used; In the default "C" locale, a lowercase letter is any of: a b c d e f g h i j k l m n o p q r s t u v w x y z, which translate respectively to: A B C D E F G H I J K L M N O P Q R S T U V W X Y Z.

// In other locales, if a lowercase character has more than one correspondent uppercase character, this function always returns the same character for the same value of c.

// In C++, a locale-specific template version of this function (toupper) exists in header <locale>.

/* toupper example */
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
    putchar (toupper(c));
    i++;
  }
  return 0;
}

// 
// toupper.cc ends here
