#include<iostream>
#include<ctime>
using namespace std;
void foo() 
{
  for(int i=0;i<200000;i++)
    cout<<"a"<<i<<"b"<<endl;
}
int main()
{ 
  time_t stime , etime ;
  time( &stime ); /* get start time */

  foo();


  time( &etime ); /* get end time */
  cout<<"benciyongshi:"<<etime - stime<<endl;
  return 0; 
}
