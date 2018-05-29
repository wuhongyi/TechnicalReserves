// is_partitioned.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 5月 24 16:26:34 2015 (+0800)
// Last-Updated: 日 5月 24 16:26:52 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

//C++11
// is_partitioned example
#include <iostream>     // std::cout
#include <algorithm>    // std::is_partitioned
#include <array>        // std::array

bool IsOdd (int i) { return (i%2)==1; }

int main () {
  std::array<int,7> foo {1,2,3,4,5,6,7};

  // print contents:
  std::cout << "foo:"; for (int& x:foo) std::cout << ' ' << x;
  if ( std::is_partitioned(foo.begin(),foo.end(),IsOdd) )
    std::cout << " (partitioned)\n";
  else
    std::cout << " (not partitioned)\n";

  // partition array:
  std::partition (foo.begin(),foo.end(),IsOdd);

  // print contents again:
  std::cout << "foo:"; for (int& x:foo) std::cout << ' ' << x;
  if ( std::is_partitioned(foo.begin(),foo.end(),IsOdd) )
    std::cout << " (partitioned)\n";
  else
    std::cout << " (not partitioned)\n";

  return 0;
}

// 
// is_partitioned.cc ends here
