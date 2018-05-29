// orig.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 一 3月 12 10:28:42 2018 (+0800)
// Last-Updated: 一 3月 12 10:45:51 2018 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

{
  TFile *f = new TFile("test.root","RECREATE","PKU ROOT FILE");//"RECREATE" "READ"
  if(!f->IsOpen())
    {
      std::cout<<"Can't open root file"<<std::endl;
    }

  TTree *t = new TTree("t","Hongyi Wu Data");
  // TTree *t = (TTree*)rootfile->Get(""t"");
  
  int evt;
  double data;

  t->Branch("evt",&evt,"evt/I");
  t->Branch("data",&data,"data/D");
  
  // Branch
  // int mhit;
  // int hitdata[1024];
  // t->Branch("mhit",&mhit,"mhit/I");
  // t->Branch("hitdata",&hitdata,"hitdata[mhit]/I");

  for (int i = 0; i < 100; ++i)
    {
      evt = i;
      data = 2.0*i;
      t->Fill();//loop
    }
  
  
  t->Write();
  
  // t->GetEntries();//获取entry数
  // t->Print("");// "all" friend trees are also printed. "toponly" only the top level branches are printed. "clusters" information about the cluster of baskets is printed.    T.Print("xxx*") will print all branches with name starting with "xxx".
  
  
  // Event *event = 0;  //event must be null or point to a valid object it must be initialized
  // t->SetBranchAddress("event",&event);
  // t->GetEntry( /*int*/);




  
  // f->ls("");
  // TObject->Write();
  // TH1D *h = (TH1D*)f->Get("name");
  f->Close();

}
// 
// orig.cc ends here
