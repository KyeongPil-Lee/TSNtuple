#include "MakeHist.h"

void MakeHist_beforeUpdate()
{
  std::unique_ptr<HistProducer> histProducer( new HistProducer() );
  histProducer->SetOutputFileName("ROOTFile_TnPHist_beforeUpdate.root");

  TString rootFilePath = "/u/user/kplee/SE_UserHome/SingleMuon/crab_TSNtuple_v20180910_SingleMuon_Run2018D_Run322356_DCSOnly_Menuv3p4/180911_110630/0000/*.root";
  histProducer->AddDataPath( rootFilePath );

  histProducer->Set_minPt( 24 ); // -- min pT applied for eta, phi and vtx. 24: due to L1SingleMu22

  histProducer->Produce();
}