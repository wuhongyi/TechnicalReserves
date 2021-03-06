// wuhttp.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 六 3月 12 20:38:46 2016 (+0800)
// Last-Updated: 六 3月 12 21:20:44 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 5
// URL: http://wuhongyi.cn 

#include "TH1.h"
#include "TH2.h"
#include "TRandom3.h"
#include "TSystem.h"
#include "THttpServer.h"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//  Authentication file auth.txt was generated with following shell commands:
//    [shell]  htdigest -c auth.txt root guest
//          typing <empty> password for guest account
//    [shell]  htdigest auth.txt root admin
//          typing 'admin' as password for admin account
//  When macro started and opening in browser with url
//      http://localhost:8080
//  User name and password will be requested. One should
//  either specify guest account without password or
//  admin account with password 'admin'
//
//  User with guest account only can monitor histograms
//  User with admin account see commands, which can be executed

void wuhttp()
{

  // create histograms
  TH1D *hpx = new TH1D("hpx","This is the px distribution",100,-4,4);
  hpx->SetFillColor(48);
  hpx->SetDirectory(0);
  TH2D *hpxpy = new TH2D("hpxpy","py vs px",40,-4,4,40,-4,4);
  hpxpy->SetDirectory(0);

   if (gSystem->AccessPathName("auth.txt")!=0) {
      printf("Please start macro from directory where auth.txt file is available\n");
      printf("It required to supply authentication information for the http server\n");
      return;
   }

   // start http server
   THttpServer* serv = new THttpServer("http:8080?auth_file=auth.txt&auth_domain=root");//http:8080

   // enable monitoring and
   // specify items to draw when page is opened
   serv->SetItemField("/","_monitoring","5000");
   serv->SetItemField("/","_layout","tabs");
   // serv->SetItemField("/","_drawitem","[hpxpy,hpx,Debug]");
   // serv->SetItemField("/","_drawopt","col");



   // register histograms
   serv->Register("/", hpx);
   serv->Register("/", hpxpy);


   // register commands, invoking object methods
   serv->RegisterCommand("/ResetHPX","/hpx/->Reset();", "button;rootsys/icons/ed_delete.png");
   serv->RegisterCommand("/ResetHPXPY","/hpxpy/->Reset();", "button;rootsys/icons/bld_delete.png");
   serv->RegisterCommand("/RebinHPX","/hpx/->Rebin(%arg1%);", "button;rootsys/icons/ed_execute.png");

   serv->RegisterCommand("/ExitRoot","gSystem->Exit(1);", "rootsys/icons/ed_delete.png");

   // these two commands fully hidden for other accounts,
   // only admin can see and execute these commands
   serv->Restrict("/ResetHPX",  "visible=admin");
   serv->Restrict("/ResetHPXPY", "visible=admin");

   // this command visible for other, but will be refused (return false)
   // when executed from any other account
   serv->Restrict("/RebinHPX", "allow=admin");

   // Fill histograms randomly
   TRandom3 random;
   Float_t px, py;
   const Long_t kUPDATE = 1000;
   Long_t cnt = 0;
   while (kTRUE) {
      random.Rannor(px,py);
      hpx->Fill(px);
      hpxpy->Fill(px,py);

      // IMPORTANT: one should regularly call ProcessEvents
      if (cnt++ % kUPDATE == 0) {
         if (gSystem->ProcessEvents()) break;
      }
   }

}


// 
// wuhttp.cc ends here
