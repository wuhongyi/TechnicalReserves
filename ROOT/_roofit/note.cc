// note.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 三 7月  8 18:53:19 2015 (+0800)
// Last-Updated: 日 7月 12 12:37:11 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 46
// URL: http://wuhongyi.cn 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef __CINT__
#include "RooCFunction1Binding.h"//单一参数函数 
#include "RooCFunction3Binding.h"//三参数函数
#include "RooGlobalFunc.h"
#endif

#include "RooAbsReal.h"
#include "RooAddModel.h"
#include "RooAddPdf.h"
#include "RooBinning.h"
#include "RooBMixDecay.h"
#include "RooCategory.h"
#include "RooChebychev.h"
#include "RooClassFactory.h"
#include "RooConstVar.h"
#include "RooCustomizer.h"
#include "RooDataHist.h"
#include "RooDataSet.h"
#include "RooDecay.h"
#include "RooExponential.h"
#include "RooExtendPdf.h"
#include "RooFFTConvPdf.h"
#include "RooFitResult.h"
#include "RooFormulaVar.h"
#include "RooGaussian.h"
#include "RooGaussModel.h"
#include "RooGenericPdf.h"
#include "RooHist.h"
#include "RooLandau.h"
#include "RooPlot.h"
#include "RooPolynomial.h"
#include "RooRealVar.h"
#include "RooTFnBinding.h" 
#include "RooTruthModel.h"


#include "TAxis.h"
#include "TArrow.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TFile.h"
#include "TH1.h"
#include "TH1D.h"
#include "TMath.h"
#include "Math/DistFunc.h"
#include "TText.h"
#include "TTree.h"
#include "TRandom.h"
#include "TROOT.h"

using namespace RooFit ;
//over 
//101 102 103 105 106 107     109 110
//201 202 203 204 205 206   208 


//= 108 111 207  209
//error 104
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Declare variables x,mean,sigma with associated name, title, initial value and allowed range
RooRealVar x("x","x",-10,10) ;
RooRealVar mean("mean","mean of gaussian",1,-10,10) ;
RooRealVar sigma("sigma","width of gaussian",1,0.1,10) ;
RooGaussian gauss("gauss","gaussian PDF",x,mean,sigma) ;// Build gaussian p.d.f in terms of x,mean and sigma  
RooPlot* xframe = x.frame(Title("Gaussian p.d.f.")) ;// Construct plot frame in 'x'
gauss.plotOn(xframe) ;// Plot gauss in frame (i.e. in x) 
sigma.setVal(3) ;// Change the value of sigma to 3
gauss.plotOn(xframe,LineColor(kRed)) ;// Plot gauss in frame (i.e. in x) and draw frame on canvas

RooDataSet* data = gauss.generate(x,10000) ;// Generate a dataset of 1000 events in x from gauss
RooPlot* xframe2 = x.frame(Title("Gaussian p.d.f. with data")) ;// Make a second plot frame in x and draw both the data and the p.d.f in the frame
data->plotOn(xframe2) ;
gauss.plotOn(xframe2) ;
gauss.fitTo(*data) ;// Fit pdf to data
mean.Print() ;// Print values of mean and sigma (that now reflect fitted values and errors)
sigma.Print() ;
// Draw all frames on a canvas
TCanvas* c = new TCanvas("rf101_basics","rf101_basics",800,400) ;
c->Divide(2) ;
c->cd(1) ; gPad->SetLeftMargin(0.15) ; xframe->GetYaxis()->SetTitleOffset(1.6) ; xframe->Draw() ;
c->cd(2) ; gPad->SetLeftMargin(0.15) ; xframe2->GetYaxis()->SetTitleOffset(1.6) ; xframe2->Draw() ;
  


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//RooRealVar
RooRealVar x("x","x",-10,10) ;
RooRealVar mean("mean","mean of gaussian",1,-10,10) ;
RooRealVar sigma("sigma","width of gaussian",1,0.1,10) ;

sigma.setVal(3) ;// Change the value of sigma to 3

mean.Print() ;// Print values of mean and sigma
sigma.Print() ;

x.setRange("signal",-5,5) ;// Define a range named "signal" in x from -5,5

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//RooAbsReal
// -----------------------------------
x.setRange("signal",-5,5) ;// Define a range named "signal" in x from -5,5
// Create an integral of gx_Norm[x] over x in range "signal"
// This is the fraction of of p.d.f. gx_Norm[x] which is in the range named "signal"
RooAbsReal* igx_sig = gx.createIntegral(x,NormSet(x),Range("signal")) ;//对归一化的函数子区域进行积分
cout << "gx_Int[x|signal]_Norm[x] = " << igx_sig->getVal() << endl ;


// Create the cumulative distribution function of gx  i.e. calculate Int[-10,x] gx(x') dx'
RooAbsReal* gx_cdf = gx.createCdf(x) ;//计算累积的分布函数，其最大值为1.
gx_cdf->plotOn(frame) ;


// Bind one-dimensional TMath::Erf function as RooAbsReal function
RooRealVar x("x","x",-3,3) ;
RooAbsReal* erf = bindFunction("erf",TMath::Erf,x) ;//单一参数函数
erf->Print() ;// Print erf definition
RooPlot* frame1 = x.frame(Title("TMath::Erf bound as RooFit function")) ;
erf->plotOn(frame1) ;// Plot erf on frame 

TF1 *fa1 = new TF1("fa1","sin(x)/x",0,10);// Create a ROOT TF1 function
RooRealVar x3("x3","x3",0.01,20) ;// Create an observable 
RooAbsReal* rfa1 = bindFunction(fa1,x3) ;// Create binding of TF1 object to above observable
rfa1->Print() ;// Print rfa1 definition
RooPlot* frame3 = x3.frame(Title("TF1 bound as RooFit function")) ;
rfa1->plotOn(frame3) ;// Make plot frame in observable, plot TF1 binding function


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//RooAbsPdf
// -----------------------------------
// Bind pdf ROOT::Math::Beta with three variables as RooAbsPdf function
RooRealVar x2("x2","x2",0,0.999) ;
RooRealVar a("a","a",5,0,10) ;
RooRealVar b("b","b",2,0,10) ;
RooAbsPdf* beta = bindPdf("beta",ROOT::Math::beta_pdf,x2,a,b) ;//三参数函数
beta->Print() ;// Perf beta definition
RooDataSet* data = beta->generate(x2,10000) ;// Generate some events and fit
beta->fitTo(*data) ;
RooPlot* frame2 = x2.frame(Title("ROOT::Math::Beta bound as RooFit pdf")) ;// Plot data and pdf on frame
data->plotOn(frame2) ;
beta->plotOn(frame2) ;


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//RooAddPdf   各种模型的函数想加
// -----------------------------------

// model(x) = fsig*sig(x) + (1-fsig)*bkg(x)
RooAddPdf model(“model”,”model”,RooArgList(sig,bkg),fsig) ;
// model2(x) = fsig*sig(x) + fbkg1*bkg1(x) + (1-fsig-fbkg)*bkg2(x)
RooAddPdf model2(“model2”,”model2”,RooArgList(sig,bkg1,bkg2),RooArgList(fsig,fbkg1)) ;
// Sum the composite signal and background into an extended pdf nsig*sig+nbkg*bkg
RooAddPdf  model("model","(g1+g2)+a",RooArgList(bkg,sig),RooArgList(nbkg,nsig)) ;



RooRealVar mean("mean","mean of gaussians",5) ;
RooRealVar sigma1("sigma1","width of gaussians",0.5) ;
RooRealVar sigma2("sigma2","width of gaussians",1) ;
RooGaussian sig1("sig1","Signal component 1",x,mean,sigma1) ;  
RooGaussian sig2("sig2","Signal component 2",x,mean,sigma2) ;  
RooRealVar sig1frac("sig1frac","fraction of component 1 in signal",0.8,0.,1.) ;
RooAddPdf sig("sig","Signal",RooArgList(sig1,sig2),sig1frac) ;// Sum the signal components into a composite signal p.d.f.
RooRealVar a0("a0","a0",0.5,0.,1.) ;
RooRealVar a1("a1","a1",-0.2,0.,1.) ;
RooChebychev bkg("bkg","Background",x,RooArgSet(a0,a1)) ;// Build Chebychev polynomial p.d.f.  
RooRealVar bkgfrac("bkgfrac","fraction of background",0.5,0.,1.) ;
RooAddPdf  model("model","g1+g2+a",RooArgList(bkg,sig),bkgfrac) ;// Sum the composite signal and background
RooDataSet *data = model.generate(x,1000) ;
RooPlot* xframe = x.frame(Title("Example of composite pdf=(sig1+sig2)+bkg")) ;// Plot data and PDF overlaid
data->plotOn(xframe) ;
model.plotOn(xframe) ;
model.plotOn(xframe,Components(bkg),LineStyle(kDashed)) ;// Overlay the background component of model with a dashed line
model.plotOn(xframe,Components(RooArgSet(bkg,sig2)),LineStyle(kDotted)) ;// Overlay the background+sig2 components of model with a dotted line
model.Print("t") ;// Print structure of composite p.d.f.

RooAddPdf  model2("model","g1+g2+a",RooArgList(bkg,sig1,sig2),RooArgList(bkgfrac,sig1frac),kTRUE) ;// model2 = bkg + (sig1 + sig2) 
// NB: Each coefficient is interpreted as the fraction of the left-hand component of the i-th recursive sum, i.e. sum4 = A + ( B + ( C + D)  with fraction fA, fB and fC expands to sum4 = fA*A + (1-fA)*(fB*B + (1-fB)*(fC*C + (1-fC)*D))
model2.plotOn(xframe,LineColor(kRed),LineStyle(kDashed)) ;
model2.plotOn(xframe,Components(RooArgSet(bkg,sig2)),LineColor(kRed),LineStyle(kDashed)) ;
model2.Print("t") ;


// Plot data and PDF overlaid, use expected number of events for p.d.f projection normalization rather than observed number of events (==data->numEntries())
RooPlot* xframe = x.frame(Title("extended ML fit example")) ;
data->plotOn(xframe) ;
model.plotOn(xframe,Normalization(1.0,RooAbsReal::RelativeExpected)) ;
model.plotOn(xframe,Components(bkg),LineStyle(kDashed),Normalization(1.0,RooAbsReal::RelativeExpected)) ;// Overlay the background component of model with a dashed line
model.plotOn(xframe,Components(RooArgSet(bkg,sig2)),LineStyle(kDotted),Normalization(1.0,RooAbsReal::RelativeExpected)) ;// Overlay the background+sig2 components of model with a dotted line
model.Print("t") ;// Print structure of composite p.d.f.



// Print tree to file
model.printCompactTree("","rf206_asciitree.txt") ;
// Print GraphViz DOT file with representation of tree
model.graphVizTree("rf206_model.dot") ;
// Make graphic output file with one of the GraphViz tools
// 'Top-to-bottom graph'
// unix> dot -Tgif -o rf206_model_dot.gif rf206_model.dot   或者  dot -Tps rf206_model.dot -o rf206.ps
// 'Spring-model graph'
// unix> fdp -Tgif -o rf207_model_fdp.gif rf207_model.dot
// 格式：dot -T<type> -o <outfile> <infile.dot>
// 输入文件是<infile.dot>，生成的格式由<type>指定，生成的文件是<outfile>。
// 其中-T <type>包括：
// -Tps (PostScript),
// -Tsvg -Tsvgz (Structured Vector Graphics), 
// -Tfig (XFIG  graphics), 
// -Tmif  (FrameMaker graphics),
// -Thpgl (HP pen plotters),
// -Tpcl (Laserjet printers),
// -Tpng -Tgif (bitmap graphics),
// -Tdia (GTK+ based diagrams),
// -Timap (imagemap files for httpd servers for each node or edge  that  has a non-null "href" attribute.),
// -Tcmapx (client-side imagemap for use in html and xhtml).

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//RooExtendPdf

// Sum the composite signal and background into an extended pdf nsig*sig+nbkg*bkg
RooRealVar nsig("nsig","number of signal events",500,0.,10000) ;
RooRealVar nbkg("nbkg","number of background events",500,0,10000) ;
RooAddPdf sig("sig","Signal",RooArgList(sig1,sig2),sig1frac) ;
RooChebychev bkg("bkg","Background",x,RooArgSet(a0,a1)) ;
// Associated nsig/nbkg as expected number of events with sig/bkg
RooExtendPdf esig("esig","extended signal p.d.f",sig,nsig) ;
RooExtendPdf ebkg("ebkg","extended background p.d.f",bkg,nbkg) ;
// Construct sum of two extended p.d.f. (no coefficients required)
RooAddPdf  model2("model2","(g1+g2)+a",RooArgList(ebkg,esig)) ;


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//RooFFTConvPdf

RooRealVar t("t","t",-10,30) ;
RooRealVar ml("ml","mean landau",5.,-20,20) ;
RooRealVar sl("sl","sigma landau",1,0.1,10) ;
RooLandau landau("lx","lx",t,ml,sl) ;
RooRealVar mg("mg","mg",0) ;
RooRealVar sg("sg","sg",2,0.1,10) ;
RooGaussian gauss("gauss","gauss",t,mg,sg) ;
t.setBins(10000,"cache") ;// Set #bins to be used for FFT sampling to 10000
RooFFTConvPdf lxg("lxg","landau (X) gauss",t,landau,gauss) ;// Construct landau (x) gauss
RooDataSet* data = lxg.generate(t,10000) ;// Sample 1000 events in x from gxlx
lxg.fitTo(*data) ;// Fit gxlx to data
RooPlot* frame = t.frame(Title("landau (x) gauss convolution")) ;  // Plot data, landau pdf, landau (X) gauss pdf
data->plotOn(frame) ;
lxg.plotOn(frame) ;
landau.plotOn(frame,LineStyle(kDashed)) ;


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//RooFormulaVar
// -----------------------------------
RooRealVar mean2("mean2","mean^2",10,0,200) ;
RooRealVar sigma("sigma","sigma",3,0.1,10) ;
RooFormulaVar mean("mean","mean","sqrt(mean2)",mean2) ;// Construct interpreted function mean = sqrt(mean^2)
RooGaussian g2("g2","h2",x,mean,sigma) ;// Construct a gaussian g2(x,sqrt(mean2),sigma) ;
RooGaussian g1("g1","g1",x,RooConst(10),RooConst(3)) ;// Construct a separate gaussian g1(x,10,3) to generate a toy Gaussian dataset with mean 10 and width 3
RooDataSet* data2 = g1.generate(x,1000) ;
RooFitResult* r = g2.fitTo(*data2,Save()) ;// Fit g2 to data from g1
r->Print() ;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//RooGaussian

RooPlot* xframe = x.frame(Title("Gaussian p.d.f.")) ;// Construct plot frame in 'x'
RooGaussian gauss("gauss","gaussian PDF",x,mean,sigma) ;// Build gaussian p.d.f in terms of x,mean and sigma  
gauss.plotOn(xframe) ;// Plot gauss in frame (i.e. in x) 
gauss.plotOn(xframe,LineColor(kRed)) ;// Plot gauss in frame (i.e. in x) and draw frame on canvas

RooDataSet* data = gauss.generate(x,10000) ;// Generate a dataset of 1000 events in x from gauss
gauss.fitTo(*data) ;// Fit pdf to data

RooGaussian g1("g1","g1",x,RooConst(10),RooConst(3)) ;// Construct a separate gaussian g1(x,10,3) to generate a toy Gaussian dataset with mean 10 and width 3

TH1* hh = ...... ;
RooDataHist dh("dh","dh",x,Import(*hh)) ;
gauss.fitTo(dh) ;
gauss.plotOn(frame) ;


//这个不明白用处
Double_t gauss_raw = gauss.getVal();//raw unnormalized value
Double_t gauss_pdfX = gauss.getVal(x);//value when used as p.d.f in x
Double_t gauss_pdfM = gauss.getVal(mean);//value when used as p.d.f in mean
Double_t gauss_pdfS = gauss.getVal(sigma);//value when used as p.d.f in sigma

// Return 'raw' unnormalized value of gx
cout << "gx = " << gx.getVal() << endl ;

// Return value of gx normalized over x in range [-10,10]
RooArgSet nset(x) ;
cout << "gx_Norm[x] = " << gx.getVal(&nset) << endl ;

// Create object representing integral over gx which is used to calculate  gx_Norm[x] == gx / gx_Int[x]
RooAbsReal* igx = gx.createIntegral(x) ;
cout << "gx_Int[x] = " << igx->getVal() << endl ;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//RooChebychev  切比雪夫

RooRealVar x("x","x",0,10) ;
RooRealVar a0("a0","a0",0.5,0.,1.) ;
RooRealVar a1("a1","a1",-0.2,0.,1.) ;
RooChebychev bkg1("bkg1","Background 1",x,RooArgSet(a0,a1)) ;// Build Chebychev polynomial p.d.f.


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//RooExponential   指数函数

RooRealVar x("x","x",0,10) ;
RooRealVar alpha("alpha","alpha",-1) ;
RooExponential bkg2("bkg2","Background 2",x,alpha) ;  // Build expontential pdf


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//RooLandau   朗道

RooRealVar t("t","t",-10,30) ;
RooRealVar ml("ml","mean landau",5.,-20,20) ;
RooRealVar sl("sl","sigma landau",1,0.1,10) ;
RooLandau landau("lx","lx",t,ml,sl) ;  // Construct landau(t,ml,sl) ;


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//RooPlot
// -----------------------------------
RooPlot* xframe = x.frame(Title("Gaussian p.d.f.")) ;// Construct plot frame in 'x'
gauss.plotOn(xframe) ;// Plot gauss in frame (i.e. in x) 

RooDataSet* data = gauss.generate(x,10000) ;// Generate a dataset of 1000 events in x from gauss
data->plotOn(xframe) ;
data->plotOn(frame,DataError(RooAbsData::SumW2)) ;//ErrorType { Poisson, SumW2, None, Auto, Expected }
gauss.plotOn(frame1) ;
cout << "chi^2 = " << frame->chiSquare() << endl ;//Calculate chi^2
// Show the chi^2 of the curve w.r.t. the histogram
// If multiple curves or datasets live in the frame you can specify the name of the relevant curve and/or dataset in chiSquare()

TCanvas* c = new TCanvas("rf101_basics","rf101_basics",800,400) ;
c->Divide(2) ;
c->cd(1) ; gPad->SetLeftMargin(0.15) ; xframe->GetYaxis()->SetTitleOffset(1.6) ; xframe->Draw() ;

RooAbsReal* gx_cdf = gx.createCdf(x) ;// Create the cumulative distribution function of gx  i.e. calculate Int[-10,x] gx(x') dx'
gx_cdf->plotOn(frame) ;

RooPlot* frame1 = x.frame(Name("xframe"),Title("Red Curve / SumW2 Histo errors"),Bins(20)) ;





//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//RooDataSet
// -----------------------------------
RooDataSet* data = gauss.generate(x,10000) ;// Generate a dataset of 1000 events in x from gauss

RooGenericPdf genpdf("genpdf","genpdf","(1+0.1*abs(x)+sin(sqrt(abs(x*alpha+0.1))))",RooArgSet(x,alpha)) ;
RooDataSet* data = genpdf.generate(x,10000) ;// Generate a toy dataset from the interpreted p.d.f

// Construct unbinned dataset importing tree branches x and y matching between branches and RooRealVars is done by name of the branch/RRV
// Note that ONLY entries for which x,y have values within their allowed ranges as defined in RooRealVar x and y are imported. Since the y values in the import tree are in the range [-15,15] and RRV y defines a range [-10,10] this means that the RooDataSet below will have less entries than the TTree 'tree'
TTree* tree = ......;//tree->Branch("x",px,"x/D") ; tree->Branch("y",py,"y/D") ;
RooRealVar x("x","x",-10,10) ;
RooRealVar y("y","y",-10,10) ;
RooDataSet ds("ds","ds",RooArgSet(x,y),Import(*tree)) ;
ds.Print() ;// Print number of events in dataset
ds.plotOn(frame) ;// Print unbinned dataset with default frame binning (100 bins)
ds.plotOn(frame,Binning(20)) ;// Print unbinned dataset with custom binning choice (20 bins)



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//RooDataHist
// -----------------------------------
TH1* hh =......;// Create a ROOT TH1 histogram
RooRealVar x("x","x",-10,10) ;// Declare observable x
RooDataHist dh("dh","dh",x,Import(*hh)) ;// Create a binned dataset that imports contents of TH1 and associates its contents to observable 'x'
RooPlot* frame = x.frame(Title("Imported TH1 with Poisson error bars")) ;
dh.plotOn(frame) ;//default Poisson error bars
//或者
dh.plotOn(frame,DataError(RooAbsData::SumW2)) ;//symmetric 'sum-of-weights' error 



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//RooGenericPdf
// -----------------------------------
// To construct a proper p.d.f, the formula expression is explicitly normalized internally by dividing it by a numeric integral of the expresssion over x in the range [-20,20] 
RooRealVar x("x","x",-20,20) ;
RooRealVar alpha("alpha","alpha",5,0.1,10) ;
RooGenericPdf genpdf("genpdf","genpdf","(1+0.1*abs(x)+sin(sqrt(abs(x*alpha+0.1))))",RooArgSet(x,alpha)) ;
RooDataSet* data = genpdf.generate(x,10000) ;// Generate a toy dataset from the interpreted p.d.f
genpdf.fitTo(*data) ;// Fit the interpreted p.d.f to the generated data

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//RooHist  直方图

RooHist* hresid = frame1->residHist() ;// Construct a histogram with the residuals of the data w.r.t. the curve   残差分布  直方图-数据与拟合曲线的差值
RooHist* hpull = frame1->pullHist() ;// Construct a histogram with the pulls of the data w.r.t the curve
RooPlot* frame2 = x.frame(Title("Residual Distribution")) ;// Create a new frame to draw the residual distribution and add the distribution to the frame
frame2->addPlotable(hresid,"P") ;
RooPlot* frame3 = x.frame(Title("Pull Distribution")) ;// Create a new frame to draw the pull distribution and add the distribution to the frame
frame3->addPlotable(hpull,"P") ;


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//RooFitResult
// -----------------------------------
RooFitResult* r = g2.fitTo(*data2,Save()) ;
r->Print() ;

// Fit p.d.f to all data
RooFitResult* r_full = model.fitTo(*modelData,Save(kTRUE)) ;
x.setRange("signal",-3,3) ;// Define "signal" range in x as [-3,3]  
// Fit p.d.f only to data in "signal" range
RooFitResult* r_sig = model.fitTo(*modelData,Save(kTRUE),Range("signal")) ;


RooDataSet *data = model.generate(x,1000) ;
// Perform unbinned extended ML fit to data
RooFitResult* r = model.fitTo(*data,Extended(kTRUE),Save()) ;
r->Print() ;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......





//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


// Data plotting styles  数据填充样式
// -----------------------------------
RooDataSet* data = gauss.generate(x,100) ;
// Use sqrt(sum(weights^2)) error instead of Poisson errors
data->plotOn(frame1,DataError(RooAbsData::SumW2)) ;
// Remove horizontal error bars
data->plotOn(frame2,XErrorSize(0)) ;//移除水平误差棒
// Blue markers and error bors
data->plotOn(frame3,MarkerColor(kBlue),LineColor(kBlue)) ;//设置误差棒颜色
// Filled bar chart
data->plotOn(frame4,DrawOption("B"),DataError(RooAbsData::None),XErrorSize(0),FillColor(kGray)) ;//


// Function plotting styles 曲线填充样式
// -----------------------------------
// Change line color to red
gauss.plotOn(frame1,LineColor(kRed)) ;//设置曲线颜色
// Change line style to dashed
gauss.plotOn(frame2,LineStyle(kDashed)) ;//设置曲线样式
// Filled shapes in green color
gauss.plotOn(frame3,DrawOption("F"),FillColor(kOrange),MoveToBack()) ;
//
gauss.plotOn(frame4,Range(-8,3),LineColor(kMagenta)) ;//设置曲线范围跟颜色


model.plotOn(frame,Range("Full"),LineStyle(kDashed),LineColor(kRed)) ; // Add shape in full ranged dashed
model.plotOn(frame) ; // By default only fitted range is shown

model.plotOn(xframe,Components(bkg),LineColor(kRed)) ;// Plot single background component specified by object reference
model.plotOn(xframe,Components(bkg2),LineStyle(kDashed),LineColor(kRed)) ;// Plot single background component specified by object reference
model.plotOn(xframe,Components(RooArgSet(bkg,sig2)),LineStyle(kDotted)) ;

// Make component by name/regexp
model.plotOn(xframe2,Components("bkg"),LineColor(kCyan)) ;// Plot single background component specified by name
model.plotOn(xframe2,Components("bkg1,sig2"),LineStyle(kDotted),LineColor(kCyan)) ;// Plot multiple background components specified by name
model.plotOn(xframe2,Components("sig*"),LineStyle(kDashed),LineColor(kCyan)) ;// Plot multiple background components specified by regular expression on name
model.plotOn(xframe2,Components("bkg1,sig*"),LineStyle(kDashed),LineColor(kYellow),Invisible()) ;// Plot multiple background components specified by multiple regular expressions on name



// Add box with pdf parameters 
// -----------------------------------
// Left edge of box starts at 55% of Xaxis) 
gauss.paramOn(frame,Layout(0.55)) ; //mean  sigma


// Add box with data statistics
// -----------------------------------
// X size of box is from 55% to 99% of Xaxis range, top of box is at 80% of Yaxis range)
data->statOn(frame,Layout(0.55,0.99,0.8)) ;//RMS Mean Entries



// Add text and arrow
// -----------------------------------
// Add text to frame
TText* txt = new TText(2,100,"Signal") ;
txt->SetTextSize(0.04) ;
txt->SetTextColor(kRed) ;
frame->addObject(txt) ;

// Add arrow to frame
TArrow* arrow = new TArrow(2,100,-1,50,0.01,"|>") ;
arrow->SetLineColor(kRed) ;
arrow->SetFillColor(kRed) ;
arrow->SetLineWidth(3) ;
frame->addObject(arrow) ;

// Persist frame with all decorations in ROOT file
// -----------------------------------
frame->Write() ;
f.Close() ;


// 
// note.cc ends here
