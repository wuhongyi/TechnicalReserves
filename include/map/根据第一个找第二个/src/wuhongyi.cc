// wuhongyi.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 六 3月 29 20:16:41 2014 (+0800)
// Last-Updated: 六 3月 29 20:42:03 2014 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 6
// URL: http://wuhongyi.cn 

  //radical name
  //1: .OH
  //2: eaq-
  //3: H.
  //4: H3O+
  //5: H2
  //6: H2O2
  //7: O
#include "wuhongyi.hh"

wuhongyi::wuhongyi()
{
  radius.insert(pair<string,double> (".OH+.OH",0.1416));
  radius.insert(pair<string,double> (".OH+eaq-",0.4525));
  radius.insert(pair<string,double> (".OH+H.",0.2697));
  radius.insert(pair<string,double> (".OH+H2",0.00076));
  radius.insert(pair<string,double> (".OH+H2O2",0.00061));
  radius.insert(pair<string,double> ("eaq-+eaq-",0.0807));
  radius.insert(pair<string,double> ("eaq-+H.",0.2873));
  radius.insert(pair<string,double> ("eaq-+H3O+",0.1664));
  radius.insert(pair<string,double> ("eaq-+O",0.3804));
  radius.insert(pair<string,double> ("H.+H.",0.0944));
  radius.insert(pair<string,double> ("H.+H2O2",0.00144));
  radius.insert(pair<string,double> ("H.+O",0.2904));



  cp=radius.find(".OH+H.");
  cout<<cp->second<<endl;
}

wuhongyi::~wuhongyi()
{

}

void wuhongyi::fun()
{
  cout<<"zzzzzzzzzzzzzzzzzzzzzzz"<<endl;
}
// 
// wuhongyi.cc ends here
