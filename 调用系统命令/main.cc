// main.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 四 3月 12 16:20:50 2015 (+0800)
// Last-Updated: 四 3月 12 16:58:31 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 14
// URL: http://wuhongyi.cn 

#include<cstdlib>
#include<sstream>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
  string NAME="B4";
  string aa="";
  string bb="";
  string filename="";


  stringstream ss;

  for (int number=0; number<2; number++)
    {
      ss<<number;
      string bb;ss>>bb;
      filename=filename+NAME+"_t"+bb+".root ";
      ss.clear();
    }
  aa="hadd "+NAME+".root "+filename;
  cout<<"aa:"<<aa<<endl;
  bb="rm "+filename;
  cout<<"bb:"<<bb<<endl;
  system(aa.c_str());
  system(bb.c_str());
  return 0;
}
// 
// main.cc ends here
