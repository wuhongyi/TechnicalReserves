// map_find.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 4月 20 19:30:18 2015 (+0800)
// Last-Updated: 日 5月 10 16:00:37 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 9
// URL: http://wuhongyi.cn 

// map::find
#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;
  mymap['a']=60;
  it=mymap.find('b');
  mymap.erase (it);
  mymap.erase (mymap.find('d'));

  // print content:
  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap.find('a')->second << '\n';
  std::cout << "c => " << mymap.find('c')->second << '\n';

  if(mymap.find('f')==mymap.end()) std::cout << "#########" << '\n';

  return 0;
}

// 
// map_find.cc ends here














