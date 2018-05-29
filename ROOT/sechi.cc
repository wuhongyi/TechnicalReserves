// sechi.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 5月 18 14:50:14 2014 (+0800)
// Last-Updated: 日 5月 18 15:52:03 2014 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 41
// URL: http://wuhongyi.cn 

#include "TCanvas.h"
#include "TPad.h"
#include "TPaveLabel.h"
#include "TLatex.h"
#include "TGraph.h"
#include "TFrame.h"

int sechi()
{
  TCanvas *c1 = new TCanvas("c1","Harbin Engineering University",10,40,800,600);
  //c1->SetFillColor(40);


  TPaveLabel *pl = new TPaveLabel(1,16.3,24,17.5,"Z-scaling of \
     Direct Photon Productions in pp Collisions at RHIC Energies","br");
  pl->SetFillColor(18);
  pl->SetTextFont(32);
  //pl->SetTextColor(49);
  pl->Draw();

  TLatex *t = new TLatex();
  t->SetTextFont(32);
  t->SetTextColor(1);
  t->SetTextSize(0.1);
  t->SetTextAlign(12);
  t->DrawLatex(0.0,10,"Hongyi Wu @ Harbin Engineering University ");
  t->DrawLatex(5.,20,"JINR preprint E2-98-64, Dubna, 1998 ");

   TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.48,0.83,22);
   TPad *pad2 = new TPad("pad2","This is pad2",0.52,0.02,0.98,0.83,33);

   pad1->Draw();
   pad2->Draw();

   //===================================

   pad1->cd();
   pad1->SetLogx();
   pad1->SetLogy();
   //pad1->GetFrame()->SetFillColor(19);
   t = new TLatex();
   t->SetTextFont(62);
   t->SetTextColor(36);
   t->SetTextSize(0.08);
   t->SetTextAlign(12);
   t->DrawLatex(0.6,0.85,"p - p");

   t->SetTextSize(0.05);
   t->DrawLatex(0.6,0.79,"Direct #gamma");
   t->DrawLatex(0.6,0.75,"#theta = 90^{o}");

   t->DrawLatex(0.20,0.45,"Ed^{3}#sigma/dq^{3}");
   t->DrawLatex(0.18,0.40,"(barn/Gev^{2})");

   t->SetTextSize(0.045);
   t->SetTextColor(kBlue);
   t->DrawLatex(0.22,0.260,"#sqrt{s} = 63(GeV)");
   t->SetTextColor(kRed);
   t->DrawLatex(0.22,0.205,"#sqrt{s} = 200(GeV)");
   t->SetTextColor(6);
   t->DrawLatex(0.22,0.15,"#sqrt{s} = 500(GeV)");

   t->SetTextSize(0.05);
   t->SetTextColor(1);
   t->DrawLatex(0.6,0.06,"q_{T} (Gev/c)");

  TH2F *h1 = new TH2F("h1","test1",10,0,1,20,0,20);
  gPad->SetTickx(2);
  gPad->SetTicky(2);
  h1->Draw();

   c1->Modified();
   c1->Update();
  return 0;
}
// 
// sechi.cc ends here
