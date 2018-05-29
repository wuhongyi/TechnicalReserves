// map_emplace.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 4月 20 19:25:36 2015 (+0800)
// Last-Updated: 一 4月 20 19:25:44 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

//C++11
// map::emplace
#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;

  mymap.emplace('x',100);
  mymap.emplace('y',200);
  mymap.emplace('z',100);

  std::cout << "mymap contains:";
  for (auto& x: mymap)
    std::cout << " [" << x.first << ':' << x.second << ']';
  std::cout << '\n';

  return 0;
}

// 
// map_emplace.cc ends here
