// map_emplace_hint.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 4月 20 19:26:48 2015 (+0800)
// Last-Updated: 一 4月 20 19:27:04 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

//C++11
// map::emplace_hint
#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;
  auto it = mymap.end();

  it = mymap.emplace_hint(it,'b',10);
  mymap.emplace_hint(it,'a',12);
  mymap.emplace_hint(mymap.end(),'c',14);

  std::cout << "mymap contains:";
  for (auto& x: mymap)
    std::cout << " [" << x.first << ':' << x.second << ']';
  std::cout << '\n';

  return 0;
}

// 
// map_emplace_hint.cc ends here
