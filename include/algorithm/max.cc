// max.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 5月 24 16:58:31 2015 (+0800)
// Last-Updated: 日 5月 24 16:58:41 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// max example
#include <iostream>     // std::cout
#include <algorithm>    // std::max

int main () {
  std::cout << "max(1,2)==" << std::max(1,2) << '\n';
  std::cout << "max(2,1)==" << std::max(2,1) << '\n';
  std::cout << "max('a','z')==" << std::max('a','z') << '\n';
  std::cout << "max(3.14,2.73)==" << std::max(3.14,2.73) << '\n';
  return 0;
}

// 
// max.cc ends here
