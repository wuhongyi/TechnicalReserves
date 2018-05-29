// main.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 三 4月 27 12:31:46 2016 (+0800)
// Last-Updated: 三 4月 27 13:30:26 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 23
// URL: http://wuhongyi.cn 

#include <iostream>
#include <ctime>
#include <unistd.h>

#include "global.hh"
#include "User.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


int main(int argc, char *argv[])
{
  int N = 10000;
  int data[1000] = {1,2,3,4,5,6,7,8,9,10};

  time_t stime;
  time_t etime;
  

  OpenFile();
  time( &stime );
  for (int i = 0; i < N; ++i)
    {
      // for (int j = 0; j < 10; ++j)
      // 	fprintf(f,"%d",data[j]);

      WriteData(data);
    }
  time( &etime );
  std::cout<<"The running time： "<<(etime-stime)/3600<<"hour "<<((etime-stime)%3600)/60<<"min "<<((etime-stime)%3600)%60<<"sec。"<<std::endl;

  CloseFile();
  return 0;
}



// 
// main.cc ends here
