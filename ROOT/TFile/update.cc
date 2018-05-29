// update.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 3月 12 10:55:54 2018 (+0800)
// Last-Updated: 一 3月 12 11:07:59 2018 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 4
// URL: http://wuhongyi.cn 
{
  TFile *f = new TFile("test.root","UPDATE");//"RECREATE" "READ"
  if(!f->IsOpen())
    {
      std::cout<<"Can't open root file"<<std::endl;
    }

  TTree *t = (TTree*)f->Get("t");
  
  Int_t           evt;
  Double_t        data;

  TBranch        *b_evt;   //!
  TBranch        *b_data;   //!

  t->SetBranchAddress("evt", &evt, &b_evt);
  t->SetBranchAddress("data", &data, &b_data);


  Long64_t TotalEntry = t->GetEntries();//拿到TChain中总entry行数
  
  std::cout<<"TotalEntry:  "<<TotalEntry<<std::endl;

  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  for (Long64_t entry = 0; entry < TotalEntry; ++entry)
    {//循环处理从这里开始
      t->GetEvent(entry);//这个是重点，拿到TChain中第entry行数据

      data = evt*3.0;
      t->Fill();
    }//循环处理到这里结束
  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  
  t->Write("", TObject::kOverwrite); // save only the new version of the tree
  
  // f->ls("");
  // TObject->Write();
  // TH1D *h = (TH1D*)f->Get("name");
  f->Close();
}
// 
// update.cc ends here
