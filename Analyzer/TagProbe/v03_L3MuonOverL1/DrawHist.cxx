#include <TagProbe/TnPTool.h>
// #include <Include/SimplePlotTools.h>

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
  TString fileName_default = "ROOTFile_TnPHist_L3MuonOverL1_default.root";
  TString fileName_90 = "ROOTFile_TnPHist_L3MuonOverL1_90.root";
  TString fileName_80 = "ROOTFile_TnPHist_L3MuonOverL1_80.root";
  TString fileName_70 = "ROOTFile_TnPHist_L3MuonOverL1_70.root";
  TString fileName_60 = "ROOTFile_TnPHist_L3MuonOverL1_60.root";
  TString fileName_50 = "ROOTFile_TnPHist_L3MuonOverL1_50.root";
  TString fileName_0p05 = "ROOTFile_TnPHist_L3MuonOverL1_0p05.root";


  TGraphAsymmErrors* g_default = GetEffGraph(fileName_default, var);
  TGraphAsymmErrors* g_90 = GetEffGraph(fileName_90, var);
  TGraphAsymmErrors* g_80 = GetEffGraph(fileName_80, var);
  TGraphAsymmErrors* g_70 = GetEffGraph(fileName_70, var);
  TGraphAsymmErrors* g_60 = GetEffGraph(fileName_60, var);
  TGraphAsymmErrors* g_50 = GetEffGraph(fileName_50, var);
  TGraphAsymmErrors* g_0p05 = GetEffGraph(fileName_0p05, var);

  // -- canvas with ratio
  TString canvasName = "c_vs"+var;
  if( setZoomIn ) canvasName = canvasName + "_zoomIn";
  PlotTool::GraphCanvaswRatio *canvasRatio = new PlotTool::GraphCanvaswRatio(canvasName, 0, 0);
  canvasRatio->Register(g_default, "Menu v2.1 (default)", kBlack);
  canvasRatio->Register(g_90, "default * 90%", kGreen+2);
  canvasRatio->Register(g_80, "default * 80%", kBlue);
  canvasRatio->Register(g_70, "default * 70%", kViolet);
  canvasRatio->Register(g_60, "default * 60%", kCyan);
  canvasRatio->Register(g_50, "default * 50%", kOrange+2);
  canvasRatio->Register(g_0p05, "#Delta#eta = 0.05 & #Delta#phi = 0.05", kRed);

  TString titleX = "";
  if( var == "Pt" )  titleX = "P_{T}(#mu) [GeV]";
  if( var == "Eta" ) titleX = "#eta(#mu)";
  if( var == "Phi" ) titleX = "#phi(#mu)";
  if( var == "Vtx" ) titleX = "# vtx";

  canvasRatio->SetTitle( titleX, "Efficiency", "Ratio to default");
  canvasRatio->SetLegendPosition( 0.25, 0.32, 0.95, 0.47 );
  canvasRatio->SetLegendColumn(2);

  if( var == "Pt" && setZoomIn ) canvasRatio->SetRangeX(29, 500);
  canvasRatio->SetRangeY( 0.85, 1.05 );
  // if( var == "Pt" ) canvasRatio->SetRangeY( 0, 1.1 );
  canvasRatio->SetRangeRatio( 0.97, 1.03 );

  canvasRatio->Latex_CMSPre();
  // -- https://cmswbm.cern.ch/cmsdb/servlet/RunSummary?RUN=316110
  canvasRatio->RegisterLatex( 0.67, 0.96, "#font[42]{#scale[0.7]{Run305636 (92 pb^{-1})}}");
  if( var == "Pt" )
    canvasRatio->RegisterLatex( 0.16, 0.91, "#font[42]{#scale[0.6]{L3(before filter) / L1}}");
  else
    canvasRatio->RegisterLatex( 0.16, 0.91, "#font[42]{#scale[0.6]{L3(before filter) / L1 (P_{T} > 29 GeV)}}");

  canvasRatio->Draw();
}

TGraphAsymmErrors* GetEffGraph( TString fileName, TString var )
{
  std::unique_ptr<TnPEffTool> tool( new TnPEffTool(fileName) );

  TGraphAsymmErrors* gEff = tool->CalcTnPEff_CutAndCount( var );

  return gEff;
}