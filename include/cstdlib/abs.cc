// abs.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 6月 22 17:08:41 2015 (+0800)
// Last-Updated: 一 6月 22 17:09:10 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 



//           int abs (          int n);
//      long int abs (     long int n);
// long long int abs (long long int n);

// Absolute value
// Returns the absolute value of parameter n ( /n/ ).

// In C++, this function is also overloaded in header <cmath> for floating-point types (see cmath abs), in header <complex> for complex numbers (see complex abs), and in header <valarray> for valarrays (see valarray abs).

/* abs example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* abs */

int main ()
{
  int n,m;
  n=abs(23);
  m=abs(-11);
  printf ("n=%d\n",n);
  printf ("m=%d\n",m);
  return 0;
}

// 
// abs.cc ends here
