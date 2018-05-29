// set_operator.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 4月 20 19:07:00 2015 (+0800)
// Last-Updated: 一 4月 20 19:07:09 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// assignment operator with sets
#include <iostream>
#include <set>

int main ()
{
  int myints[]={ 12,82,37,64,15 };
  std::set<int> first (myints,myints+5);   // set with 5 ints
  std::set<int> second;                    // empty set

  second = first;                          // now second contains the 5 ints
  first = std::set<int>();                 // and first is empty

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  return 0;
}

// 
// set_operator.cc ends here
