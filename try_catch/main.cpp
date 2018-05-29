#include <iostream>
#include <cmath>
using namespace std;
char mm,nn;
int main( )
{
  double triangle(double,double,double);
  double a,b,c;
  cin>>a>>b>>c;
  try//在try块中包含要检查的函数
    {
      while(a>0 && b>0 && c>0)
	{
	  cout<<triangle(a,b,c)<<endl;
	  cin>>a>>b>>c;
	}
    }
  catch(char) //用catch捕捉异常信息并作相应处理
    {cout<<"a="<<a<<",b="<<b<<",c="<<c<<",that is not a triangle!"<<endl;}
  // catch(double) //用catch捕捉异常信息并作相应处理
  //   {cout<<"that is not a triangle!"<<endl;}

  cout<<"end"<<endl;
  return 0;
}


double triangle(double a,double b,double c) //计算三角形的面积的函数
{
  double s=(a+b+c)/2;
  if (a+b<=c||b+c<=a||c+a<=b) throw mm; //当不符合三角形条件抛出异常信息
  // if (a+b>c||b+c>a||c+a>b) throw a;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}
