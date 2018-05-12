#include <TagProbe/TnPTool.h>

void DrawHist_IsoMu27overL1() {
  std::unique_ptr<TnPEffTool> tool( new TnPEffTool("ROOTFile_TnPHist_example.root") );

  TH1D* hEff_eta = tool->CalcTnPEff_CutAndCount( "Eta" );
  hEff_eta->Draw();
}