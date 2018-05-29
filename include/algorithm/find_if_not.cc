// find_if_not.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 5月 24 16:20:08 2015 (+0800)
// Last-Updated: 日 5月 24 16:20:25 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

//C++11
// find_if_not example
#include <iostream>     // std::cout
#include <algorithm>    // std::find_if_not
#include <array>        // std::array

int main () {
  std::array<int,5> foo = {1,2,3,4,5};

  std::array<int,5>::iterator it =
    std::find_if_not (foo.begin(), foo.end(), [](int i){return i%2;} );
  std::cout << "The first even value is " << *it << '\n';

  return 0;
}

// 
// find_if_not.cc ends here
