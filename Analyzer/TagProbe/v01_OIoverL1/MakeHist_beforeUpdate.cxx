#include "MakeHist.h"

void MakeHist_beforeUpdate()
{
  std::unique_ptr<HistProducer> histProducer( new HistProducer() );
  histProducer->SetOutputFileName("ROOTFile_TnPHist_beforeUpdate.root");

  rootFilePath = "";
  histProducer->AddDataPath( rootFilePath );

  histProducer->Set_minPt( 24 ); // -- min pT applied for eta, phi and vtx. 24: due to L1SingleMu22

  histProducer->Produce();
}