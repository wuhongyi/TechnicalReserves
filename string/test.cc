// test.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 六 4月 19 10:38:27 2014 (+0800)
// Last-Updated: 五 9月 25 20:18:15 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 12
// URL: http://wuhongyi.cn 

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
  string a="zxAvbnm";
  int num=a.size();
  cout<<num<<endl;
for (int i = 0; i<num; ++i)
  {
    cout<<a[i]<<endl;
  }
 if (a[2]>='0'&&a[2]<='9')
  {
    cout<<"zzzzzzzzzzzzzzzzzzzzzzzzz"<<endl;
  }

 string aaa="PKUwuhongyi12";
 aaa.erase(0, 11);
 cout<<aaa<<endl;

  return 0;
}


// 
// test.cc ends here
