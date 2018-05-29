// main.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 四 4月  9 08:32:41 2015 (+0800)
// Last-Updated: 四 4月  9 12:20:13 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 12
// URL: http://wuhongyi.cn 


//GCC包含了openMP
//g++ -fopenmp main.cc -o 123
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void Test (int n) 
{
  for(int i = 0; i < 10000; ++i)
    {
      //do nothing, just waste time
    }
  //printf("%d, ", n);
  cout<<n<<"  id:"<<omp_get_thread_num()<<"  当前线程数目:"<<omp_get_num_threads()<<endl;
}

int main(int argc,char* argv[]) 
{
  omp_set_num_threads(2);
  cout<<"当前线程数目:"<<omp_get_num_threads()<<endl;
  cout<<"===================================="<<endl;
#pragma omp parallel for
  for(int i = 0; i < 10; ++i)
    {
    Test( i );
    }
  cout<<"ending!"<<endl;
}

// 
// main.cc ends here
