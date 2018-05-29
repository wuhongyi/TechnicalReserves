// wuMergeClient.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 五 1月 30 14:13:01 2015 (+0800)
// Last-Updated: 五 1月 30 19:42:01 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 17
// URL: http://wuhongyi.cn 

void wuMergeClient()
{
  gBenchmark->Start("Client");

  // Open connection to server
  TSocket *sock = new TSocket("localhost", 9090);
  if (!sock->IsValid()) {
    Error("Client","Could not establish a connection with the server %s:%d.","localhost",9090);
    return;
  }


  Int_t status, kind;
  sock->Recv(status, kind);
  cout<<"status: "<<status<<"  kind: "<<kind<<endl;



  TMemFile *file = new TMemFile("mergedClient.root","RECREATE");
  //TH1 *hpx;
  //hpx = new TH2F("hpxpy","py vs px",40,-4,4,40,-4,4);
  Float_t px, py;
  TTree *tree = new TTree("tree","tree");
  tree->SetAutoFlush(4000000);
  tree->Branch("px",&px);
  tree->Branch("py",&py);

  TMessage::EnableSchemaEvolutionForAll(kTRUE);
  TMessage mess(kMESS_OBJECT);

  // Fill histogram randomly
  gRandom->SetSeed();
  const int kUPDATE = 100000;
  for (int i = 0; i < 2500000; )
    {
      gRandom->Rannor(px,py);
      //hpx->Fill(px,py);
      tree->Fill();
      ++i;
      if (i && (i%kUPDATE) == 0)
	{
	  file->Write();
	  mess.Reset(kMESS_ANY);              // re-use TMessage object
	  mess.WriteInt(status);
	  mess.WriteTString(file->GetName());
	  mess.WriteLong64(file->GetEND()); 
	  //cout<<file->GetEND()<<endl;
	  file->CopyTo(mess);
	  sock->Send(mess);          // send message
         
	  file->ResetAfterMerge(0);  // This resets only the TTree objects.
	  //hpx->Reset();
	}
    }
  sock->Send("Finished");          // tell server we are finished




  gBenchmark->Show("Client");
}

// 
// wuMergeClient.cc ends here
