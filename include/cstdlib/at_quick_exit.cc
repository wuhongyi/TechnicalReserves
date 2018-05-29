// at_quick_exit.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 6月 22 17:17:16 2015 (+0800)
// Last-Updated: 一 6月 22 17:17:56 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

//C++11

// extern "C" int at_quick_exit (void (*func)(void)) noexcept;
// extern "C++" int at_quick_exit (void (*func)(void)) noexcept;

// Set function to be executed on quick exit
// The function pointed by func is automatically called (without arguments) when quick_exit is called.

// If more than one at_quick_exit function has been specified by different calls to this function, they are all executed in reverse order.

// If a function registered with at_quick_exit throws an exception for which it does not provide a handler while called by quick_exit, terminate is automatically called (C++).

// Notice that the at_quick_exit stack of functions is separate from the atexit stack (and each is triggered by different circumstances), but the same function may be passed to both functions so that it is called in both cases.

// Particular library implementations may impose a limit on the number of functions that can be registered with at_quick_exit, but this cannot be less than 32 functions.

/* at_quick_exit example */
#include <stdio.h>      /* puts */
#include <stdlib.h>     /* at_quick_exit, quick_exit, EXIT_SUCCESS */

void fnQExit (void)
{
  puts ("Quick exit function.");
}

int main ()
{
  at_quick_exit (fnQExit);
  puts ("Main function: Beginning");
  quick_exit (EXIT_SUCCESS);
  puts ("Main function: End");  // never executed
  return 0;
}

// 
// at_quick_exit.cc ends here










