// move.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 7月 12 12:55:08 2015 (+0800)
// Last-Updated: 日 7月 12 12:55:36 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

//C++11
// move algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::move (ranges)
#include <utility>      // std::move (objects)
#include <vector>       // std::vector
#include <string>       // std::string

int main () {
  std::vector<std::string> foo = {"air","water","fire","earth"};
  std::vector<std::string> bar (4);

  // moving ranges:
  std::cout << "Moving ranges...\n";
  std::move ( foo.begin(), foo.begin()+4, bar.begin() );

  std::cout << "foo contains " << foo.size() << " elements:";
  std::cout << " (each in an unspecified but valid state)";
  std::cout << '\n';

  std::cout << "bar contains " << bar.size() << " elements:";
  for (std::string& x: bar) std::cout << " [" << x << "]";
  std::cout << '\n';

  // moving container:
  std::cout << "Moving container...\n";
  foo = std::move (bar);

  std::cout << "foo contains " << foo.size() << " elements:";
  for (std::string& x: foo) std::cout << " [" << x << "]";
  std::cout << '\n';

  std::cout << "bar is in an unspecified but valid state";
  std::cout << '\n';

  return 0;
}
// 
// move.cc ends here
