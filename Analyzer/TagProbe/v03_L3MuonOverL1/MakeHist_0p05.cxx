#include <TagProbe/Setting.h>
#include "MakeHist_L3MuonOverL1.h"

void MakeHist_0p05() {
  TString type = "0p05";

  std::unique_ptr<HistProducer> histProducer( new HistProducer() );

  histProducer->SetOutputFileName("ROOTFile_TnPHist_L3MuonOverL1_"+type+".root");

  vector<TString> rootFilePaths = Setting::rootFilePathsForType( type );
  for( const auto& rootFilePath : rootFilePaths )
    histProducer->AddDataPath(rootFilePath);
  
  histProducer->Set_minPt( 29 ); // -- min pT applied for eta, phi and vtx

  histProducer->Produce();
}