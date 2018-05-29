// wuhongyi.hh --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 六 3月 29 20:16:50 2014 (+0800)
// Last-Updated: 六 3月 29 20:32:09 2014 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 2
// URL: http://wuhongyi.cn 

#ifndef _WUHONGYI_H_
#define _WUHONGYI_H_

#include <map>
#include <cstring>
#include <iostream>

using namespace std;

class wuhongyi
{
public:
  wuhongyi();
  virtual ~wuhongyi();

  void fun();

  map<string,double> radius;
  map <string,double>::iterator cp;
};

#endif /* _WUHONGYI_H_ */
// 
// wuhongyi.hh ends here
