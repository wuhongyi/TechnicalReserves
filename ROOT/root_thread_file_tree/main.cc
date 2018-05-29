// main.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 5月  3 20:33:35 2015 (+0800)
// Last-Updated: 日 5月  3 20:34:04 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 


int main(int argc, char *argv[])
{
  
   TFile f("ht.root","recreate");
   TTree *T     = new TTree("T","test");
   TH1F *hpx    = new TH1F("hpx","This is the px distribution",100,-4,4);
   TH2F *hpxpy  = new TH2F("hpxpy","py vs px",40,-4,4,40,-4,4);
   TProfile *hprof  = new TProfile("hprof","Profile of pz versus px",100,-4,4,0,20);
   T->Branch("hpx","TH1F",&hpx,32000,0);
   T->Branch("hpxpy","TH2F",&hpxpy,32000,0);
   T->Branch("hprof","TProfile",&hprof,32000,0);
   Float_t px, py, pz;
   for (Int_t i = 0; i < 25000; i++) {
      if (i%1000 == 0) printf("at entry: %d\n",i);
      gRandom->Rannor(px,py);
      pz = px*px + py*py;
      hpx->Fill(px);
      hpxpy->Fill(px,py);
      hprof->Fill(px,pz);
      T->Fill();
   }
   T->Print();
   f.Write();


  return 0;
}


// 
// main.cc ends here
