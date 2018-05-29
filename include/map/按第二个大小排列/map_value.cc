// map_value.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 四 3月 27 13:54:46 2014 (+0800)
// Last-Updated: 四 3月 27 14:24:33 2014 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 11
// URL: http://wuhongyi.cn 

#include<map>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

typedef pair<int, double> PAIR;

struct CmpByValue {
  bool operator()(const PAIR& lhs, const PAIR& rhs) {
    return lhs.second < rhs.second;
  }
};

//输出重载
ostream& operator<<(ostream& out, const PAIR& p) {
  return out << p.first << "\t" << p.second;
}

int main(int argc, char *argv[])
{
  map<int, double> aaa;
  aaa[0] = 90.1;
  aaa[1] = 79.9;
  aaa[2] = 92.69;
  aaa.insert(make_pair(3,99.12));
  aaa.insert(make_pair(4,86.09));
  //把map中元素转存到vector中 
  vector<PAIR> bbb(aaa.begin(), aaa.end());
  sort(bbb.begin(), bbb.end(), CmpByValue());
  //输出
  for (int i = 0; i != bbb.size(); ++i) {
    cout << bbb[i]<< endl;
  }
  return 0;
}


// 
// map_value.cc ends here
