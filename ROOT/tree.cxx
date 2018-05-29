#include<iostream>
#include<ctime>
using namespace std;
struct ChlData
{
  bool sIsWrite;
  short sData;
};

int tree()
{
  time_t stime , etime ;
  time( &stime );

  ChlData DataReg[16];
  double num;
  double random;
  TFile *f;
  TTree *t;
  f=0;t=0;
  f=new TFile("random.root","RECREATE");
  t=new TTree("NameOfTree","title:a list of random and numbers");
  // t->Branch("NameOfBranch1",&num,"number/D");
  // t->Branch("NameOfBranch2",&random,"random/D");
  char name[10];
  for (int k = 0; k<16; ++k)
    {
      sprintf(name,"channal%d",k); 
      t->Branch(name,&DataReg[k].sData,"channal/S");
    }
  // t->Branch("channal0",&DataReg[0].sData,"channal/S");
  // t->Branch("channal1",&DataReg[1].sData,"channal/S");
  // t->Branch("channal2",&DataReg[2].sData,"channal/S");
  // t->Branch("channal3",&DataReg[3].sData,"channal/S");
  // t->Branch("channal4",&DataReg[4].sData,"channal/S");
  // t->Branch("channal5",&DataReg[5].sData,"channal/S");
  // t->Branch("channal6",&DataReg[6].sData,"channal/S");
  // t->Branch("channal7",&DataReg[7].sData,"channal/S");
  // t->Branch("channal8",&DataReg[8].sData,"channal/S");
  // t->Branch("channal9",&DataReg[9].sData,"channal/S");
  // t->Branch("channal10",&DataReg[10].sData,"channal/S");
  // t->Branch("channal11",&DataReg[11].sData,"channal/S");
  // t->Branch("channal12",&DataReg[12].sData,"channal/S");
  // t->Branch("channal13",&DataReg[13].sData,"channal/S");
  // t->Branch("channal14",&DataReg[14].sData,"channal/S");
  // t->Branch("channal15",&DataReg[15].sData,"channal/S");
  t->SetMaxTreeSize(10485760);
  for(long i=0;i<1000000;i++)
    {
      // num=i;
      // random=gRandom->Rndm();
      for (int k = 0; k < 16; ++k)
	{
	  DataReg[k].sIsWrite = false;
	  DataReg[k].sData =100*gRandom->Rndm();
	}
      t->Fill();
      //if(i%100000==0) {cout<<f->GetSize()<<endl;}
    }
  t->Write();
  //f->Write();
  //f->Close();
  //if(f->IsOpen())f->Close();
  cout<<f->IsOpen()<<endl;
  f->Close();
  cout<<"~~~~~~~~~~~~~~~~~"<<endl;

  // if(t!=0) t=0;
  // if(f!=0) f=0;


  time( &etime ); /* get end time */
  cout<<etime - stime<<endl;
  return 0;
}
