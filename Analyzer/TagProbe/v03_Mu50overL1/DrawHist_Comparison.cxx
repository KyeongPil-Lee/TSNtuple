#include <TagProbe/TnPTool.h>

void DrawHistForEachVariable(TString var, Bool_t setZoomIn = kFALSE);
TGraphAsymmErrors* GetEffGraph( TString fileName, TString var );

void DrawHist_Comparison() {
  DrawHistForEachVariable( "Pt" );
  DrawHistForEachVariable( "Pt", kTRUE );
  DrawHistForEachVariable( "Eta" );
  DrawHistForEachVariable( "Phi" );
  DrawHistForEachVariable( "Vtx" );
}

void DrawHistForEachVariable(TString var, Bool_t setZoomIn = kFALSE)
{
  TString fileName1 = "ROOTFile_TnPHist_Default.root";
  TString fileName2 = "ROOTFile_TnPHist_KBMTF.root"; // -- can be replaced by the other root file

  TGraphAsymmErrors* g1 = GetEffGraph(fileName1, var);
  TGraphAsymmErrors* g2 = GetEffGraph(fileName2, var);

  // -- canvas with ratio
  TString canvasName = "c_vs"+var;
  if( setZoomIn ) canvasName = canvasName + "_zoomIn";
  PlotTool::GraphCanvaswRatio *canvasRatio = new PlotTool::GraphCanvaswRatio(canvasName, 0, 0);
  canvasRatio->Register(g1, "Default BTMF", kBlack);
  canvasRatio->Register(g2, "BMTF with Kalman", kBlue);

  TString titleX = "";
  if( var == "Pt" )  titleX = "P_{T}(#mu) [GeV]";
  if( var == "Eta" ) titleX = "#eta(#mu)";
  if( var == "Phi" ) titleX = "#phi(#mu)";
  if( var == "Vtx" ) titleX = "# vtx";

  canvasRatio->SetTitle( titleX, "Efficiency", "kBMTF/default");
  canvasRatio->SetLegendPosition( 0.60, 0.32, 0.95, 0.45 );
  // canvasRatio->SetLegendColumn(2);

  if( var == "Pt" && setZoomIn ) canvasRatio->SetRangeX(50, 120);

  canvasRatio->SetRangeY( 0.8, 1.05 );
  if( var == "Pt" && !setZoomIn) canvasRatio->SetRangeY( 0, 1.1 );

  canvasRatio->SetRangeRatio( 0.85, 1.15 );

  canvasRatio->Latex_CMSPre();


  canvasRatio->RegisterLatex( 0.60, 0.96, "#font[42]{#scale[0.6]{Run322625 (~340 pb^{-1})}}");
  canvasRatio->RegisterLatex( 0.16, 0.91, "#font[42]{#scale[0.6]{Mu50 / L1}}");
  if( var != "Pt" )
    canvasRatio->RegisterLatex( 0.16, 0.87, "#font[42]{#scale[0.6]{P_{T} > 52 GeV}}");

  canvasRatio->Draw();
}

TGraphAsymmErrors* GetEffGraph( TString fileName, TString var )
{
  std::unique_ptr<TnPEffTool> tool( new TnPEffTool(fileName) );

  TGraphAsymmErrors* gEff = tool->CalcTnPEff_CutAndCount( var );

  return gEff;
}