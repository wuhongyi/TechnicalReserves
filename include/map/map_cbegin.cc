// map_cbegin.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 4月 20 19:23:09 2015 (+0800)
// Last-Updated: 一 4月 20 19:23:22 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

//C++11
// map::cbegin/cend
#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  // print content:
  std::cout << "mymap contains:";
  for (auto it = mymap.cbegin(); it != mymap.cend(); ++it)
    std::cout << " [" << (*it).first << ':' << (*it).second << ']';
  std::cout << '\n';

  return 0;
}

// 
// map_cbegin.cc ends here
