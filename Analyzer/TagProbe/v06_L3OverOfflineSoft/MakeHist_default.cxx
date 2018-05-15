#include <TagProbe/Setting.h>
#include "MakeHist_L3MuonOverOfflineSoft.h"

void MakeHist_default() {
  TString type = "default";

  std::unique_ptr<HistProducer> histProducer( new HistProducer() );

  histProducer->SetOutputFileName("ROOTFile_TnPHist_L3MuonOverOfflineSoft_"+type+".root");

  vector<TString> rootFilePaths = Setting::rootFilePathsForType( type );
  for( const auto& rootFilePath : rootFilePaths )
    histProducer->AddDataPath(rootFilePath);
  // histProducer->AddDataPath(Setting::rootFilePath_TEST);
  
  histProducer->Set_minPt( 2 ); // -- min pT applied for eta, phi and vtx

  histProducer->Produce();
}
