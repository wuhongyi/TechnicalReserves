// thread.cc --- 
// 
// Description: 
// Author: HongyiWu,吴鸿毅
// Email: wuhongyi@qq.com 
// Created: 一 3月  3 13:08:14 2014 (+0800)
// Last-Updated: 三 3月  5 09:26:09 2014 (+0800)
//           By: HongyiWu,吴鸿毅
//     Update #: 13
// URL: http://wuhongyi.cn 

// #include <thread>
// #include <iostream>
// #include <vector>
// using namespace std;
	  
// void hello(){
//   std::cout << "Hello from thread " << std::this_thread::get_id() << std::endl;
// }
	  
// int main(){
//   std::vector<std::thread> threads;
	  
//   for(int i = 0; i < 5; ++i){
//     threads.push_back(std::thread(hello));
//   }
	  
//   for(auto& thread : threads){
//     thread.join();
//   }
	  
//   return 0;
// }

// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
 
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
      double b;
      b=j*j*j;
// std::cout<<"bbb-"<<j<<std::endl;
    }
  // do stuff...
}
void doo() 
{
  for (unsigned int k = 0; k<1000000000; ++k)
    {
      double c;
      c=k*k*k;      
// std::cout<<"ccc-"<<k<<std::endl;
    }// do stuff...
}

int main() 
{
time_t start, end;
time(&start);

int parts = 4;
std::thread *tt = new std::thread[parts - 1]; 

  std::thread first (foo);     // spawn new thread that calls foo()
  std::thread second (bar,0);  // spawn new thread that calls bar(0)
  std::thread three(doo);
  std::cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
  first.join();                // pauses until first finishes
  second.join();               // pauses until second finishes
  three.join();
  std::cout << "foo and bar completed.\n";
time(&end);
 std::cout << difftime(end, start) << " seconds" << std::endl;
  return 0;
}

// 
// thread.cc ends here
