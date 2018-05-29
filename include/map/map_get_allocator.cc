// map_get_allocator.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 4月 20 19:30:59 2015 (+0800)
// Last-Updated: 一 4月 20 19:31:11 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// map::get_allocator
#include <iostream>
#include <map>

int main ()
{
  int psize;
  std::map<char,int> mymap;
  std::pair<const char,int>* p;

  // allocate an array of 5 elements using mymap's allocator:
  p=mymap.get_allocator().allocate(5);

  // assign some values to array
  psize = sizeof(std::map<char,int>::value_type)*5;

  std::cout << "The allocated array has a size of " << psize << " bytes.\n";

  mymap.get_allocator().deallocate(p,5);

  return 0;
}

// 
// map_get_allocator.cc ends here
