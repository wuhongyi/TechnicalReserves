#include <iostream>
#include <cmath>
using namespace std;
char mm,nn;
int main( )
{
  double triangle(double,double,double);
  double a,b,c;
  cin>>a>>b>>c;
  try//��try���а���Ҫ���ĺ���
    {
      while(a>0 && b>0 && c>0)
	{
	  cout<<triangle(a,b,c)<<endl;
	  cin>>a>>b>>c;
	}
    }
  catch(char) //��catch��׽�쳣��Ϣ������Ӧ����
    {cout<<"a="<<a<<",b="<<b<<",c="<<c<<",that is not a triangle!"<<endl;}
  // catch(double) //��catch��׽�쳣��Ϣ������Ӧ����
  //   {cout<<"that is not a triangle!"<<endl;}

  cout<<"end"<<endl;
  return 0;
}


double triangle(double a,double b,double c) //���������ε�����ĺ���
{
  double s=(a+b+c)/2;
  if (a+b<=c||b+c<=a||c+a<=b) throw mm; //�������������������׳��쳣��Ϣ
  // if (a+b>c||b+c>a||c+a>b) throw a;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}
