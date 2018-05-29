#include <TSpectrum>
void Back_gamma256() {
   Int_t i, j;
   Double_t nbinsx = 64;
   Double_t nbinsy = 64;
   Double_t xmin = 0;
   Double_t xmax = (Double_t)nbinsx;
   Double_t ymin = 0;
   Double_t ymax = (Double_t)nbinsy;
   Double_t** source = new Double_t*[nbinsx];
   for (i=0;i<nbinsx;i++)
      source[i]=new Double_t[nbinsy];
   TH2F *back = new TH2F("back","Background estimation",nbinsx,xmin,xmax,nbinsy,ymin,ymax);
   TFile *f = new TFile("spectra2/TSpectrum2.root");
   back=(TH2F*) f->Get("back2;1");
   TCanvas *Background = new TCanvas("Background","Estimation of background with increasing window",10,10,1000,700);
   TSpectrum *s = new TSpectrum();
   for (i = 0; i < nbinsx; i++){
      for (j = 0; j < nbinsy; j++){
         source[i][j] = back->GetBinContent(i + 1,j + 1);
      }
   }
   s->Background(source,nbinsx,nbinsy,8,8,kBackIncreasingWindow,kBackSuccessiveFiltering);
   for (i = 0; i < nbinsx; i++){
      for (j = 0; j < nbinsy; j++)
         back->SetBinContent(i + 1,j + 1, source[i][j]);
   }
   back->Draw("SURF");
}
