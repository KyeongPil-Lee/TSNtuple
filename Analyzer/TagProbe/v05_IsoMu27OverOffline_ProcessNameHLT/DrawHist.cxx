#include <TagProbe/TnPTool.h>
// #include <Include/SimplePlotTools.h>

void DrawHistForEachVariable(TString var);
TGraphAsymmErrors* GetEffGraph( TString fileName, TString var );

void DrawHist() {
  DrawHistForEachVariable( "Pt" );
  DrawHistForEachVariable( "Eta" );
  DrawHistForEachVariable( "Phi" );
  DrawHistForEachVariable( "Vtx" );
}

void DrawHistForEachVariable(TString var)
{
  TString fileName_HLT = "ROOTFile_TnPHist_IsoMu27OverOffline_default.root";
  TString fileName_reHLT = "../v04_IsoMu27OverOffline/ROOTFile_TnPHist_IsoMu27OverOffline_default.root";

  TGraphAsymmErrors* g_HLT = GetEffGraph(fileName_HLT, var);
  TGraphAsymmErrors* g_reHLT = GetEffGraph(fileName_reHLT, var);

  // -- canvas with ratio
  PlotTool::GraphCanvaswRatio *canvasRatio = new PlotTool::GraphCanvaswRatio("c_vs"+var, 0, 0);
  canvasRatio->Register(g_HLT, "HLT", kBlack);
  canvasRatio->Register(g_reHLT, "re-HLT", kRed);

  TString titleX = "";
  if( var == "Pt" )  titleX = "P_{T}(#mu) [GeV]";
  if( var == "Eta" ) titleX = "#eta(#mu)";
  if( var == "Phi" ) titleX = "#phi(#mu)";
  if( var == "Vtx" ) titleX = "# vtx";

  canvasRatio->SetTitle( titleX, "Efficiency", "re-HLT/HLT");
  canvasRatio->SetLegendPosition( 0.60, 0.78, 0.95, 0.95 );

  // canvasRatio->SetRangeX( 0, 500 );
  canvasRatio->SetRangeY( 0.6, 1.1 );
  canvasRatio->SetRangeRatio( 0.9, 1.1 );

  canvasRatio->Latex_CMSPre();
  canvasRatio->RegisterLatex( 0.16, 0.91, "#font[42]{#scale[0.6]{IsoMu27 / offline}}");

  canvasRatio->Draw();
}

TGraphAsymmErrors* GetEffGraph( TString fileName, TString var )
{
  std::unique_ptr<TnPEffTool> tool( new TnPEffTool(fileName) );

  TGraphAsymmErrors* gEff = tool->CalcTnPEff_CutAndCount( var );

  return gEff;
}