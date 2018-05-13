#include "MakeHist_IsoMu27overL1.h"

void MakeHist_IsoMu27overL1() {
  std::unique_ptr<HistProducer> histProducer( new HistProducer() );
  histProducer->SetOutputFileName("ROOTFile_TnPHist_IsoMu27overL1_Default.root");

  TString rootFilePath = "/Users/KyeongPil_Lee/ServiceWorks/MuonHLT/v20180507_v01_UpdateTnPCode/TSNtuple/Analyzer/TagProbe/ExampleCodes/ntuple_9.root";
  
  histProducer->AddDataPath(rootFilePath);
  histProducer->Set_minPt( 29 ); // -- min pT applied for eta, phi and vtx

  histProducer->Produce();
}
