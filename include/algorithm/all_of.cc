// all_of.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 5月 24 15:38:01 2015 (+0800)
// Last-Updated: 日 5月 24 15:38:25 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

//C++11
// all_of example
#include <iostream>     // std::cout
#include <algorithm>    // std::all_of
#include <array>        // std::array

int main () {
  std::array<int,8> foo = {3,5,7,11,13,17,19,23};

  if ( std::all_of(foo.begin(), foo.end(), [](int i){return i%2;}) )
    std::cout << "All the elements are odd numbers.\n";

  return 0;
}

// 
// all_of.cc ends here
