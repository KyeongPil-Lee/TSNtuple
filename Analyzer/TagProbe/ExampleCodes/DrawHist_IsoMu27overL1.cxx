#include <TagProbe/TnPTool.h>

void DrawHist_IsoMu27overL1() {
  std::unique_ptr<TnPEffTool> tool( new TnPEffTool("ROOTFile_TnPHist_example.root") );

  TGraphAsymmErrors* gEff_eta = tool->CalcTnPEff_CutAndCount( "Eta" );
  gEff_eta->Draw();
}