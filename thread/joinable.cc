// joinable.cc --- 
// 
// Description: 
// Author: HongyiWu,吴鸿毅
// Email: wuhongyi@qq.com 
// Created: 三 3月  5 15:03:40 2014 (+0800)
// Last-Updated: 三 3月  5 15:51:53 2014 (+0800)
//           By: HongyiWu,吴鸿毅
//     Update #: 11
// URL: http://wuhongyi.cn 

// example for thread::joinable
#include <iostream>       // std::cout
#include <thread>         // std::thread
 using namespace std;

void mythread() 
{
  for (int i = 0; i<1000000000; ++i)
    {
      double a;
      a=i*i*i*i;
    }
}

void mythread1() 
{
  for (int i = 0; i<1000000000; ++i)
    {
      double a;
      a=i*i*i*i;
    }
}

void mythread2() 
{
  for (int i = 0; i<1000000000; ++i)
    {
      double a;
      a=i*i*i*i;
      //    cout<<"----"<<a<<endl;
    }
}

void mythread3() 
{
  for (int i = 0; i<1000000000; ++i)
    {
      double a;
      a=i*i*i*i;
      //   cout<<"****"<<a<<endl;
    }
}
 
int main() 
{
  for (int i = 0; i<1000000; ++i)
    {
      cout<<"!!!!"<<i<<endl;
    }
  std::thread foo(mythread1);
  std::thread bar(mythread);

  std::cout << "Joinable after construction:\n" << std::boolalpha;
  std::cout << "foo: " << foo.joinable() << '\n';
  std::cout << "bar: " << bar.joinable() << '\n';

  if (foo.joinable()) foo.join();
  if (bar.joinable()) bar.join();

  std::cout << "Joinable after joining:\n" << std::boolalpha;
  std::cout << "foo: " << foo.joinable() << '\n';
  std::cout << "bar: " << bar.joinable() << '\n';

  std::thread too(mythread2);
  std::thread tooo(mythread3);
  too.join();
  tooo.join();
  for (int i = 0; i<1000000; ++i)
    {
      cout<<"!!!!"<<i<<endl;
    }
  return 0;
}
// 
// joinable.cc ends here
