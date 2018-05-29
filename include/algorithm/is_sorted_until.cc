// is_sorted_until.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 5月 24 16:28:57 2015 (+0800)
// Last-Updated: 日 5月 24 16:29:10 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

//C++11
// is_sorted_until example
#include <iostream>     // std::cout
#include <algorithm>    // std::is_sorted_until, std::prev_permutation
#include <array>        // std::array

int main () {
  std::array<int,4> foo {2,4,1,3};
  std::array<int,4>::iterator it;

  do {
    // try a new permutation:
    std::prev_permutation(foo.begin(),foo.end());

    // print range:
    std::cout << "foo:";
    for (int& x:foo) std::cout << ' ' << x;
    it=std::is_sorted_until(foo.begin(),foo.end());
    std::cout << " (" << (it-foo.begin()) << " elements sorted)\n";

  } while (it!=foo.end());

  std::cout << "the range is sorted!\n";

  return 0;
}

// 
// is_sorted_until.cc ends here
