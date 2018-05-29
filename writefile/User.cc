// User.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 三 4月 27 12:48:15 2016 (+0800)
// Last-Updated: 三 4月 27 13:52:44 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 11
// URL: http://wuhongyi.cn 

#include "User.hh"
#include <iostream>

void OpenFile()
{
  if((f=fopen("test.txt","ab")) == NULL)
     std::cout<<"-1"<<std::endl;
}

void CloseFile()
{
  if(f != NULL)
    fclose(f);
  f = NULL;
}

void WriteData(int *d)
{
  fwrite(d,sizeof(int),1000,f);
  int ab = 123;
  fwrite(&ab,sizeof(int),1,f);
}

// 
// User.cc ends here










