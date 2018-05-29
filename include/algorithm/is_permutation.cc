// is_permutation.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 5月 24 16:27:21 2015 (+0800)
// Last-Updated: 日 5月 24 16:27:36 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

//C++11
// is_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::is_permutation
#include <array>        // std::array

int main () {
  std::array<int,5> foo = {1,2,3,4,5};
  std::array<int,5> bar = {3,1,4,5,2};

  if ( std::is_permutation (foo.begin(), foo.end(), bar.begin()) )
    std::cout << "foo and bar contain the same elements.\n";

  return 0;
}

// 
// is_permutation.cc ends here
