// main.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 3月 22 20:15:15 2015 (+0800)
// Last-Updated: 五 6月  5 09:45:40 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 58
// URL: http://wuhongyi.cn 

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include "TCanvas.h"
#include "TBenchmark.h"
#include "TRandom.h"
#include "TFile.h"
#include "TRint.h"
#include "TObject.h"
#include "TFile.h"
#include "TROOT.h"
#include "TVirtualPad.h"
#include "TH1.h"
#include "TH2.h"
#include "TF1.h"
using namespace std;
int main(int argc, char *argv[])
{
  TRint *theApp = new TRint("Rint", &argc, argv);

  TCanvas* c1=new TCanvas("c1","");
  TH2D* h=new TH2D("h","",8,-4,4,4,-2,2);

  int count=0;
  int sum=0;
  for (int i = 1; i<9; ++i)
    for (int j = 1; j<5; ++j)
      {
	count++;
	sum+=count;
	h->SetBinContent(i,j,count);
	cout<<"("<<i<<","<<j<<")  "<<h->GetBinContent(i,j)<<endl;
      }
  cout<<"MaxValue:"<<h->GetBinContent(h->GetMaximumBin())<<endl;

  //   int i,j;
  // for (int k=0; k<32; ++k)
  //   {
  //     i=k/8;j=k%8;
  //     count++;
  //     sum+=count;
  //     h->SetBinContent((j+1),(4-i),count);
  //     cout<<"("<<i<<","<<j<<")  ("<<j-4<<","<<2-i<<")   ("<<j+1<<","<<4-i<<")"<<endl;
  //   }

  h->Draw("lego");
  // h->Draw("");
  cout<<"sum:"<<sum<<endl;
  cout<<h->Integral(3,6,2,3)<<endl;
  cout<<h->Integral()<<endl;//积分

  cout<<h->ShowPeaks(4, "", 0.1)<<endl;

  double x,y;
  for (int i = 0; i<15; ++i)
    {
      h->GetRandom2(x,y);
      cout<<x<<"  "<<y<<endl;
    }

  cout<<"GetCovariance:"<<h->GetCovariance(1,2)<<endl;


  cout<<"GetBin:"<<h->GetBin(2,2)<<endl;
  cout<<"GetBinContent:"<<h->GetBinContent(h->GetBin(2,2))<<endl;

 TH1D* px;
 TH1D* py;

 px=h->ProjectionX();
 py=h->ProjectionY();


 h->Reset();

 // and enter the event loop...
 theApp->Run();
 delete theApp;

  return 0;
}

// 
// main.cc ends here





