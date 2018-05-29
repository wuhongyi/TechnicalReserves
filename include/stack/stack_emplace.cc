// stack_emplace.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 4月 20 21:05:23 2015 (+0800)
// Last-Updated: 一 4月 20 21:06:14 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 3
// URL: http://wuhongyi.cn 

//C++11
// stack::emplace
#include <iostream>       // std::cin, std::cout
#include <stack>          // std::stack
#include <string>         // std::string, std::getline(string)

int main ()
{
  std::stack<std::string> mystack;

  mystack.emplace ("First sentence");
  mystack.emplace ("Second sentence");

  std::cout << "mystack contains:\n";
  while (!mystack.empty())
  {
    std::cout << mystack.top() << '\n';
    mystack.pop();
  }

  return 0;
}

// 
// stack_emplace.cc ends here
