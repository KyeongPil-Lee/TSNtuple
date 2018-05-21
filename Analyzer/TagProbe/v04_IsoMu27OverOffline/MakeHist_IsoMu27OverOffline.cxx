#include <TagProbe/Setting.h>
#include "MakeHist_IsoMu27OverOffline.h"

void MakeHist_IsoMu27OverOffline(TString type) {
  std::unique_ptr<HistProducer> histProducer( new HistProducer() );

  histProducer->SetOutputFileName("ROOTFile_TnPHist_IsoMu27OverOffline_"+type+".root");

  vector<TString> rootFilePaths = Setting::rootFilePathsForType( type );
  for( const auto& rootFilePath : rootFilePaths )
    histProducer->AddDataPath(rootFilePath);
  
  histProducer->Set_minPt( 29 ); // -- min pT applied for eta, phi and vtx

  histProducer->Produce();
}
