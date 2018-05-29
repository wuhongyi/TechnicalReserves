// any_of.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 5月 24 15:42:18 2015 (+0800)
// Last-Updated: 日 5月 24 15:42:37 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

//C++11
// any_of example
#include <iostream>     // std::cout
#include <algorithm>    // std::any_of
#include <array>        // std::array

int main () {
  std::array<int,7> foo = {0,1,-1,3,-3,5,-5};

  if ( std::any_of(foo.begin(), foo.end(), [](int i){return i<0;}) )
    std::cout << "There are negative elements in the range.\n";

  return 0;
}

// 
// any_of.cc ends here
