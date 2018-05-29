#include<iostream>
#include<fstream>
#include<cstdlib>

#include "DataWrite.hh"
#include "writetest1.hh"


using namespace std;

int main()
{
  DataWrite* aa=new DataWrite;
  writetest1* bb=new writetest1(aa);
  bb->fun();

  // Date *oneDay;
  // Date *today=new Date(2013,9,29);
  
  // oneDay=new Date(2000);
  // cout<<"One day is:";
  // oneDay->Display();
  
  // cout<<"Today is:";
  // today->Display();
  
  // delete oneDay;
  // delete today;
  // Circle c(3);
  // cout<<"Area="<<c.Area()<<endl;
  
  return 0;
  
}
