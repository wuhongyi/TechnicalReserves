// thread0.cc --- 
// 
// Description: 
// Author: HongyiWu,吴鸿毅
// Email: wuhongyi@qq.com 
// Created: 一 3月  3 14:23:39 2014 (+0800)
// Last-Updated: 六 3月  8 11:57:14 2014 (+0800)
//           By: HongyiWu,吴鸿毅
//     Update #: 11
// URL: http://wuhongyi.cn 

#include <iostream>       // std::cout

 #include <ctime>

void foo() 
{
  for (unsigned int i = 0; i<1000000000; ++i)
{
  double a;
  a=i*i*i;
  // std::cout<<"aaa-"<<i<<std::endl;
 }// do stuff...
}

void bar(int x)
{
  for (unsigned int j=0; j<1000000000; ++j)
    {
      double c;
      c=j*j*j;      
// std::cout<<"bbb-"<<j<<std::endl;
    }
// do stuff...
}
void doo() 
{
  for (unsigned int k = 0; k<1000000000; ++k)
{
  double b;
  b=k*k*k;
  // std::cout<<"ccc-"<<k<<std::endl;
 }// do stuff...
}

int main() 
{
  time_t start, end;
  time(&start);
  std::cout << "main, foo and bar now execute concurrently...\n";
  foo();
  bar(0);
  doo();
  // synchronize threads:
  std::cout << "foo and bar completed.\n";
  time(&end);

  std::cout << difftime(end, start) << " seconds" << std::endl;

  return 0;
}
// 
// thread0.cc ends here
