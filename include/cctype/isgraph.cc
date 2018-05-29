// isgraph.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 6月 22 16:35:01 2015 (+0800)
// Last-Updated: 一 6月 22 16:35:24 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// int isgraph ( int c );

// Check if character has graphical representation
// Checks whether c is a character with graphical representation.

// The characters with graphical representation are all those characters than can be printed (as determined by isprint) except the space character (' ').

// For a detailed chart on what the different ctype functions return for each character of the standard ASCII character set, see the reference for the <cctype> header.

// In C++, a locale-specific template version of this function (isgraph) exists in header <locale>.

/* isgraph example */
#include <stdio.h>
#include <ctype.h>
int main ()
{
  FILE * pFile;
  int c;
  pFile=fopen ("myfile.txt","r");
  if (pFile)
  {
    do {
      c = fgetc (pFile);
      if (isgraph(c)) putchar (c);
    } while (c != EOF);
    fclose (pFile);
  }
}

// 
// isgraph.cc ends here
