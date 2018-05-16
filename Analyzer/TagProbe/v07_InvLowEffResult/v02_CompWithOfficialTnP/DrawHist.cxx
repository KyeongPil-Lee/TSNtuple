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
  TString fileName_ref = "ROOTFile_EfficiencyGraphs_IsoMu27.root";
  TString fileName_my = "../../v05_IsoMu27OverOffline_ProcessNameHLT/ROOTFile_TnPHist_IsoMu27OverOffline_default.root";

  TString str_var = "";
  if( var == "Pt" ) str_var = "pt";
  if( var == "Eta" ) str_var = "eta";
  if( var == "Phi" ) str_var = "phi";
  if( var == "Vtx" ) str_var = "vtx";
  TGraphAsymmErrors* g_ref = PlotTool::Get_Graph(fileName_ref, "Data_IsoMu27_from_Tight2012_and_dBeta_015_"+str_var);
  TGraphAsymmErrors* g_my = GetEffGraph(fileName_my, var);

  // -- canvas
  PlotTool::GraphCanvas *canvas = new PlotTool::GraphCanvas("c_vs"+var, 0, 0);
  canvas->Register(g_ref, "Official T&P", kBlack);
  canvas->Register(g_my, "Priviate T&P", kRed);

  TString titleX = "";
  if( var == "Pt" )  titleX = "P_{T}(#mu) [GeV]";
  if( var == "Eta" ) titleX = "#eta(#mu)";
  if( var == "Phi" ) titleX = "#phi(#mu)";
  if( var == "Vtx" ) titleX = "# vtx";

  canvas->SetTitle( titleX, "Efficiency");
  canvas->SetLegendPosition( 0.60, 0.78, 0.95, 0.95 );

  canvas->SetRangeY( 0.6, 1.1 );

  canvas->Latex_CMSPre();
  canvas->RegisterLatex( 0.75, 0.96, "#font[42]{#scale[0.8]{Run 316110}}");
  canvas->RegisterLatex( 0.16, 0.91, "#font[42]{#scale[0.6]{IsoMu27 / Offline}}");
  canvas->RegisterLatex( 0.16, 0.87, "#font[42]{#scale[0.6]{(Old muon reco.)}}");

  canvas->Draw();


  // // -- canvas with ratio
  // PlotTool::GraphCanvaswRatio *canvasRatio = new PlotTool::GraphCanvaswRatio("c_vs"+var, 0, 0);
  // canvasRatio->Register(g_ref, "Official T&P", kBlack);
  // canvasRatio->Register(g_my, "Priviate T&P", kRed);

  // TString titleX = "";
  // if( var == "Pt" )  titleX = "P_{T}(#mu) [GeV]";
  // if( var == "Eta" ) titleX = "#eta(#mu)";
  // if( var == "Phi" ) titleX = "#phi(#mu)";
  // if( var == "Vtx" ) titleX = "# vtx";

  // canvasRatio->SetTitle( titleX, "Efficiency", "Private/Official");
  // canvasRatio->SetLegendPosition( 0.60, 0.78, 0.95, 0.95 );

  // // canvasRatio->SetRangeX( 0, 500 );
  // canvasRatio->SetRangeY( 0.6, 1.1 );
  // canvasRatio->SetRangeRatio( 0.9, 1.1 );

  // canvasRatio->Latex_CMSPre();
  // canvasRatio->RegisterLatex( 0.75, 0.96, "#font[42]{#scale[0.8]{Run 316110}}");
  // canvasRatio->RegisterLatex( 0.16, 0.91, "#font[42]{#scale[0.6]{IsoMu27 / Offline}}");
  // canvasRatio->RegisterLatex( 0.16, 0.87, "#font[42]{#scale[0.6]{(Old muon reco.)}}");

  // canvasRatio->Draw();
}

TGraphAsymmErrors* GetEffGraph( TString fileName, TString var )
{
  std::unique_ptr<TnPEffTool> tool( new TnPEffTool(fileName) );

  TGraphAsymmErrors* gEff = tool->CalcTnPEff_CutAndCount( var );

  return gEff;
}