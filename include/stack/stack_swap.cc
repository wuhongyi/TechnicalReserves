// stack_swap.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 4月 20 21:11:16 2015 (+0800)
// Last-Updated: 一 4月 20 21:11:45 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 2
// URL: http://wuhongyi.cn 

//C++11
// stack::swap
#include <iostream>       // std::cout
#include <stack>          // std::stack

int main ()
{
  std::stack<int> foo,bar;
  foo.push (10); foo.push(20); foo.push(30);
  bar.push (111); bar.push(222);

  foo.swap(bar);

  std::cout << "size of foo: " << foo.size() << '\n';
  std::cout << "size of bar: " << bar.size() << '\n';

  return 0;
}

// 
// stack_swap.cc ends here
