// mismatch.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 7月 12 12:53:28 2015 (+0800)
// Last-Updated: 日 7月 12 12:53:49 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// mismatch algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::mismatch
#include <vector>       // std::vector
#include <utility>      // std::pair

bool mypredicate (int i, int j) {
  return (i==j);
}

int main () {
  std::vector<int> myvector;
  for (int i=1; i<6; i++) myvector.push_back (i*10); // myvector: 10 20 30 40 50

  int myints[] = {10,20,80,320,1024};                //   myints: 10 20 80 320 1024

  std::pair<std::vector<int>::iterator,int*> mypair;

  // using default comparison:
  mypair = std::mismatch (myvector.begin(), myvector.end(), myints);
  std::cout << "First mismatching elements: " << *mypair.first;
  std::cout << " and " << *mypair.second << '\n';

  ++mypair.first; ++mypair.second;

  // using predicate comparison:
  mypair = std::mismatch (mypair.first, myvector.end(), mypair.second, mypredicate);
  std::cout << "Second mismatching elements: " << *mypair.first;
  std::cout << " and " << *mypair.second << '\n';

  return 0;
}

// 
// mismatch.cc ends here
