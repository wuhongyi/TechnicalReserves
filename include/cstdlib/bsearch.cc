// bsearch.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 6月 22 17:18:23 2015 (+0800)
// Last-Updated: 一 6月 22 17:19:50 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// void* bsearch (const void* key, const void* base,
//                size_t num, size_t size,
//                int (*compar)(const void*,const void*));

// Binary search in array
// Searches the given key in the array pointed by base (which is formed by num elements, each of size bytes), and returns a void* pointer to a matching element, if found.

// To perform the search, the function performs a series of calls to compar with key as first argument and elements of the array pointed by base as second argument.

// Because this function may be optimized to use a non-linear search algorithm (presumably a binary search), the elements that compare less than key using compar should precede those that compare equal, and these should precede those that compare greater. This requirement is fulfilled by any array ordered with the same criteria used by compar (as if sorted with qsort).

// Parameters
// key
//     Pointer to the object that serves as key for the search, type-casted to a void*.
// base
//     Pointer to the first object of the array where the search is performed, type-casted to a void*.
// num
//     Number of elements in the array pointed by base.
//     size_t is an unsigned integral type.
// size
//     Size in bytes of each element in the array.
//     size_t is an unsigned integral type.
// compar
//     Pointer to a function that compares two elements.
//     This function is called repeatedly by bsearch to compare key against individual elements in base. It shall follow the following prototype:
//     int compar (const void* pkey, const void* pelem);

//     Taking two pointers as arguments: the first is always key, and the second points to an element of the array (both type-casted to const void*). The function shall return (in a stable and transitive manner):
//     return value	meaning
//     <0	The element pointed by pkey goes before the element pointed by pelem
//     0	The element pointed by pkey is equivalent to the element pointed by pelem
//     >0	The element pointed by pkey goes after the element pointed by pelem

//     For types that can be compared using regular relational operators, a general compar function may look like:
//     int compareMyType (const void * a, const void * b)
//     {
//       if ( *(MyType*)a <  *(MyType*)b ) return -1;
//       if ( *(MyType*)a == *(MyType*)b ) return 0;
//       if ( *(MyType*)a >  *(MyType*)b ) return 1;
//     }

/* bsearch example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort, bsearch, NULL */

int compareints (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int values[] = { 50, 20, 60, 40, 10, 30 };

int main ()
{
  int * pItem;
  int key = 40;
  qsort (values, 6, sizeof (int), compareints);
  pItem = (int*) bsearch (&key, values, 6, sizeof (int), compareints);
  if (pItem!=NULL)
    printf ("%d is in the array.\n",*pItem);
  else
    printf ("%d is not in the array.\n",key);
  return 0;
}

// 
// bsearch.cc ends here
