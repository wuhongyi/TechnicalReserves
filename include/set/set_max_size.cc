// set_max_size.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 4月 20 19:05:16 2015 (+0800)
// Last-Updated: 一 4月 20 19:05:25 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// set::max_size
#include <iostream>
#include <set>

int main ()
{
  int i;
  std::set<int> myset;

  if (myset.max_size()>1000)
  {
    for (i=0; i<1000; i++) myset.insert(i);
    std::cout << "The set contains 1000 elements.\n";
  }
  else std::cout << "The set could not hold 1000 elements.\n";

  return 0;
}

// 
// set_max_size.cc ends here
