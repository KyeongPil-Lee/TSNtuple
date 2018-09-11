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
  TString fileName1 = "ROOTFile_TnPHist_beforeUpdate.root";
  TString fileName2 = "ROOTFile_TnPHist_afterUpdate.root"; // -- can be replaced by the other root file

  TGraphAsymmErrors* g1 = GetEffGraph(fileName1, var);
  TGraphAsymmErrors* g2 = GetEffGraph(fileName2, var);

  // -- canvas with ratio
  TString canvasName = "c_vs"+var;
  if( setZoomIn ) canvasName = canvasName + "_zoomIn";
  PlotTool::GraphCanvaswRatio *canvasRatio = new PlotTool::GraphCanvaswRatio(canvasName, 0, 0);
  canvasRatio->Register(g1, "Before OI update (Run 322356)", kBlack);
  canvasRatio->Register(g2, "After OI update (Run 322381)", kBlue);

  TString titleX = "";
  if( var == "Pt" )  titleX = "P_{T}(#mu) [GeV]";
  if( var == "Eta" ) titleX = "#eta(#mu)";
  if( var == "Phi" ) titleX = "#phi(#mu)";
  if( var == "Vtx" ) titleX = "# vtx";

  canvasRatio->SetTitle( titleX, "Efficiency", "After/Before");
  canvasRatio->SetLegendPosition( 0.60, 0.32, 0.95, 0.45 );
  // canvasRatio->SetLegendColumn(2);

  if( var == "Pt" && setZoomIn ) canvasRatio->SetRangeX(24, 120);

  canvasRatio->SetRangeY( 0.6, 1.1 );
  if( var == "Pt" && !setZoomIn) canvasRatio->SetRangeY( 0, 1.25 );

  canvasRatio->SetRangeRatio( 0.85, 1.15 );

  canvasRatio->Latex_CMSPre();


  canvasRatio->RegisterLatex( 0.76, 0.96, "#font[42]{#scale[0.7]{2018, 13 TeV}}" );
  canvasRatio->RegisterLatex( 0.16, 0.91, "#font[42]{#scale[0.6]{OIFromL2 / L1}}");
  if( var != "Pt" )
    canvasRatio->RegisterLatex( 0.16, 0.865, "#font[42]{#scale[0.6]{P_{T} > 24 GeV}}");

  canvasRatio->Draw();
}

TGraphAsymmErrors* GetEffGraph( TString fileName, TString var )
{
  std::unique_ptr<TnPEffTool> tool( new TnPEffTool(fileName) );

  TGraphAsymmErrors* gEff = tool->CalcTnPEff_CutAndCount( var );

  return gEff;
}