#include <TagProbe/v04_Mu8Leg/MakeHist_TnP_Mu8Leg.h>

void MakeHist_TnP_Mu8Leg()
{
	TString basePath = "/u/user/kplee/SE_UserHome/SingleMuon";
	TString dataPath = basePath + "/crab_TSntuple_v20180311_DimuonLeg_SingleMuon_Run2017Fv1_Run305636_Default/180311_021428/0000/*.root";
	TString outputFileName = "ROOTFile_Default.root";

	HistProducer* producer = new HistProducer();
	producer->SetOutputFileName( outputFileName );
	producer->AddDataPath(dataPath);
	producer->Produce();
}