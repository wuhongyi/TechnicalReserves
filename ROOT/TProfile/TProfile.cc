// TProfile.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 2月 15 21:57:55 2016 (+0800)
// Last-Updated: 四 3月 17 21:55:23 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 16
// URL: http://wuhongyi.cn 

#include "TH1.h"
#include "TH2.h"
#include "TCanvas.h"
#include "TRandom.h"
#include "TProfile.h"

#include <iostream>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
int TProfile()
{
  TCanvas *c1 = new TCanvas("c1","",800,600);

  TH2D *h = new TH2D("h","",100,-10,10,100,-10,10);
  
  int N = 100000;
  Double_t x,y;
  for (int i = 0; i < N; ++i)
    {
      x = gRandom->Uniform(-10, 10);//Gaus(0, 3);
      y = gRandom->Gaus(0, 1);
      h->Fill(x, y);
    }

  c1->cd();

  h->Draw();
  c1->SaveAs("h.pdf");
  c1->Clear();

  //每个slide的均值、方差
  TH1D *p = h->ProfileX();
  p->Draw();
  c1->SaveAs("p.pdf");
  c1->Clear();

  //error
  // TH1D *p;
  // h->ProfileX("p");
  // p->Draw();
  // c1->SaveAs("p.pdf");
  // c1->Clear();


  //每个slide直接投影下去
  TH1D *px = h->ProjectionX();
  px->Draw();
  c1->SaveAs("px.pdf");
  c1->Clear();

  return 0;
}


// 
// TProfile.cc ends here













