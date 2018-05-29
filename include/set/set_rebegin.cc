// set_rebegin.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 4月 20 19:07:46 2015 (+0800)
// Last-Updated: 一 4月 20 19:07:51 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// set::rbegin/rend
#include <iostream>
#include <set>

int main ()
{
  int myints[] = {21,64,17,78,49};
  std::set<int> myset (myints,myints+5);

  std::set<int>::reverse_iterator rit;

  std::cout << "myset contains:";
  for (rit=myset.rbegin(); rit != myset.rend(); ++rit)
    std::cout << ' ' << *rit;

  std::cout << '\n';

  return 0;
}

// 
// set_rebegin.cc ends here
