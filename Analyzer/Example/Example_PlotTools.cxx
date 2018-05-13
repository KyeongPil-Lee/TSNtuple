#include <Include/SimplePlotTools.h>

void Example_Histogram();
void Example_Graph();

void Example_PlotTools() {
  Example_Histogram();
  Example_Graph();
}

void Example_Histogram() {
  TString fileName = "TestFile_Histogram.root";

  // -- MET distribution
  TH1D* h_gen    = PlotTool::Get_Hist( fileName, "myMHMETAnalyzer/h_genMET" );
  TH1D* h_online = PlotTool::Get_Hist( fileName, "myMHMETAnalyzer/h_onlinePFMET");

  // -- canvas without ratio
  PlotTool::HistCanvas *canvas = new PlotTool::HistCanvas("c_METPlots", 0, 0);
  canvas->Register( h_gen, "Gen-MET", kBlack);
  canvas->Register( h_online, "online PFMET (old muon reco.)", kRed);

  canvas->SetTitle( "MET [GeV]", "Events");
  canvas->SetLegendPosition( 0.40, 0.72, 0.95, 0.95 );
  canvas->SetRangeX( 0, 500 );
  canvas->SetRangeY( 0, 600 );
  canvas->SetRebin( 10 );

  canvas->Latex_CMSPre();
  // canvas->Latex_CMSPre(35.9, 13);
  // canvas->Latex_CMSSim();
  canvas->RegisterLatex( 0.16, 0.91, "#font[42]{#scale[0.6]{MET comparison}}");

  canvas->Draw();


  // -- canvas with ratio
  PlotTool::HistCanvaswRatio *canvasRatio = new PlotTool::HistCanvaswRatio("c_METPlotswRatio", 0, 0);
  canvasRatio->Register( h_gen, "Gen-MET", kBlack);
  canvasRatio->Register( h_online, "online PFMET (old muon reco.)", kRed);

  canvasRatio->SetTitle( "MET [GeV]", "Events", "Ratio to Gen");
  canvasRatio->SetLegendPosition( 0.40, 0.72, 0.95, 0.95 );
  canvasRatio->SetRangeX( 0, 500 );
  canvasRatio->SetRangeY( 0, 600 );
  canvasRatio->SetRangeRatio( 0, 2.5 );
  canvasRatio->SetRebin( 10 );

  canvasRatio->Latex_CMSPre();
  // canvasRatio->Latex_CMSPre(35.9, 13);
  // canvasRatio->Latex_CMSSim();
  canvasRatio->RegisterLatex( 0.16, 0.91, "#font[42]{#scale[0.6]{MET comparison}}");

  canvasRatio->Draw();
}

void Example_Graph() {
  TString fileName = "TestFile_Graph.root";
  TGraphAsymmErrors* g_abseta0 = PlotTool::Get_Graph(fileName, "Data_IsoMu27_from_Tight2012_and_dBeta_015_pteta_abseta0");
  TGraphAsymmErrors* g_abseta1 = PlotTool::Get_Graph(fileName, "Data_IsoMu27_from_Tight2012_and_dBeta_015_pteta_abseta1");
  TGraphAsymmErrors* g_abseta2 = PlotTool::Get_Graph(fileName, "Data_IsoMu27_from_Tight2012_and_dBeta_015_pteta_abseta2");
  TGraphAsymmErrors* g_abseta3 = PlotTool::Get_Graph(fileName, "Data_IsoMu27_from_Tight2012_and_dBeta_015_pteta_abseta3");

  PlotTool::GraphCanvas *canvas = new PlotTool::GraphCanvas("c_IsoMu27EffvsPt", 0, 0);
  canvas->Register(g_abseta0, "|#eta| < 0.9", kBlack);
  canvas->Register(g_abseta1, "0.9 < |#eta| < 1.2", kBlue);
  canvas->Register(g_abseta2, "1.2 < |#eta| < 2.1", kGreen);
  canvas->Register(g_abseta3, "2.1 < |#eta| < 2.4", kRed);

  canvas->SetTitle( "P_{T}(#mu) [GeV]", "Efficiency");
  canvas->SetLegendPosition( 0.60, 0.78, 0.95, 0.95 );
   // canvas->SetRangeX( 0, 500 );
  canvas->SetRangeY( 0.5, 1.1 );

  canvas->Latex_CMSPre();
  // canvas->Latex_CMSPre(35.9, 13);
  // canvas->Latex_CMSSim();
  canvas->RegisterLatex( 0.16, 0.91, "#font[42]{#scale[0.6]{Run2017B-F, Rereco(17Nov2017)}}");
  canvas->RegisterLatex( 0.16, 0.87, "#font[42]{#scale[0.6]{IsoMu27 / offline}}");

  canvas->Draw();


  // -- canvas with ratio
  PlotTool::GraphCanvaswRatio *canvasRatio = new PlotTool::GraphCanvaswRatio("c_IsoMu27EffvsPtwRatio", 0, 0);
  canvasRatio->Register(g_abseta0, "|#eta| < 0.9", kBlack);
  canvasRatio->Register(g_abseta1, "0.9 < |#eta| < 1.2", kBlue);
  canvasRatio->Register(g_abseta2, "1.2 < |#eta| < 2.1", kGreen);
  canvasRatio->Register(g_abseta3, "2.1 < |#eta| < 2.4", kRed);

  canvasRatio->SetTitle( "P_{T}(#mu) [GeV]", "Efficiency", "Ratio to black");
  canvasRatio->SetLegendPosition( 0.60, 0.78, 0.95, 0.95 );

  // canvasRatio->SetRangeX( 0, 500 );
  canvasRatio->SetRangeY( 0.5, 1.1 );
  canvasRatio->SetRangeRatio( 0.7, 1.1 );


  canvasRatio->Latex_CMSPre();
  // canvasRatio->Latex_CMSPre(35.9, 13);
  // canvasRatio->Latex_CMSSim();
  canvasRatio->RegisterLatex( 0.16, 0.91, "#font[42]{#scale[0.6]{Run2017B-F, Rereco(17Nov2017)}}");
  canvasRatio->RegisterLatex( 0.16, 0.87, "#font[42]{#scale[0.6]{IsoMu27 / offline}}");

  canvasRatio->Draw();
}