#include <TagProbe/TnPTool.h>

void DrawHistForEachVariable(TString menu, TString var, Bool_t setZoomIn = kFALSE);
TGraphAsymmErrors* GetEffGraph( TString fileName, TString var );
void HotFix( TString menu, TString var, TGraphAsymmErrors* g_Iso, TGraphAsymmErrors* g_NonIso );

void DrawHist_Iso_NonIso() {
  DrawHistForEachVariable( "2p0", "Pt" );
  DrawHistForEachVariable( "2p0", "Pt", kTRUE );
  DrawHistForEachVariable( "2p0", "Eta" );
  DrawHistForEachVariable( "2p0", "Phi" );
  DrawHistForEachVariable( "2p0", "Vtx" );

  DrawHistForEachVariable( "2p1", "Pt" );
  DrawHistForEachVariable( "2p1", "Pt", kTRUE );
  DrawHistForEachVariable( "2p1", "Eta" );
  DrawHistForEachVariable( "2p1", "Phi" );
  DrawHistForEachVariable( "2p1", "Vtx" );
}

void DrawHistForEachVariable(TString menu, TString var, Bool_t setZoomIn = kFALSE)
{
  TString fileName_Iso = "ROOTFile_TnPHist_menu"+menu+".root";
  TString fileName_NonIso = "../v01_Mu5_over_LooseNonIso/ROOTFile_TnPHist_menu"+menu+".root";

  TGraphAsymmErrors* g_Iso = GetEffGraph(fileName_Iso, var);
  TGraphAsymmErrors* g_NonIso = GetEffGraph(fileName_NonIso, var);

  HotFix( menu, var, g_Iso, g_NonIso );

  // -- canvas with ratio
  TString canvasName = "c_Iso_NonIso_"+menu+"_vs"+var;
  if( setZoomIn ) canvasName = canvasName + "_zoomIn";
  PlotTool::GraphCanvaswRatio *canvasRatio = new PlotTool::GraphCanvaswRatio(canvasName, 0, 0);
  canvasRatio->Register(g_Iso, "Mu5 / L1SingleMu3 + LooseID + PFIso(d#beta)/P_{T} < 0.25", kGreen+2);
  canvasRatio->Register(g_NonIso, "Mu5 / L1SingleMu3 + LooseID + PFIso(d#beta)/P_{T} > 0.25", kViolet);

  TString titleX = "";
  if( var == "Pt" )  titleX = "P_{T}(#mu) [GeV]";
  if( var == "Eta" ) titleX = "#eta(#mu)";
  if( var == "Phi" ) titleX = "#phi(#mu)";
  if( var == "Vtx" ) titleX = "# vtx";

  canvasRatio->SetTitle( titleX, "Efficiency", "NonIso/Iso");
  canvasRatio->SetLegendPosition( 0.13, 0.32, 0.93, 0.45 );
  // canvasRatio->SetLegendColumn(2);

  if( var == "Pt" && !setZoomIn ) canvasRatio->SetRangeX(0, 200);
  if( var == "Pt" && setZoomIn )  canvasRatio->SetRangeX(5, 40);
  if( var == "Vtx" )              canvasRatio->SetRangeX(10, 60);

  canvasRatio->SetRangeY( 0.8, 1.05 );
  if( var == "Pt" && !setZoomIn) canvasRatio->SetRangeY( 0, 1.1 );

  canvasRatio->SetRangeRatio( 0.85, 1.15 );

  canvasRatio->Latex_CMSPre();


  TString info_menu = "";
  if( menu == "2p0" ) info_menu = "Menu v2.0";
  if( menu == "2p1" ) info_menu = "Menu v2.1";
  canvasRatio->RegisterLatex( 0.60, 0.96, "#font[42]{#scale[0.6]{Run316361-316362 (79 pb^{-1})}}");
  canvasRatio->RegisterLatex( 0.16, 0.91, "#font[42]{#scale[0.6]{"+info_menu+"}}");
  if( var != "Pt" )
    canvasRatio->RegisterLatex( 0.16, 0.87, "#font[42]{#scale[0.6]{P_{T} > 6 GeV}}");

  canvasRatio->Draw();
}

TGraphAsymmErrors* GetEffGraph( TString fileName, TString var )
{
  std::unique_ptr<TnPEffTool> tool( new TnPEffTool(fileName) );

  TGraphAsymmErrors* gEff = tool->CalcTnPEff_CutAndCount( var );

  return gEff;
}

void HotFix( TString menu, TString var, TGraphAsymmErrors* g_Iso, TGraphAsymmErrors* g_NonIso )
{
  if( menu == "2p0" )
  {
    if( var == "Pt" )
      g_Iso->RemovePoint(16); // -- last bin

    if( var == "Vtx" )
    {
      g_Iso->RemovePoint(0);
      g_Iso->RemovePoint(0);
    }
  }

  if( menu == "2p1" )
  {
    if( var == "Pt" )
      g_Iso->RemovePoint(16); // -- last bin

    if( var == "Vtx" )
    {
      g_Iso->RemovePoint(0);
      g_Iso->RemovePoint(0);
    }
  }
}