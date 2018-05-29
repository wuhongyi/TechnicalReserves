// main.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 三 9月 23 21:13:52 2015 (+0800)
// Last-Updated: 六 4月 23 14:41:55 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 11
// URL: http://wuhongyi.cn 


#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
using namespace std;

int main( ) 
{
  string real = "12.32 12 35 25.3 36.366";
  stringstream ss;
  ss.clear();//重复使用前一定要清空
  ss<<real;
  vector< double > vd;

  // Collect all real numbers.
  double temp;
  while( ss >> temp )
    { 
      vd.push_back( temp );
      cout<<temp<<endl;
    }

  string a="$12.m";
  cout<<a[0]<<" "<<a[1]<< " "<<a[2]<<" "<<a[3]<<endl;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  //数字转字符串
  ss.clear();
  int num=132456789;
  ss<<num;
  string strnum;
  ss>>strnum;
  cout<<strnum<<endl;


  return 0;
}


// 
// main.cc ends here
