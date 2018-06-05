// wuServer.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 四 1月 29 16:52:09 2015 (+0800)
// Last-Updated: 二 2月  3 20:19:03 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 40
// URL: http://wuhongyi.cn 

void wuServer()
{
  // Open a server socket looking for connections on a named service or on a specified port.
  TServerSocket *ss = new TServerSocket(1991, kTRUE);

  // Accept a connection and return a full-duplex communication socket.
  TSocket *s0 = ss->Accept();

  // tell the clients to start
  s0->Send("go 0");

  // Check some options of socket 0.
  int val;
  s0->GetOption(kSendBuffer, val);
  printf("sendbuffer size: %d\n", val);
  s0->GetOption(kRecvBuffer, val);
  printf("recvbuffer size: %d\n", val);


  // Get the remote addresses (informational only).
  TInetAddress adr = s0->GetInetAddress();
  adr.Print();

  TMonitor *mon = new TMonitor;
  mon->Add(s0);


  TFile *f;
  TTree *t;
  f=new TFile("random.root","RECREATE");
  t=new TTree("NameOfTree","title:a list of random and numbers");

   // Declaration of leaf types
   Double_t        NameOfBranch1;
   Double_t        NameOfBranch2;

   // List of branches
   TBranch        *b_number;   //!
   TBranch        *b_random;   //!

  t->Branch("NameOfBranch1",&NameOfBranch1,"number/D");
  t->Branch("NameOfBranch2",&NameOfBranch2,"random/D");

  while(1)
    {
      TMessage *mess;
      TSocket  *s;

      s = mon->Select();
      s->Recv(mess);
      
      if (mess->What() == kMESS_STRING) {
	char str[64];
	mess->ReadString(str, 64);
	cout<<str<<endl;
	mon->Remove(s);
	if (mon->GetActive() == 0) {

	  t->Write();//!!!!!
	  printf("No more active clients... stopping\n");
	  break;
	}
      }
      else if (mess->What() == kMESS_OBJECT)
	    {
	      TTree* h = (TTree *)mess->ReadObject(mess->GetClass());

	      if (h) {
	      	cout<<h->GetEntries()<<endl;
		h->SetBranchAddress("NameOfBranch1", &NameOfBranch1, &b_number);
		h->SetBranchAddress("NameOfBranch2", &NameOfBranch2, &b_random);
		for (long i=0; i<h->GetEntries(); ++i)
		  {
		    b_number->GetEntry(i);
		    b_random->GetEntry(i);
		    t->Fill();
		  }
		//t->Write();
	      	delete h;
	      }

       	    } 
          else 
	    {
	      printf("*** Unexpected message ***\n");
            }
      delete mess;
    }

  if(f->IsOpen()) f->Close();

  // Close the server socket (unless we will use it later to wait for another connection).
  ss->Close();

  // Close the socket.
  s0->Close();


}

// 
// wuServer.cc ends here
