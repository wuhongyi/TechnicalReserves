// map_size.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 4月 20 16:21:50 2015 (+0800)
// Last-Updated: 一 4月 20 16:22:35 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 2
// URL: http://wuhongyi.cn 

// map::size
#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;
  mymap['a']=101;
  mymap['b']=202;
  mymap['c']=302;
  mymap['c']=301;
  std::cout << "mymap.size() is " << mymap.size() << '\n';

  return 0;
}

// 
// map_size.cc ends here
