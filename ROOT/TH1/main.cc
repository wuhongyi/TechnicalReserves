// main.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 四 6月 11 14:27:39 2015 (+0800)
// Last-Updated: 五 4月  8 14:11:54 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 84
// URL: http://wuhongyi.cn 

// #include "TRint.h"
// #include "TObject.h"
// #include "TApplication.h"
// #include "TH1D.h"
// #include "TRandom.h"

// int main(int argc, char **argv)
{
  // Create an interactive ROOT application
  // TRint *theApp = new TRint("Rint", &argc, argv);

  int bin=60;
  TH1D *h=new TH1D("h","the title",bin,-3.0,3.0);
  TRandom *r =new TRandom();
  for (int i = 0; i<100000; ++i)
    {
      h->Fill(r->Gaus());
    }
  h->LabelsDeflate("X");
  h->LabelsDeflate("Y");
  // std::cout<<h->IsBinOverflow(30)<<std::endl;
  // std::cout<<h->IsBinUnderflow(30)<<std::endl;

  // h->SetBins(10,-3.0,3.0);
  h=(TH1D *)h->RebinX(2,"hh");
  
  h->Draw();


  // int bin=20;
  // TH2D *h =new TH2D("h","the title",bin,-1.0,1.0,bin,-1.0,1.0);
  // TRandom *r =new TRandom();
  // for (int i = 0; i<1000; ++i)
  //   {
  //     h->Fill(r->Gaus(),r->Gaus());
  //   }
  // // int binx,biny;
  // // h->GetBinXYZ(h->GetBin(10,10),binx,biny);
  // // cout<<"binx:"<<binx<<"  biny:"<<biny<<std::endl;
  // std::cout<<h->GetNcells()<<std::endl;
  // h->Draw();



  // double *Integral;
  // Integral=h->GetIntegral();
  // for (int i = 0; i<bin; ++i)
  //   {
  //     std::cout<<i<<"  "<<Integral[i]<<std::endl;
  //   }

  // and enter the event loop...
  // theApp->Run();

  // delete theApp;
  // return 0;
}


// 
// main.cc ends here








