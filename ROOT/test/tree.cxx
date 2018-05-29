#include<iostream>
using namespace std;
int tree(){
 double num;
 double weight;
 TFile *f=new TFile("weight.root","RECREATE");
 TTree *t=new TTree("NameOfTree","title:a list of weight and numbers");
 t->Branch("NameOfBranch1",&num,"number/D");
 t->Branch("NameOfBranch2",&weight,"weight/D");
 ifstream data("test.txt");
 for(int i=0;i<20;i++)
 {
  data>>num>>weight;
  cout<<num<<" "<<weight<<endl;
  t->Fill();
 }
 t->Write();
 data.close();
 f->Close();
}
