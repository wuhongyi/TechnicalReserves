// WriteObject.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 五 5月  1 19:12:40 2015 (+0800)
// Last-Updated: 日 5月  3 20:52:13 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 70
// URL: http://wuhongyi.cn 

#include "TThread.h"
#include <Riostream.h>

#include "TROOT.h"
#include "TFile.h"
#include "TSystem.h"
#include "TDirectory.h"

#include <iostream>

#include "Hit.hh"

using namespace std;

TThread *thread1, *thread2;
// TFile* f1;
// TFile* f2;
void *handle1(void *)
{
  // gThreadTsd

   // TThread::Lock();
  TFile* f1=new TFile("wu1.root","RECREATE");
  Hit* hit;
  vector<Hit*> hitsVector;
  // TClass::GetClass("vector<Hit*>");
  for (long i = 0; i<100; ++i)
    {
      hit=new Hit();
      hit->SetEnergy(1.2*i);
      hit->SetID(int(i));
      cout <<"thread:1  ID:"<<hit->GetID()<<"  Energy:"<<hit->GetEnergy()<< endl;
      hitsVector.push_back(hit);
    }

  f1->WriteObject(&hitsVector, "test1");
  f1->Close();
  delete hit;
   // TThread::UnLock();
}

void *handle2(void *)
{
   // TThread::Lock();
  TFile* f2=new TFile("wu2.root","RECREATE");
  Hit* hit;
  vector<Hit*> hitsVector;
  // TClass::GetClass("vector<Hit*>");
  for (long i = 0; i<100; ++i)
    {
      hit=new Hit();
      hit->SetEnergy(1.2*i);
      hit->SetID(i);
      cout <<"thread:2  ID:"<<hit->GetID()<<"  Energy:"<<hit->GetEnergy()<< endl;
      hitsVector.push_back(hit);
    }

  f2->WriteObject(&hitsVector, "test2");
  f2->Close();
  delete hit;
   // TThread::UnLock();
}

int main()
{
  // TFile* f=new TFile("wu.root","RECREATE");
  // Hit* hit;
  // vector<Hit*> hitsVector;
  // // TClass::GetClass("vector<Hit*>");
  // for (int i = 0; i<100; ++i)
  //   {
  //     hit=new Hit();
  //     hit->SetEnergy(1.2*i);
  //     hit->SetID(i);
  //     // cout <<"ID:"<<hit->GetID()<<"  Energy:"<<hit->GetEnergy()<< endl;
  //     hitsVector.push_back(hit);
  //   }

  // f->WriteObject(&hitsVector, "test1");
  // f->Close();
  // delete hit;


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......



   printf("Starting Thread 0\n");
   thread1 = new TThread("t0", handle1, (void*) 0);
   thread1->Run();
   printf("Starting Thread 1\n");
   thread2 = new TThread("t1", handle2, (void*) 1);
   thread2->Run();

  for (long i = 0; i<100; ++i)
    {

      cout <<"thread: master"<< endl;

    }

   thread1->Join();
   thread2->Join();

   delete thread1;
   delete thread2;

  return 0;
}
// 
// WriteObject.cc ends here
