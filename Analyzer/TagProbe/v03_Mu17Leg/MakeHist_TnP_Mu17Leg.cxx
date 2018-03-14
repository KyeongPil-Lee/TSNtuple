#include <TagProbe/v03_Mu17Leg/MakeHist_TnP_Mu17Leg.h>

void MakeHist_TnP_Mu17Leg()
{
	TString basePath = "/u/user/kplee/SE_UserHome/SingleMuon";
	TString dataPath = "";
	TString outputFileName = "ROOTFile_Default.root";

	HistProducer* producer = new HistProducer();
	producer->SetOutputFileName( outputFileName );

	// dataPath = basePath + "/crab_TSntuple_v20180311_DimuonLeg_SingleMuon_Run2017Fv1_Run305636_Default/180311_021428/0000/*.root";
	// producer->AddDataPath(dataPath);

	dataPath = basePath + "/crab_TSntuple_v20180311_DimuonLeg_SingleMuon_Run2017Fv1_Run30832to62_Default/180311_150618/0000/*.root";
	producer->AddDataPath(dataPath);

	producer->SetNEvent(1000000); // -- prevent memory problem
	
	producer->Produce();
}