// sleepfor.cc --- 
// 
// Description: 
// Author: HongyiWu,吴鸿毅
// Email: wuhongyi@qq.com 
// Created: 三 3月  5 16:21:24 2014 (+0800)
// Last-Updated: 三 3月  5 16:21:30 2014 (+0800)
//           By: HongyiWu,吴鸿毅
//     Update #: 1
// URL: http://wuhongyi.cn 

// this_thread::sleep_for example
#include <iostream>       // std::cout
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
 
int main() 
{
  std::cout << "countdown:\n";
  for (int i=10; i>0; --i) {
    std::cout << i << '\n';
    std::this_thread::sleep_for (std::chrono::seconds(1));
  }
  std::cout << "Lift off!\n";

  return 0;
}
// 
// sleepfor.cc ends here
