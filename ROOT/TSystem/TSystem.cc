// TSystem.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 四 3月 17 21:40:23 2016 (+0800)
// Last-Updated: 六 8月 13 16:49:39 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 77
// URL: http://wuhongyi.cn 

#include <TSystem.h>
#include <iostream>
using namespace std;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

int TSystem()
{
  //以下部分只有在解释运行时能出正确结果，gcc编译运行结果是有问题的！！！

  TString dir = gSystem->UnixPathName(__FILE__);//当前文件所在目录
  cout<<dir<<endl;

  // gSystem->AccessPathName("pathToFile/FileName",kFileExists) 判断文件是否存在
  if(gSystem->AccessPathName("main.cc",kFileExists)) cout<<"#文件存在。"<<endl;//判断当前目录下是否存在该文件

  if(gSystem->AccessPathName(".",kWritePermission)) cout<<"#当前路径可写。"<<endl;//判断文件夹是否可写
  // gSystem->AccessPathName("/etc/krb5.conf", kReadPermission);

  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  FileStat_t fs;
  gSystem->GetPathInfo("TSystem.cc", fs);//获取文件信息
  cout<<(Int_t)fs.fSize<<endl;

  cout<<"当前路径："<<gSystem->pwd()<<endl;
  gSystem->cd("/usr/include");

  cout<<"BaseName:"<<gSystem->BaseName("TSystem.cc")<<endl;

  // gSystem->CompileMacro("track.C");//将文件编译成动态链接库
  // gSystem->CompileMacro("track.C", "k");
  gSystem->Rename("123","456");//文件、文件夹重命名
  // gSystem->CopyFile("hsimple.root", "tot100.root");

  cout<<gSystem->GetName()<<endl;//获取系统类型 Unix、WinNT 等

  Long_t id, size,flags,modtime;
  gSystem->GetPathInfo("ROOTSYS",&id,&size,&flags,&modtime);
  cout<<id<<"  "<<size<<"  "<<flags<<"  "<<modtime<<endl;

  cout<<"TempDirectory:"<<gSystem->TempDirectory()<<endl;
  cout<<gSystem->DirName(__FILE__)<<endl;
  gSystem->ChangeDirectory("/opt");//
  cout<<gSystem->WorkingDirectory()<<endl;
  gSystem->OpenDirectory("XXX");//打开文件夹
  gSystem->MakeDirectory("xxx");//新建文件夹
  // gSystem->ExpandPathName("xxx");

  cout<<"root:"<<gSystem->Which(gSystem->Getenv("PATH"), "root.exe", kExecutePermission)<<endl;//寻找可执行文件所在位置

  // gSystem->mkdir("xxx", kTRUE);

  gSystem->Exec("ls");//执行命令

  cout<<gSystem->GetSoExt()<<endl;//so
  // gSystem->Load("xx.so");//加载文件、链接库等
  gSystem->Load("libGeom");
  // gSystem->Load("$HOME/pythia6/libPythia6");

  cout<<gSystem->Getenv("ROOTSYS")<<endl;//获取环境变量对应的路径


  CpuInfo_t cpuInfo;
  MemInfo_t memInfo;
  gSystem->GetCpuInfo(&cpuInfo, 100);
  Float_t act_load = cpuInfo.fTotal;
  cout<<act_load<<endl;//actual CPU load
  gSystem->GetMemInfo(&memInfo);
  Int_t memUsage;
  memUsage = memInfo.fMemTotal;
  cout<<"MemTotal:"<<memUsage<<endl;
  memUsage = memInfo.fMemUsed;
  cout<<"MemUsed:"<<memUsage<<endl;
  memUsage = memInfo.fMemFree;
  cout<<"MemFree:"<<memUsage<<endl;

  UserGroup_t *u = gSystem->GetUserInfo();
  cout<<u->fUser<<endl;
  UserGroup_t *ug = gSystem->GetUserInfo(gSystem->GetUid());
  cout<<ug->fUser.Data()<<endl;

  cout<<gSystem->HostName()<<endl;
  cout<<gSystem->GetPid()<<endl;

  // gSystem->Setenv("XXXXXX", "xxx");

  //gSystem->AddIncludePath("-I$ROOTSYS/include");
  gSystem->IgnoreSignal(kSigSegmentationViolation, true);//未明白

  // gSystem->Unlink(("guitest01.C");//未明白
  // gSystem->RedirectOutput(fName.Data(), "a");
  // gSystem->RedirectOutput(0);

  // gSystem->GetDirEntry(thedir);
  // gSystem->FreeDirectory(dirp);
  // gSystem->ProcessEvents();//未明白

  // gSystem->GetFromPipe("xxx");//
  // gSystem->GetFromPipe("ls -lrt memstat*.root");

  // gSystem->DynamicPathName("libSRPAuth", kTRUE);

  // FILE *fp = gSystem->OpenPipe("xxx", "r");
  // gSystem->ClosePipe(fp);

  gSystem->Sleep(100);

  gSystem->Exit(1);//退出程序
  cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;

  return 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// 
// TSystem.cc ends here
