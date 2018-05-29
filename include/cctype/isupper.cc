// isupper.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 6月 22 16:41:52 2015 (+0800)
// Last-Updated: 一 6月 22 16:42:16 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// int isupper ( int c );

// Check if character is uppercase letter
// Checks if parameter c is an uppercase alphabetic letter.

// Notice that what is considered a letter may depend on the locale being used; In the default "C" locale, an uppercase letter is any of: A B C D E F G H I J K L M N O P Q R S T U V W X Y Z.

// Other locales may consider a different selection of characters as uppercase characters, but never characters that returns true for iscntrl, isdigit, ispunct or isspace.

// For a detailed chart on what the different ctype functions return for each character of the standard ANSII character set, see the reference for the <cctype> header.

// In C++, a locale-specific template version of this function (isupper) exists in header <locale>.

/* isupper example */
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
    if (isupper(c)) c=tolower(c);
    putchar (c);
    i++;
  }
  return 0;
}

// 
// isupper.cc ends here
