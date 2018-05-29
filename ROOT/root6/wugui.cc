// wugui.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 3月 13 13:12:12 2016 (+0800)
// Last-Updated: 日 3月 13 13:33:49 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 8
// URL: http://wuhongyi.cn 

#include <TGButton.h>

#include <TGClient.h>

#include <TGFrame.h>

#include <TGLabel.h>
#include <TGLayout.h>

#include <TGSplitter.h>


class wuMainFrame : public TGMainFrame
{
public:
  wuMainFrame(const TGWindow *p, int w, int h);
  virtual ~wuMainFrame();


  void CloseWindow();

  ClassDef(wuMainFrame,0);
};

wuMainFrame:: wuMainFrame(const TGWindow *p, int w, int h)
:TGMainFrame(p, w, h)
{


  // What to clean up in destructor
  SetCleanup(kDeepCleanup);

  // Set a name to the main frame
  SetWindowName("Hongyi Wu(wuhongyi@qq.com)");
  SetWMSizeHints(350, 200, 600, 400, 0, 0);
  MapSubwindows();
  Resize(GetDefaultSize());
  MapWindow();
}

wuMainFrame::~wuMainFrame()
{

}

void wuMainFrame::CloseWindow()
{
  // Called when window is closed via the window manager.
  delete this;
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void wugui()
{

  wuMainFrame *mainWindow = new wuMainFrame(gClient->GetRoot(),1200,800);


}

// 
// wugui.cc ends here
