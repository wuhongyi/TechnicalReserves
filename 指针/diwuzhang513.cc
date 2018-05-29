// diwuzhang513.cc --- 
// 
// Description: 
// Author: HongyiWu,吴鸿毅
// Email: wuhongyi@qq.com 
// Created: 六 2月 22 20:59:56 2014 (+0800)
// Last-Updated: 六 2月 22 21:10:47 2014 (+0800)
//           By: HongyiWu,吴鸿毅
//     Update #: 1
// URL: http://wuhongyi.cn 
#include <iostream>
#include <iomanip>
using namespace std;
double maxmin(double a[][5],double *pmax,double *pmin,int n,int m);
int main()
{
  double max,min;
  double a[][5]={{85,90,66,68,48},{79,88,84,98,92},{90,77,78,72,80},{69,86,82,89,77}};
  for (int i = 0; i<=3; ++i)
    {
      for (int j=0; j<=4; ++j)
	{
	  cout<<setw(6)<<a[i][j];
	}
      cout<<endl;
    }
  cout<<"Average="<<maxmin(a,&max,&min,4,5)<<endl;
  cout<<"Max="<<max<<endl;
  cout<<"Min="<<min<<endl;
}

double maxmin(double a[][5],double *pmax,double *pmin,int n,int m)
{
  double aver=0;
  double sum =0;
  *pmax=*pmin=a[0][0];
  for (int i = 0; i<n; ++i)
    {
      for(int j=0;j<m;++j)
	{
	  if (a[i][j]>*pmax)
	    {
	      *pmax=a[i][j];
	    }
	  if (a[i][j]<*pmin)
	    {
	      *pmin=a[i][j];
	    }
	  sum+=a[i][j];
	}
    }
  aver=sum/20;
  return aver;
}

// 
// diwuzhang513.cc ends here
