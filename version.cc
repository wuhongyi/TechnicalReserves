// version.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 六 6月  4 20:04:38 2016 (+0800)
// Last-Updated: 六 6月  4 20:55:01 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 9
// URL: http://wuhongyi.cn 

// 经测试，gcc4.4.7 gcc4.9.2默认是c90标准。

// gcc -posix -E -dM - </dev/null 

// 4.4.7
// #define __VERSION__ "4.4.7 20120313 (Red Hat 4.4.7-11)"

// 4.9.2
// #define __VERSION__ "4.9.2"
// #define __STDC_ISO_10646__ 201103L

// 若没有使用-std参数来指定GCC的C标准, 则使用默认的GNUC90标准, GNUC90标准在C90标准的基础上进行了扩展.
// 熟知的C标准大概有三种: c90( or c89), c99, c11. 分别于1990年, 1999年, 2011年发布.
// 在编译的时候指定c90标准: -ansi, -std=c90 or -std=iso9899:1990;
// 指定C99标准: -std=c99 or -std=iso9899:1999
// 指定C11标准: -std=c11 or -std=iso9899:2011
// 原来的ANSI C标准(X3.159-1989)在1989年获得批准, 并在1990年发布. 之后(1990年)被批准为ISO标准(ISO/IEC 9899:1990). C89和C90在技术上没有区别.
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  printf("%d\n",__GNUC__);
  printf("%d\n",__GNUC_MINOR__);
  printf("%d\n",__GNUC_PATCHLEVEL__);

  
  return 0;
}

// 
// version.cc ends here
