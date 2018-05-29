// lock.cc --- 
// 
// Description: 
// Author: HongyiWu,吴鸿毅
// Email: wuhongyi@qq.com 
// Created: 六 3月  8 11:51:13 2014 (+0800)
// Last-Updated: 六 3月  8 11:54:58 2014 (+0800)
//           By: HongyiWu,吴鸿毅
//     Update #: 2
// URL: http://wuhongyi.cn 

// std::lock example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::lock

std::mutex foo,bar;

void task_a () {
  // foo.lock(); bar.lock(); // replaced by:
  std::lock (foo,bar);
  std::cout << "task a\n";
  foo.unlock();
  bar.unlock();
}

void task_b () {
  // bar.lock(); foo.lock(); // replaced by:
  std::lock (bar,foo);
  std::cout << "task b\n";
  bar.unlock();
  foo.unlock();
}

int main ()
{
  std::thread th1 (task_a);
  std::thread th2 (task_b);

  th1.join();
  th2.join();

  return 0;
}
// 
// lock.cc ends here
