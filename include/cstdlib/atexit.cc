// atexit.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 6月 22 17:09:36 2015 (+0800)
// Last-Updated: 一 6月 22 17:10:17 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// extern "C" int atexit (void (*func)(void)) noexcept;
// extern "C++" int atexit (void (*func)(void)) noexcept;

// Set function to be executed on exit
// The function pointed by func is automatically called without arguments when the program terminates normally.

// If more than one atexit function has been specified by different calls to this function, they are all executed in reverse order as a stack (i.e. the last function specified is the first to be executed at exit).

// A single function can be registered to be executed at exit more than once.

// If atexit is called after exit, the call may or may not succeed depending on the particular system and library implementation (unspecified behavior).

// If a function registered with atexit throws an exception for which it does not provide a handler when called on termination, terminate is automatically called (C++).

// Particular library implementations may impose a limit on the number of functions call that can be registered with atexit, but this cannot be less than 32 function calls.

/* atexit example */
#include <stdio.h>      /* puts */
#include <stdlib.h>     /* atexit */

void fnExit1 (void)
{
  puts ("Exit function 1.");
}

void fnExit2 (void)
{
  puts ("Exit function 2.");
}

int main ()
{
  atexit (fnExit1);
  atexit (fnExit2);
  puts ("Main function.");
  return 0;
}

// 
// atexit.cc ends here
