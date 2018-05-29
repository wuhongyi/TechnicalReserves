// minmax.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 7月 12 12:44:24 2015 (+0800)
// Last-Updated: 日 7月 12 12:48:07 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 2
// URL: http://wuhongyi.cn 

//C++11
// minmax example
#include <iostream>     // std::cout
#include <algorithm>    // std::minmax

int main () {
  auto result = std::minmax({1,2,3,4,5});

  std::cout << "minmax({1,2,3,4,5}): ";
  std::cout << result.first << ' ' << result.second << '\n';
  return 0;
}

// 
// minmax.cc ends here
