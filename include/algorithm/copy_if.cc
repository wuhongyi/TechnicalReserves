// copy_if.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 5月 24 16:09:03 2015 (+0800)
// Last-Updated: 日 5月 24 16:09:22 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

//C++11
// copy_if example
#include <iostream>     // std::cout
#include <algorithm>    // std::copy_if, std::distance
#include <vector>       // std::vector

int main () {
  std::vector<int> foo = {25,15,5,-5,-15};
  std::vector<int> bar (foo.size());

  // copy only positive numbers:
  auto it = std::copy_if (foo.begin(), foo.end(), bar.begin(), [](int i){return !(i<0);} );
  bar.resize(std::distance(bar.begin(),it));  // shrink container to new size

  std::cout << "bar contains:";
  for (int& x: bar) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}

// 
// copy_if.cc ends here
