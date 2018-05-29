// hardsize.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 四 4月 26 20:58:03 2018 (+0800)
// Last-Updated: 四 4月 26 21:17:51 2018 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 5
// URL: http://wuhongyi.cn 

{
  // TString ss = gSystem->GetFromPipe("df -hl /home/wuhongyi/data/");
  TString ss1 = gSystem->GetFromPipe("df -hl /home/wuhongyi/data/ | awk 'NR>1{print $3}'");
  TString ss2 = gSystem->GetFromPipe("df -hl /home/wuhongyi/data/ | awk 'NR>1{print $4}'");
  TString ss3 = gSystem->GetFromPipe("df -hl /home/wuhongyi/data/ | awk 'NR>1{print $5}'");
  std::cout<<ss1<<std::endl;
  std::cout<<ss2<<std::endl;
  std::cout<<ss3<<std::endl;
}

// 
// hardsize.cc ends here















