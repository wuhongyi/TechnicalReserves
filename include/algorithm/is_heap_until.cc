// is_heap_until.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 5月 24 16:25:31 2015 (+0800)
// Last-Updated: 日 5月 24 16:25:49 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

//C++11
// is_heap example
#include <iostream>     // std::cout
#include <algorithm>    // std::is_heap_until, std::sort, std::reverse
#include <vector>       // std::vector

int main () {
  std::vector<int> foo {2,6,9,3,8,4,5,1,7};

  std::sort(foo.begin(),foo.end());
  std::reverse(foo.begin(),foo.end());

  auto last = std::is_heap_until (foo.begin(),foo.end());

  std::cout << "The " << (last-foo.begin()) << " first elements are a valid heap:";
  for (auto it=foo.begin(); it!=last; ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}

// 
// is_heap_until.cc ends here
