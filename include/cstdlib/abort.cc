// abort.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 6月 22 17:07:00 2015 (+0800)
// Last-Updated: 一 6月 22 17:07:41 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// [[noreturn]] void abort() noexcept;

// Abort current process
// Aborts the current process, producing an abnormal program termination.

// The function raises the SIGABRT signal (as if raise(SIGABRT) was called). This, if uncaught, causes the program to terminate returning a platform-dependent unsuccessful termination error code to the host environment.

// The program is terminated without destroying any object and without calling any of the functions passed to atexit or at_quick_exit.

/* abort example */
#include <stdio.h>      /* fopen, fputs, fclose, stderr */
#include <stdlib.h>     /* abort, NULL */

int main ()
{
  FILE * pFile;
  pFile= fopen ("myfile.txt","r");
  if (pFile == NULL)
  {
    fputs ("error opening file\n",stderr);
    abort();
  }

  /* regular process here */

  fclose (pFile);
  return 0;
}

// 
// abort.cc ends here
