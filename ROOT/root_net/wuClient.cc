// wuClient.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 四 1月 29 16:52:21 2015 (+0800)
// Last-Updated: 二 2月  3 19:25:57 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 30
// URL: http://wuhongyi.cn 

void wuClient()
{
  gBenchmark->Start("client");

  // Open connection to server
  TSocket *sock = new TSocket("localhost", 1991);

  // Wait till we get the start message
  char str[32];
  sock->Recv(str, 32);
  cout<<str<<endl;
  //sock->SetCompressionLevel(1);

  TMessage::EnableSchemaEvolutionForAll(kTRUE);
  TMessage mess(kMESS_OBJECT);

  TTree* t;
  t=new TTree("NameOfTree","title:a list of random and numbers");
  double num;
  double random;
  t->Branch("NameOfBranch1",&num,"number/D");
  t->Branch("NameOfBranch2",&random,"random/D");

  gRandom->SetSeed();
  const int kUPDATE = 10000;
  for (long long i=1; i<=100000; ++i)
    {
      num=i;
      random=gRandom->Uniform();
      t->Fill();
      if ((i%kUPDATE) == 0)
	{
	  mess.Reset();              // re-use TMessage object
	  mess.WriteObject(t);     // write object in message buffer
	  sock->Send(mess);          // send message
	  t->Reset();
	}
    }

  sock->Send("Finished");          // tell server we are finished
  cout<<"ending!"<<endl;

  // Close the socket
  sock->Close();

  gBenchmark->Show("client");
}

// 
// wuClient.cc ends here
