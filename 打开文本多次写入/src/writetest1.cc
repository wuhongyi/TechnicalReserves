// writetest1.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 4月 13 16:03:13 2014 (+0800)
// Last-Updated: 日 4月 13 18:11:11 2014 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 12
// URL: http://wuhongyi.cn 

#include "writetest1.hh"
#include "iostream"

using namespace std;

writetest1::writetest1(DataWrite *pt)
{
  write=pt;
  // write->OpenFile();
}

writetest1::~writetest1()
{

}

void writetest1::fun()
{
  write->point<<"sdfsjdfgsfj"<<endl<<endl; 

  cout<<"cccccccccccccccccccccccc"<<endl<<endl;
}
// 
// writetest1.cc ends here
