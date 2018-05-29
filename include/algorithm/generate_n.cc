// generate_n.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 5月 24 16:22:36 2015 (+0800)
// Last-Updated: 日 5月 24 16:22:50 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// generate_n example
#include <iostream>     // std::cout
#include <algorithm>    // std::generate_n

int current = 0;
int UniqueNumber () { return ++current; }

int main () {
  int myarray[9];

  std::generate_n (myarray, 9, UniqueNumber);

  std::cout << "myarray contains:";
  for (int i=0; i<9; ++i)
    std::cout << ' ' << myarray[i];
  std::cout << '\n';

  return 0;
}

// 
// generate_n.cc ends here
