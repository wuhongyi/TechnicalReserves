// graph.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 四 5月 26 15:26:24 2016 (+0800)
// Last-Updated: 四 5月 26 19:01:10 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 33
// URL: http://wuhongyi.cn 

#include "TCanvas.h"
#include "TPad.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TBranch.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TF1.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TMath.h"
#include "TRandom.h"
#include "TBenchmark.h"
#include "TString.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TSystem.h"
#include "TVirtualFitter.h"

#include <iostream>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

TGraph *g;


void myFCN(Int_t &, Double_t *, Double_t &f, Double_t *par, Int_t)
{
   Int_t np = g->GetN();
   f = 0;
   Double_t *x = g->GetX();
   Double_t *y = g->GetY();

   for (Int_t i=0;i<np;i++)
     {
       Double_t dr = (y[i]-(par[0]+par[1]*x[i]))/y[i];//  
       f += dr*dr;
     }
}

   

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

int graph()
{
  Double_t x[10] = {1,4,13,27,46,51,69,74,88,92};
  Double_t y[10] = {101,445,1301,2789,4600,5165,6889,7421,8856,9264};

  TCanvas *c1 = new TCanvas("c1","",600,400);
  // gStyle->SetOptStat(0);

  g = new TGraph(10,x,y);
  g->Draw("AP*");


  TVirtualFitter::SetDefaultFitter("Minuit");  //default is Minuit
  TVirtualFitter *fitter = TVirtualFitter::Fitter(0,2);
  fitter->SetFCN(myFCN);

  fitter->SetParameter(0, "b",   10, 0.1, 0,0);
  fitter->SetParameter(1, "k",   50, 0.1, 0,0);

  Double_t arglist[2];
  arglist[0] = 5000; // number of function calls
  arglist[1] = 0.01; // tolerance
  fitter->ExecuteCommand("MIGRAD", arglist, 2);// MIGRAD SIMPLEX SCAN Combination

  std::cout<<fitter->GetParameter(0)<<" "<<fitter->GetParameter(1)<<std::endl;

    //get result
    double minParams[10];
    double parErrors[10];
    for (int i = 0; i < 2; ++i)
      {
      minParams[i] = fitter->GetParameter(i);
      parErrors[i] = fitter->GetParError(i);
    }
    double chi2, edm, errdef;
    int nvpar, nparx;
    fitter->GetStats(chi2,edm,errdef,nvpar,nparx);
    
  return 0;
}
 

// 
// graph.cc ends here












