// main.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 3月 30 21:01:02 2015 (+0800)
// Last-Updated: 一 3月 30 21:29:12 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 30
// URL: http://wuhongyi.cn 

#include <iostream>
using namespace std;

class Atom
{
public:
  Atom(){}
  virtual ~Atom(){}

  void SetData()
  {
    v=new double[10];
    for (int i = 0; i<10; ++i)
      {
    	v[i]=i+1.0;
      }
  }

  void Print()
  {
    for (int i = 0; i<10; ++i)
      {
	cout<<v[i]<<"  ";
      }
    cout<<endl;
}
  const int number=10;

  double *v;
};

int main(int argc, char *argv[])
{
  Atom *atom=new Atom;
  atom->SetData();
  atom->Print();
  double *vv;
  vv=atom->v;
  for (int i = 0; i<10; ++i)
    {
      vv[i]=2*vv[i];
    }
 atom->Print();
  return 0;
}


// 
// main.cc ends here
