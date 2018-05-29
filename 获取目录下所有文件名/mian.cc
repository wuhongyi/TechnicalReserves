// mian.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 三 9月 23 21:08:45 2015 (+0800)
// Last-Updated: 六 3月  5 22:32:21 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 7
// URL: http://wuhongyi.cn 

#include<cstdio>
#include<cstdlib>
#include<dirent.h>
#include<vector>
#include<string>
#include<cstring>
#include <iostream>
int main(int argc, char *argv[])
{
  DIR *dp;
  struct dirent *dirp;
  char dirname[]=".";//当前目录
  //获取目录下所有文件名
  std::vector<std::string> file_names;//store file names
  if((dp=opendir(dirname))==NULL){
    perror("opendir error");
    exit(1);
  }
  while((dirp=readdir(dp))!=NULL){
    if((strcmp(dirp->d_name,".")==0)||(strcmp(dirp->d_name,"..")==0))
      continue;
    file_names.push_back(dirp->d_name);
  }
  for(std::vector<std::string>::iterator it = file_names.begin(); it != file_names.end(); it++)
    {
      std::cout<<*it<<std::endl;
    }
  return 0;
}


// 
// mian.cc ends here
