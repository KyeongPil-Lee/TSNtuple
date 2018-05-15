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
  TString fileName_2017 = "ROOTFile_TnPHist_IsoMu27OverOffline_0p05.root";
  TString fileName_2018 = "/Users/KyeongPil_Lee/ServiceWorks/MuonHLT/v20180513_v01_OptimizeIO/TSNtuple/Analyzer/TagProbe/v04_IsoMu27OverOffline/ROOTFile_TnPHist_IsoMu27OverOffline_default.root";

  TGraphAsymmErrors* g_2017 = GetEffGraph(fileName_2017, var);
  TGraphAsymmErrors* g_2018 = GetEffGraph(fileName_2018, var);

  // -- canvas with ratio
  PlotTool::GraphCanvaswRatio *canvasRatio = new PlotTool::GraphCanvaswRatio("c_vs"+var, 0, 0);
  canvasRatio->Register(g_2017, "2017 (Old muon reco.)", kBlack);
  canvasRatio->Register(g_2018, "2018 (New muon reco.)", kRed);

  TString titleX = "";
  if( var == "Pt" )  titleX = "P_{T}(#mu) [GeV]";
  if( var == "Eta" ) titleX = "#eta(#mu)";
  if( var == "Phi" ) titleX = "#phi(#mu)";
  if( var == "Vtx" ) titleX = "# vtx";

  canvasRatio->SetTitle( titleX, "Efficiency", "2018/2017");
  canvasRatio->SetLegendPosition( 0.60, 0.78, 0.95, 0.95 );

  // canvasRatio->SetRangeX( 0, 500 );
  canvasRatio->SetRangeY( 0.9, 1.05 );
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