// includes.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 5月 24 16:23:25 2015 (+0800)
// Last-Updated: 日 5月 24 16:23:37 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// includes algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::includes, std::sort

bool myfunction (int i, int j) { return i<j; }

int main () {
  int container[] = {5,10,15,20,25,30,35,40,45,50};
  int continent[] = {40,30,20,10};

  std::sort (container,container+10);
  std::sort (continent,continent+4);

  // using default comparison:
  if ( std::includes(container,container+10,continent,continent+4) )
    std::cout << "container includes continent!\n";

  // using myfunction as comp:
  if ( std::includes(container,container+10,continent,continent+4, myfunction) )
    std::cout << "container includes continent!\n";

  return 0;
}

// 
// includes.cc ends here
