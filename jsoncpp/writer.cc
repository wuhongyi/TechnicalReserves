// writer.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 11月 20 16:22:59 2016 (+0800)
// Last-Updated: 日 11月 20 16:27:14 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 3
// URL: http://wuhongyi.cn 

// g++ writer.cc -ljsoncpp -o 456
// http://www.cnblogs.com/kex1n/archive/2011/12/02/2272328.html
#include <fstream>
#include <iostream>
#include "jsoncpp/json/json.h"
 
 
int main()
{
  Json::Value root;
  Json::FastWriter writer;
  Json::Value person;
 
  person["name"] = "hello world";
  person["age"] = 100;
  root.append(person);
 
  std::string json_file = writer.write(root);
 
 
  std::ofstream ofs;
  ofs.open("write.json");
  ofs<<json_file;
 
  return 0;
}

// 
// writer.cc ends here
