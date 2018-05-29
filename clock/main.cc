// main.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 四 1月 22 12:36:51 2015 (+0800)
// Last-Updated: 四 1月 22 12:50:19 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 6
// URL: http://wuhongyi.cn 

#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  
  clock_t m_Daq_start, m_Daq_stop;
  m_Daq_start = clock();
  cout<<m_Daq_start<<endl;
    for (int i = 0; i<10000; ++i)
      {
	double temp=1+2+3+4+5+6+7+8+9+10;
	int j=65535;
	while(j--);
      }
  m_Daq_stop = clock();
  cout<<m_Daq_stop<<endl;
  double time = (double)( m_Daq_stop - m_Daq_start )/(double)CLOCKS_PER_SEC;
  cout<<CLOCKS_PER_SEC<<endl;
  cout<<time<<endl;

  m_Daq_start = clock();
  cout<<m_Daq_start<<endl;
    for (int i = 0; i<10000; ++i)
      {
	double temp=1+2+3+4+5+6+7+8+9+10;
	int j=65535;
	while(j--);
      }
  m_Daq_stop = clock();
  cout<<m_Daq_stop<<endl;
  time = (double)( m_Daq_stop - m_Daq_start )/(double)CLOCKS_PER_SEC;
  cout<<CLOCKS_PER_SEC<<endl;
  cout<<time<<endl;

  return 0;
}


// 
// main.cc ends here
