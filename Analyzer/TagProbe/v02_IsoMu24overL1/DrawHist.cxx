#include <TagProbe/TnPTool.h>

void DrawHistForEachVariable(TString var, Bool_t setZoomIn = kFALSE);
TGraphAsymmErrors* GetEffGraph( TString fileName, TString var );

void DrawHist() {
  DrawHistForEachVariable( "Pt" );
  DrawHistForEachVariable( "Pt", kTRUE );
  DrawHistForEachVariable( "Eta" );
  DrawHistForEachVariable( "Phi" );
  DrawHistForEachVariable( "Vtx" );
}

void DrawHistForEachVariable(TString var, Bool_t setZoomIn = kFALSE)
{
  TString fileName1 = "ROOTFile_TnPHist_standard.root";
  TString fileName2 = "ROOTFile_TnPHist_optiForEff.root";
  TString fileName3 = "ROOTFile_TnPHist_optiForTim.root";

  TGraphAsymmErrors* g1 = GetEffGraph(fileName1, var);
  TGraphAsymmErrors* g2 = GetEffGraph(fileName2, var);
  TGraphAsymmErrors* g3 = GetEffGraph(fileName3, var);

  // -- canvas with ratio
  TString canvasName = "c_vs"+var;
  if( setZoomIn ) canvasName = canvasName + "_zoomIn";
  PlotTool::GraphCanvaswRatio *canvasRatio = new PlotTool::GraphCanvaswRatio(canvasName, 0, 0);
  canvasRatio->Register(g1, "Before update", kBlack);
  canvasRatio->Register(g2, "Optimized for Efficiency", kBlue);
  canvasRatio->Register(g3, "Optimized for Timing", kGreen+2);

  TString titleX = "";
  if( var == "Pt" )  titleX = "P_{T}(#mu) [GeV]";
  if( var == "Eta" ) titleX = "#eta(#mu)";
  if( var == "Phi" ) titleX = "#phi(#mu)";
  if( var == "Vtx" ) titleX = "# vtx";

  canvasRatio->SetTitle( titleX, "Efficiency", "Ratio to black");
  canvasRatio->SetLegendPosition( 0.50, 0.32, 0.95, 0.45 );
  // canvasRatio->SetLegendColumn(2);

  if( var == "Pt" && setZoomIn )  canvasRatio->SetRangeX(29, 120);
  if( var == "Pt" && !setZoomIn ) canvasRatio->SetRangeX(0,  500);

  canvasRatio->SetRangeY( 0.8, 1.05 );
  if( var == "Pt" && !setZoomIn) canvasRatio->SetRangeY( 0, 1.1 );

  canvasRatio->SetRangeRatio( 0.85, 1.15 );

  canvasRatio->Latex_CMSPre();


  canvasRatio->RegisterLatex( 0.64, 0.96, "#font[42]{#scale[0.6]{Run318820-76 (250 pb^{-1})}}");
  canvasRatio->RegisterLatex( 0.16, 0.91, "#font[42]{#scale[0.6]{IsoMu27 / L1SingleMu22}}");
  if( var != "Pt" )
    canvasRatio->RegisterLatex( 0.16, 0.87, "#font[42]{#scale[0.6]{P_{T} > 29 GeV}}");

  canvasRatio->Draw();
}

TGraphAsymmErrors* GetEffGraph( TString fileName, TString var )
{
  std::unique_ptr<TnPEffTool> tool( new TnPEffTool(fileName) );

  TGraphAsymmErrors* gEff = tool->CalcTnPEff_CutAndCount( var );

  return gEff;
}