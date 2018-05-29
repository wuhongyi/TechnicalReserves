// DataWrite.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 4月 13 15:52:21 2014 (+0800)
// Last-Updated: 日 4月 13 18:12:05 2014 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 8
// URL: http://wuhongyi.cn 

#include "DataWrite.hh"
#include<cstdlib>
#include <iostream>

using namespace std;

DataWrite::DataWrite()
{
  name="wuhongyi.txt";
  OpenFile();
}

DataWrite::~DataWrite()
{

}

void DataWrite::OpenFile()
{
  point.open(name.c_str());
 if(point.fail())
 {
  cout<<"Sorry,couldn't open file"<<endl;
  exit(1);   //from cstdlib
 }
}

void DataWrite::CloseFile()
{
  point.close();
}
// 
// DataWrite.cc ends here
