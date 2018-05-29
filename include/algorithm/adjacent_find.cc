// adjacent_find.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 5月 24 15:36:04 2015 (+0800)
// Last-Updated: 日 5月 24 15:37:24 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// adjacent_find example
#include <iostream>     // std::cout
#include <algorithm>    // std::adjacent_find
#include <vector>       // std::vector

bool myfunction (int i, int j) {
  return (i==j);
}

int main () {
  int myints[] = {5,20,5,30,30,20,10,10,20};
  std::vector<int> myvector (myints,myints+8);
  std::vector<int>::iterator it;

  // using default comparison:
  it = std::adjacent_find (myvector.begin(), myvector.end());

  if (it!=myvector.end())
    std::cout << "the first pair of repeated elements are: " << *it << '\n';

  //using predicate comparison:
  it = std::adjacent_find (++it, myvector.end(), myfunction);

  if (it!=myvector.end())
    std::cout << "the second pair of repeated elements are: " << *it << '\n';

  return 0;
}

// 
// adjacent_find.cc ends here
