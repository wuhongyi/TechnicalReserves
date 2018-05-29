// Data.hh --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 4月 22 16:43:53 2014 (+0800)
// Last-Updated: 二 4月 22 17:00:21 2014 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 4
// URL: http://wuhongyi.cn 

#ifndef _DATA_H_
#define _DATA_H_
#include <cstring>
#include <string>

using namespace std;

class Data
{
public:
  Data();
  virtual ~Data();

private:
  string name;
  int id;
  double x;
  double y;
  double z;
public:
  string GetName();
  void SetName(string );
  int DetId();
  void SetId(int );

};

#endif /* _DATA_H_ */
// 
// Data.hh ends here
