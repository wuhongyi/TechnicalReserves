// map_at.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 4月 20 19:21:24 2015 (+0800)
// Last-Updated: 一 4月 20 19:21:43 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

//C++11
// map::at
#include <iostream>
#include <string>
#include <map>

int main ()
{
  std::map<std::string,int> mymap = {
                { "alpha", 0 },
                { "beta", 0 },
                { "gamma", 0 } };

  mymap.at("alpha") = 10;
  mymap.at("beta") = 20;
  mymap.at("gamma") = 30;

  for (auto& x: mymap) {
    std::cout << x.first << ": " << x.second << '\n';
  }

  return 0;
}

// 
// map_at.cc ends here
