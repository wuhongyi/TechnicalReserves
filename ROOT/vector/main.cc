// main.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 四 6月 28 09:05:41 2018 (+0800)
// Last-Updated: 四 6月 28 09:19:17 2018 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 4
// URL: http://wuhongyi.cn 

#include "RVersion.h"//版本判断
#include "TApplication.h"
#include "TBenchmark.h"
#include "TBrowser.h"
#include "TCutG.h"
#include "TDatime.h"
#include "TError.h"
#include "TList.h"
#include "TObject.h"
#include "TRint.h"
#include "TROOT.h"
#include "TSlider.h"
#include "TStopwatch.h"
#include "TString.h"
#include "TStyle.h"
#include "TSystem.h"
#include "TTimer.h"
#include "TTimeStamp.h"
#include "THttpServer.h"

#include "TF1.h"
#include "TF2.h"
#include "TFitResult.h"
#include "TFormula.h"
#include "TLorentzVector.h"
#include "TMath.h"
#include "TMatrixD.h"
#include "TMatrixDEigen.h"
#include "TRandom.h"
#include "TRandom1.h"
#include "TRandom2.h"
#include "TRandom3.h"
#include "TSpectrum.h"
#include "TSpectrum2.h"
#include "TVector3.h"
#include "TVectorD.h"

// #define NDEBUG
#include <algorithm>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void addvector(std::vector<std::string>* p)
{
  p->push_back("111");
  p->push_back("222");
  p->push_back("333");
}

int main(int argc, char *argv[])
{
  // Create an interactive ROOT application
  TRint *theApp = new TRint("Rint", &argc, argv);

  std::vector<std::string>* FilterPwith = NULL;
  if(!FilterPwith) FilterPwith = new std::vector<std::string>;

  // FilterPwith->push_back("aaa");

  size_t nwith = FilterPwith->size();
  
  if(FilterPwith){FilterPwith->clear(); delete FilterPwith;}
  
  // and enter the event loop...
  theApp->Run();
  delete theApp;

  return 0;
}

// 
// main.cc ends here
