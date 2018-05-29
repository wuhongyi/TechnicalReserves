// main.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 4月 12 12:27:30 2016 (+0800)
// Last-Updated: 二 4月 12 13:14:09 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 22
// URL: http://wuhongyi.cn 

#include <iostream>
using namespace std;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

int main(int argc, char *argv[])
{
  char buffer[] = "1234";
  // 1=49:00110001
  // 2=50:00110010
  // 3=51:00110011
  // 4=52:00110100
  unsigned int data[100];
  unsigned int DATA;
  unsigned int *p;

  // 由低位往高位依次填充
  p = data;
  *p = *((unsigned int *)buffer);//00110100,00110011,00110010,00110001
  DATA = *((unsigned int *)buffer);
  cout<<data[0]<<"  "<<DATA<<endl;

  cout<<"-----------------------"<<endl;

  char tempchar[] = "1234";
  cout<<*(unsigned int *)tempchar<<endl;
  unsigned int tempint = 875770417;
  unsigned int temp;
  temp = tempint & 0x000000FF;
  cout<<temp<<endl;
  temp = (tempint & 0x0000FF00) >> 8;
  cout<<temp<<endl;
  temp = (tempint & 0x00FF0000) >> 16;
  cout<<temp<<endl;
  temp = (tempint & 0xFF000000) >> 24;
  cout<<temp<<endl;
  
  return 0;
}

// 
// main.cc ends here










