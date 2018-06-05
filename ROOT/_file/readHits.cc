// readHits.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 五 5月  1 09:55:24 2015 (+0800)
// Last-Updated: 六 5月  2 19:34:17 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 10
// URL: http://wuhongyi.cn 

#include "TROOT.h"
#include "TFile.h"
#include "TSystem.h"
#include "TKey.h"
#include "Hit.hh"
#include <iostream>

using namespace std;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
int main(int argc, char *argv[])
{
  // initialize ROOT
  // TSystem ts;
  // gSystem->Load("libwuDict");
  //  ROOT::Cintex::Cintex::SetDebug(2);
  // ROOT::Cintex::Cintex::Enable();
  if(argc<2) cout << "Missing name of the file to read!" << endl;
 
  TFile fo(argv[1]);
   
  std::vector<Hit*>* hits;
  fo.GetListOfKeys()->Print();
 
  TIter next(fo.GetListOfKeys());
  TKey *key;
  //double tot_en;
  while ((key=(TKey*)next()))
    {
      fo.GetObject(key->GetName(), hits);
 
      //tot_en = 0;
      cout << "Collection: " << key->GetName() << endl;
      cout << "Number of hits: " << hits->size() << endl;
      for (size_t i=0;i!=hits->size();i++)
	{
	  cout <<"ID:"<<(*hits)[i]->GetID()<<"  Energy:"<<(*hits)[i]->GetEnergy()<< endl;
	}         
    }
  return 0;
}


// 
// readHits.cc ends here
