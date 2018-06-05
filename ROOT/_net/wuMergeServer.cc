// wuMergeServer.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 五 1月 30 14:13:15 2015 (+0800)
// Last-Updated: 五 1月 30 19:37:18 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 15
// URL: http://wuhongyi.cn 

void wuMergeServer()
{
  TServerSocket *ss = new TServerSocket(9090, kTRUE);
  if (!ss->IsValid()) {
    return;
  }

  TMonitor *mon = new TMonitor;
  mon->Add(ss);

  UInt_t clientCount = 0;
  TMemFile *transient = 0;

   TFileMerger merger(kFALSE,kFALSE);
   merger.SetPrintLevel(0);


  while (1)
    {
      TMessage *mess;
      TSocket  *s;

      s = mon->Select();
      if (s->IsA() == TServerSocket::Class())
	{
	  TSocket *client = ((TServerSocket *)s)->Accept();
	  client->Send(clientCount, 0);
	  ++clientCount;
	  cout<<clientCount<<endl;

	  mon->Add(client);
	  printf("Accept %d connections\n",clientCount);

	  continue;
	}

      s->Recv(mess);

      if (mess==0) 
	{
	  Error("fastMergeServer","The client did not send a message\n");
	}
      else if (mess->What() == kMESS_STRING) 
	    {
	      char str[64];
	      mess->ReadString(str, 64);
	      printf("Client %d: %s\n", clientCount, str);
	      mon->Remove(s);
	      printf("Client %d: bytes recv = %d, bytes sent = %d\n", clientCount, s->GetBytesRecv(),s->GetBytesSent());
	      s->Close();
	      --clientCount;
	      // if (mon->GetActive() == 0 || clientCount == 0)
	      // 	{
	      // 	  printf("No more active clients... stopping\n");
	      // 	  break;
	      // 	}
	    }
      else if (mess->What() == kMESS_ANY) 
            {
	      Long64_t length;
	      TString filename;
	      Int_t clientId;
	      mess->ReadInt(clientId);
	      mess->ReadTString(filename);
	      mess->ReadLong64(length);

	      Info("fastMergeServer","Receive input from client %d for %s",clientId,filename.Data());
         
	      delete transient;
	      transient = new TMemFile(filename,mess->Buffer() + mess->Length(),length);
	      mess->SetBufferOffset(mess->Length()+length);
	      merger.OutputFile(filename);
	      merger.AddAdoptFile(transient);

	      merger.PartialMerge(TFileMerger::kAllIncremental);
	      transient = 0;
	    }













      delete mess;
    }








}

// 
// wuMergeServer.cc ends here
