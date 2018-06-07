// main.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 三 6月  6 02:28:27 2018 (+0800)
// Last-Updated: 三 6月  6 20:59:10 2018 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 25
// URL: http://wuhongyi.cn 

#include "RVersion.h"//版本判断
#include "TApplication.h"
#include "TArrow.h"
#include "TAxis.h"
#include "TBenchmark.h"
#include "TBranch.h"
#include "TBrowser.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TColor.h"
#include "TCutG.h"
#include "TDatime.h"
#include "TDirectory.h"
#include "TDirectoryFile.h"
#include "TError.h"
#include "TF1.h"
#include "TF2.h"
#include "TFile.h"
#include "TFitResult.h"
#include "TFormula.h"
#include "TGaxis.h"
#include "TGraph.h"
#include "TGraph2D.h"
#include "TGraphErrors.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "THStack.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TLine.h"
#include "TList.h"
#include "TLorentzVector.h"
#include "TMarker.h"
#include "TMath.h"
#include "TMatrixD.h"
#include "TMatrixDEigen.h"
#include "TMultiGraph.h"
#include "TNtuple.h"
#include "TObject.h"
#include "TPad.h"
#include "TPaveLabel.h"
#include "TPaveStats.h"
#include "TPaveText.h"
#include "TRandom.h"
#include "TRandom1.h"
#include "TRandom2.h"
#include "TRandom3.h"
#include "TRint.h"
#include "TROOT.h"
#include "TSlider.h"
#include "TSpectrum.h"
#include "TSpectrum2.h"
#include "TStopwatch.h"
#include "TString.h"
#include "TStyle.h"
#include "TSystem.h"
#include "TTimer.h"
#include "TTimeStamp.h"
#include "TTree.h"
#include "TVector3.h"
#include "TVectorD.h"

#include "THttpServer.h"
#include "TMemFile.h"//reads and writes only from memory.
#include "TProfile.h"
#include "TFrame.h"



// #define NDEBUG
#include <algorithm>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

int main(int argc, char *argv[])
{
  // Create an interactive ROOT application
  TRint *theApp = new TRint("Rint", &argc, argv);

  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  
  // // Create two histograms
  // TH1F *hpx = new TH1F("hpx","This is the px distribution",100,-4,4);
  // TH2F *hpxpy = new TH2F("hpxpy","py vs px",40,-4,4,40,-4,4);

  // // http server with port 8080, use jobname as top-folder name
  // THttpServer* serv = new THttpServer("http:8080");

  // // use custom web page as default
  // serv->SetDefaultPage("custom.htm");

  // // Fill histograms randomly
  // TRandom3 random;
  // Float_t px, py;


  // while (!gSystem->ProcessEvents()) {
  //   random.Rannor(px,py);
  //   hpx->Fill(px);
  //   hpxpy->Fill(px,py);
  // }

  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  
  // auto serv = new THttpServer("http:8081");
  // auto h1 = new TH1F("h1", "histogram 1", 100, -5, 5);
  // auto c1 = new TCanvas("c1");
  // auto f1 = new TF1("f1", "gaus", -10, 10);

  // c1->cd();
  // h1->Draw();

  // while (!gSystem->ProcessEvents()) {
  //   h1->FillRandom("gaus", 100);
  //   h1->Fit(f1);
  //   c1->Modified();
  //   c1->Update();
  //   gSystem->Sleep(1000);
  // }

  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  // // create histograms
  // TH1D *hpx = new TH1D("hpx","This is the px distribution",100,-4,4);
  // hpx->SetFillColor(48);
  // hpx->SetDirectory(0);
  // TH2D *hpxpy = new TH2D("hpxpy","py vs px",40,-4,4,40,-4,4);
  // hpxpy->SetDirectory(0);

  // if (gSystem->AccessPathName("auth.txt") != 0)
  //   {
  //    printf("Please start macro from directory where auth.txt file is available\n");
  //    printf("It required to supply authentication information for the http server\n");
  //    return 1;
  // }

  // // start http server
  // THttpServer* serv = new THttpServer("http:8080?auth_file=auth.txt&auth_domain=root");

  // // or start FastCGI server, where host server (like Apache or lighttpd) should enable own authentication
  // // for apache one should add correspondent module and authentication for fastcgi location
  // // for lighttpd one add following lines to configuration file:
  // //   server.modules += ( "mod_auth" )
  // //   auth.backend = "htdigest"
  // //   auth.backend.htdigest.userfile = "/srv/auth/auth.txt"
  // //   auth.require = ( "/root.app" => ( "method" => "digest", "realm" => "root", "require" => "valid-user" ))
  // // THttpServer* serv = new THttpServer("fastcgi:9000");

  // // One could specify location of newer version of JSROOT
  // // serv->SetJSROOT("https://root.cern.ch/js/latest/");
  // // serv->SetJSROOT("http://jsroot.gsi.de/latest/");


   
  // // register histograms
  // serv->Register("/", hpx);
  // serv->Register("/", hpxpy);

  // // register commands, invoking object methods
  // serv->RegisterCommand("/ResetHPX","/hpx/->Reset();", "button;rootsys/icons/ed_delete.png");
  // serv->SetItemField("/ResetHPX","_update_item", "hpx"); // let browser update histogram view after commands execution
  // serv->RegisterCommand("/ResetHPXPY","/hpxpy/->Reset();", "button;rootsys/icons/bld_delete.png");
  // serv->SetItemField("/ResetHPXPY","_update_item", "hpxpy"); // let browser update histogram view after commands execution
  // // here also example how command with arguments can be invoked
  // serv->RegisterCommand("/RebinHPX","/hpx/->Rebin(%arg1%);", "button;rootsys/icons/ed_execute.png");
  // serv->SetItemField("/RebinHPX","_update_item", "hpx"); // let browser update histogram view after commands execution

  // // these two commands fully hidden for other accounts,
  // // only admin can see and execute these commands
  // serv->Restrict("/ResetHPX",  "visible=admin");
  // serv->Restrict("/ResetHPXPY", "visible=admin");

  // // this command visible for other, but will be refused (return false)
  // // when executed from any other account
  // serv->Restrict("/RebinHPX", "allow=admin");

  // // Fill histograms randomly
  // TRandom3 random;
  // Float_t px, py;
  // const Long_t kUPDATE = 1000;
  // Long_t cnt = 0;
  // while (kTRUE)
  //   {
  //     random.Rannor(px,py);
  //     hpx->Fill(px);
  //     hpxpy->Fill(px,py);

  //     // IMPORTANT: one should regularly call ProcessEvents
  //     if (cnt++ % kUPDATE == 0)
  // 	 {
  // 	   if (gSystem->ProcessEvents()) break;
  // 	 }
  //   }  

  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  // const char* jobname = "job1";
  // Long64_t maxcnt = 0;
  // TFile *hfile = new TMemFile("test.root","RECREATE","Demo ROOT file with histograms");

  // // Create some histograms, a profile histogram and an ntuple
  // TH1F *hpx = new TH1F("hpx","This is the px distribution",100,-4,4);
  // hpx->SetFillColor(48);
  // TH2F *hpxpy = new TH2F("hpxpy","py vs px",40,-4,4,40,-4,4);
  // TProfile *hprof = new TProfile("hprof","Profile of pz versus px",100,-4,4,0,20);
  // TNtuple *ntuple = new TNtuple("ntuple","Demo ntuple","px:py:pz:random:i");
  // hfile->Write();


  // // http server with port 8080, use jobname as top-folder name
  // THttpServer* serv = new THttpServer(Form("http:8080?top=%s", jobname));

  // // fastcgi server with port 9000, use jobname as top-folder name
  // // THttpServer* serv = new THttpServer(Form("fastcgi:9000?top=%s_fastcgi", jobname));

  // // dabc agent, connects to DABC master_host:1237, works only when DABC configured
  // // THttpServer* serv = new THttpServer(Form("dabc:master_host:1237?top=%s_dabc", jobname));

  // // when read-only mode disabled one could execute object methods like TTree::Draw()
  // serv->SetReadOnly(kFALSE);

  // // One could specify location of newer version of JSROOT
  // // serv->SetJSROOT("https://root.cern.ch/js/latest/");
  // // serv->SetJSROOT("http://jsroot.gsi.de/latest/");

  // gBenchmark->Start(jobname);

  // // Create a new canvas.
  // TCanvas *c1 = new TCanvas("c1","Dynamic Filling Example",200,10,700,500);
  // c1->SetFillColor(42);
  // c1->GetFrame()->SetFillColor(21);
  // c1->GetFrame()->SetBorderSize(6);
  // c1->GetFrame()->SetBorderMode(-1);


  // // Fill histograms randomly
  // TRandom3 random;
  // Float_t px, py, pz;
  // const Int_t kUPDATE = 1000;
  // Long64_t i = 0;

  // while (true) {
  //   random.Rannor(px,py);
  //   pz = px*px + py*py;
  //   Float_t rnd = random.Rndm(1);
  //   hpx->Fill(px);
  //   hpxpy->Fill(px,py);
  //   hprof->Fill(px,pz);
  //   // fill only first 25000 events in NTuple
  //   if (i<25000) ntuple->Fill(px,py,pz,rnd,i);
  //   if (i && (i%kUPDATE) == 0) {
  //     if (i == kUPDATE) hpx->Draw();
  //     c1->Modified();
  //     c1->Update();
  //     if (i == kUPDATE) hfile->Write();

  //     if (gSystem->ProcessEvents()) break;
  //   }
  //   i++;
  //   if ((maxcnt>0) && (i>=maxcnt)) break;
  // }

  // gBenchmark->Show(jobname);
   
  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  Bool_t bFillHist = kTRUE;

  // create histograms
  TH1D *hpxww = new TH1D("hpx","This is the px distribution",100,-4,4);
  hpxww->SetFillColor(48);
  hpxww->SetDirectory(0);
  TH2D *hpxpyww = new TH2D("hpxpy","py vs px",40,-4,4,40,-4,4);
  hpxpyww->SetDirectory(0);

  // start http server
  THttpServer* serv = new THttpServer("http:8080");

  // One could specify location of newer version of JSROOT
  // serv->SetJSROOT("https://root.cern.ch/js/latest/");
  // serv->SetJSROOT("http://jsroot.gsi.de/latest/");

  // register histograms
  serv->Register("/test/", hpxww);
  serv->Register("/", hpxpyww);

  // enable monitoring and
  // specify items to draw when page is opened
  serv->SetItemField("/","_monitoring","5000");
  serv->SetItemField("/","_layout","grid2x2");
  serv->SetItemField("/","_drawitem","[hpxpy,hpx,Debug]");
  serv->SetItemField("/","_drawopt","col");

  // register simple start/stop commands
  serv->RegisterCommand("/Start", "bFillHist=kTRUE;", "button;rootsys/icons/ed_execute.png");
  serv->RegisterCommand("/Stop",  "bFillHist=kFALSE;", "button;rootsys/icons/ed_interrupt.png");

  // one could hide commands and let them appear only as buttons
  serv->Hide("/Start");
  serv->Hide("/Stop");

  // register commands, invoking object methods
  serv->RegisterCommand("/ResetHPX","/test/hpx/->Reset()", "button;rootsys/icons/ed_delete.png");
  serv->RegisterCommand("/ResetHPXPY","/hpxpy/->Reset()", "button;rootsys/icons/bld_delete.png");


  // create debug text element, use MathJax - works only on Firefox
  serv->CreateItem("/Debug","debug output");
  serv->SetItemField("/Debug", "_kind", "Text");
  serv->SetItemField("/Debug", "value","\\(\\displaystyle{x+1\\over y-1}\\)");
  serv->SetItemField("/Debug", "mathjax", "true");

  // Fill histograms randomly
  TRandom3 random;
  Float_t px, py;
  const Long_t kUPDATE = 1000;
  Long_t cnt = 0;
  while (kTRUE)
    {
      if (bFillHist)
	{
	  random.Rannor(px,py);
	  hpxww->Fill(px);
	  hpxpyww->Fill(px,py);
	  cnt++;
	} else
	{
	  gSystem->Sleep(10); // sleep minimal time
	}

      if ((cnt % kUPDATE==0) || !bFillHist)
	{
	  // IMPORTANT: one should regularly call ProcessEvents
	  // to let http server process requests

	  serv->SetItemField("/Debug", "value", Form("\\(\\displaystyle{x+1\\over y-1}\\) Loop:%ld", cnt/kUPDATE));

	  if (gSystem->ProcessEvents()) break;
	}
    }
  

  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
   
  // and enter the event loop...
  theApp->Run();
  delete theApp;

  return 0;
}

// 
// main.cc ends here
