// DataWrite.hh --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 4月 13 15:51:22 2014 (+0800)
// Last-Updated: 日 4月 13 17:02:05 2014 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 5
// URL: http://wuhongyi.cn 

#ifndef _DATAWRITE_H_
#define _DATAWRITE_H_

#include <cstring>
#include <fstream>
using namespace std;

class DataWrite
{
public:
  DataWrite();
  virtual ~DataWrite();
  void OpenFile();
  void CloseFile();
  void Fill();
public:
  string name;
  ofstream point;
};

#endif /* _DATAWRITE_H_ */
// 
// DataWrite.hh ends here
