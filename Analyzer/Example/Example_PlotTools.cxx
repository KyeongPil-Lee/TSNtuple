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

  canvasRatio->Draw();
}

void Example_Graph() {
  

}