// testtime.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 四 1月 29 20:14:03 2015 (+0800)
// Last-Updated: 二 2月  3 18:41:10 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 10
// URL: http://wuhongyi.cn 

void testtime()
{
  gBenchmark->Start("client");
  TFile *f;
  TTree *t;
  f=new TFile("randomtest.root","RECREATE");
  t=new TTree("NameOfTree","title:a list of random and numbers");

  double num;
  double random;
  t->Branch("NameOfBranch1",&num,"number/D");
  t->Branch("NameOfBranch2",&random,"random/D");
  gRandom->SetSeed();
  const int kUPDATE = 100000;
  for (long long i=1; i<=10000000; ++i)
    {
      num=i;
      random=gRandom->Uniform();
      t->Fill();
      if ((i%kUPDATE) == 0)
	{
	  t->Write();
	  //t->Reset();
	  // mess.Reset();              // re-use TMessage object
	  // mess.WriteObject(t);     // write object in message buffer
	  // sock->Send(mess);          // send message
	}
    }
  t->Write();

  if(f->IsOpen()) f->Close();

  gBenchmark->Show("client");

}
// 
// testtime.cc ends here
