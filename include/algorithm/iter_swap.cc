// iter_swap.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 5月 24 16:29:38 2015 (+0800)
// Last-Updated: 日 5月 24 16:29:57 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

// iter_swap example
#include <iostream>     // std::cout
#include <algorithm>    // std::iter_swap
#include <vector>       // std::vector

int main () {

  int myints[]={10,20,30,40,50 };              //   myints:  10  20  30  40  50
  std::vector<int> myvector (4,99);            // myvector:  99  99  99  99

  std::iter_swap(myints,myvector.begin());     //   myints: [99] 20  30  40  50
                                               // myvector: [10] 99  99  99

  std::iter_swap(myints+3,myvector.begin()+2); //   myints:  99  20  30 [99] 50
                                               // myvector:  10  99 [40] 99

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}

// 
// iter_swap.cc ends here
