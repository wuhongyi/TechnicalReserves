void fillrandom() {
   
  TCanvas *c1 = new TCanvas("c1","The Title of Canvas",200,10,700,900);//设置画板
  c1->SetFillColor(18);//设置画板背景颜色

  pad1 = new TPad("pad1","The pad with the function",0.05,0.50,0.95,0.95,21);
  pad2 = new TPad("pad2","The pad with the histogram",0.05,0.05,0.95,0.45,21);
//将画板分成几份TPad，其中0.05,0.05,0.95,0.45,21：。前四个数字表示TPad所在方位，第一个0.05跟0.95表示横坐标方向从0.05-0.95，第二个0.05跟0.45表示纵坐标方向从0.05-0.45所在的区间是这个TPad的范围，21表示颜色。
  pad1->Draw();
  pad2->Draw();

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  pad1->cd();//指向第一个TPad

  //gBenchmark->Start("fillrandom");
  //
  // A function (any dimension) or a formula may reference
  // an already defined formula
  //
  form1 = new TFormula("form1","abs(sin(x)/x)");
  sqroot = new TF1("sqroot","sin(x)",0,10);
  //sqroot->SetParameters(10,4,1,20);
  pad1->SetGridx();//x轴上由网格
  pad1->SetGridy();//y轴上有网格
  pad1->GetFrame()->SetFillColor(42);
  pad1->GetFrame()->SetBorderMode(-1);
  pad1->GetFrame()->SetBorderSize(5);
  sqroot->SetLineColor(4);//设置曲线的颜色
  sqroot->SetLineWidth(6);//设置曲线线宽
  sqroot->Draw();
  lfunction = new TPaveLabel(5,39,9.8,4,"The sqroot function");
  lfunction->SetFillColor(41);
  lfunction->Draw();
  //c1->Update();

  //
  // Create a one dimensional histogram (one float per bin)
  // and fill it following the distribution in function sqroot.
  //
  pad2->cd();//指向第二个TPad
  pad2->GetFrame()->SetFillColor(42);
  pad2->GetFrame()->SetBorderMode(-1);
  pad2->GetFrame()->SetBorderSize(5);
  h1f = new TH1F("h1f","Test random numbers",200,0,10);
  h1f->SetFillColor(45);
  h1f->FillRandom("sqroot",10000);
  h1f->Draw();
  //c1->Update();
  c1->Print("fillrandom.pdf");//将画板存储成文件
  //
  // Open a ROOT file and save the formula, function and histogram
  //
  // TFile myfile("fillrandom.root","RECREATE");
  // form1->Write();
  // sqroot->Write();
  // h1f->Write();
  // gBenchmark->Show("fillrandom");
}
