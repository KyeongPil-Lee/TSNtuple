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
  TString fileName_default = "ROOTFile_TnPHist_L3MuonOverL1_default.root";
  TString fileName_0p05 = "ROOTFile_TnPHist_L3MuonOverL1_0p05.root";

  TGraphAsymmErrors* g_default = GetEffGraph(fileName_default, var);
  TGraphAsymmErrors* g_0p05 = GetEffGraph(fileName_0p05, var);

  // -- canvas with ratio
  PlotTool::GraphCanvaswRatio *canvasRatio = new PlotTool::GraphCanvaswRatio("c_vs"+var, 0, 0);
  canvasRatio->Register(g_default, "Menu v2.1", kBlack);
  canvasRatio->Register(g_0p05, "Menu v2.1 + #Delta#eta = 0.05 & #Delta#phi = 0.05", kRed);

  TString titleX = "";
  if( var == "Pt" )  titleX = "P_{T}(#mu) [GeV]";
  if( var == "Eta" ) titleX = "#eta(#mu)";
  if( var == "Phi" ) titleX = "#phi(#mu)";
  if( var == "Vtx" ) titleX = "# vtx";

  canvasRatio->SetTitle( titleX, "Efficiency", "Ratio to menu v2.1");
  canvasRatio->SetLegendPosition( 0.40, 0.82, 0.95, 0.95 );

  // canvasRatio->SetRangeX( 0, 500 );
  canvasRatio->SetRangeY( 0.9, 1.05 );
  canvasRatio->SetRangeRatio( 0.9, 1.1 );

  canvasRatio->Latex_CMSPre();
  canvasRatio->RegisterLatex( 0.16, 0.91, "#font[42]{#scale[0.6]{L3Muon / L1}}");

  canvasRatio->Draw();
}

TGraphAsymmErrors* GetEffGraph( TString fileName, TString var )
{
  std::unique_ptr<TnPEffTool> tool( new TnPEffTool(fileName) );

  TGraphAsymmErrors* gEff = tool->CalcTnPEff_CutAndCount( var );

  return gEff;
}