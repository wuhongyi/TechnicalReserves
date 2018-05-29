// sleepuntil.cc --- 
// 
// Description: 有错！！！
// Author: HongyiWu,吴鸿毅
// Email: wuhongyi@qq.com 
// Created: 三 3月  5 16:24:43 2014 (+0800)
// Last-Updated: 三 3月  5 16:44:30 2014 (+0800)
//           By: HongyiWu,吴鸿毅
//     Update #: 6
// URL: http://wuhongyi.cn 

// this_thread::sleep_for example
#include <iostream>       // std::cout
#include <iomanip>        // std::put_time
#include <thread>         // std::this_thread::sleep_until
#include <chrono>         // std::chrono::system_clock
#include <ctime>          // std::time_t, std::tm, std::localtime, std::mktime
using namespace std;

int main() 
{
  using chrono::system_clock;
  time_t tt = system_clock::to_time_t (system_clock::now());

  struct tm * ptm = localtime(&tt);
  cout << "Current time: " << put_time(ptm,"%X") << '\n';

  cout << "Waiting for the next minute to begin...\n";
  ++ptm->tm_min; ptm->tm_sec=0;
  this_thread::sleep_until (system_clock::from_time_t (mktime(ptm)));

  cout << put_time(ptm,"%X") << " reached!\n";

  return 0;
}
// 
// sleepuntil.cc ends here
