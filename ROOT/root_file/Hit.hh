// Hit.hh --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 六 5月  2 16:40:18 2015 (+0800)
// Last-Updated: 六 5月  2 16:40:35 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

#ifndef _HIT_H_
#define _HIT_H_

class Hit
{
public:
  Hit(){}
  virtual ~Hit(){}

  void SetEnergy(double e){energy=e;}
  void SetID(int i){id=i;}
  double GetEnergy(){return energy;}
  int GetID(){return id;}
  double energy;
  int id;
};

#endif /* _HIT_H_ */
// 
// Hit.hh ends here
