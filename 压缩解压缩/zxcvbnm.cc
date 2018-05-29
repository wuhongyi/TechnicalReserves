// zxcvbnm.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 六 6月 28 13:15:12 2014 (+0800)
// Last-Updated: 五 11月 13 12:20:12 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 9
// URL: http://wuhongyi.cn 

// g++ zxcvbnm.cc -lz -o 123
#include <iostream>
#include <zlib.h>
#include <zconf.h>
#include <stdio.h>
#include <string>
#include <cstring>
 
using namespace std;
int main(int argc, char *argv[])
{
  /* 原始数据 */  
  unsigned char strSrc[] = "hello world! aaaaa bbbbb ccccc ddddd 中文测试 yes";  
  unsigned char buf[1024] = {0};  
  unsigned char strDst[1024] = {0};  
  unsigned long srcLen = sizeof(strSrc);//原始数据长度  
  unsigned long bufLen = sizeof(buf);//压缩后长度  
  unsigned long dstLen = sizeof(strDst);//解压缩后长度  
      
  printf("Src string:%s\nLength:%ld\n", strSrc, srcLen);  
        
  /* 压缩 */  
  compress(buf, &bufLen, strSrc, srcLen);  
  printf("After Compressed Length:%ld\n", bufLen);//压缩后长度  
      
  /* 解压缩 */  
  uncompress(strDst, &dstLen, buf, bufLen);  
  printf("After UnCompressed Length:%ld\n",dstLen);  
      
  printf("UnCompressed String:%s\n",strDst);  
        
  string aaa="zdsddf.z";
  string bbb=".z";
  cout<<aaa+bbb<<endl;
  return 0;
}

// 
// zxcvbnm.cc ends here
