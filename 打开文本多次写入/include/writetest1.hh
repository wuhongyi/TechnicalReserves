// writetest1.hh --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 4月 13 16:02:13 2014 (+0800)
// Last-Updated: 日 4月 13 16:35:02 2014 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 8
// URL: http://wuhongyi.cn 

#ifndef _WRITETEST1_H_
#define _WRITETEST1_H_
#include "DataWrite.hh"
using namespace std;

class DataWrite;
class writetest1
{
public:
  writetest1(DataWrite *pt);
  virtual ~writetest1();
  DataWrite* write;

  void fun();
};

#endif /* _WRITETEST1_H_ */
// 
// writetest1.hh ends here
