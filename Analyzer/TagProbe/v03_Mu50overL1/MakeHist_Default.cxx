#include "MakeHist.h"
#include <TagProbe/Setting.h>

void MakeHist_Default()
{
  std::unique_ptr<HistProducer> histProducer( new HistProducer() );
  histProducer->SetOutputFileName("ROOTFile_TnPHist_Default.root");

  TString dataPath = Setting::dataPath_Default;
  histProducer->AddDataPath(dataPath);

  // histProducer->AddDataPath("/Users/KyeongPil_Lee/ServiceWorks/MuonHLT/v20180507_v01_UpdateTnPCode/TSNtuple/Analyzer/TagProbe/ExampleCodes/ntuple_9.root");

  histProducer->Set_minPt( 52 ); // -- min pT applied for eta, phi and vtx

  histProducer->Produce();
}
