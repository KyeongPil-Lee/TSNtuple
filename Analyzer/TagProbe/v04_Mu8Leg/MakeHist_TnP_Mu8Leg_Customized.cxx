#include <TagProbe/v04_Mu8Leg/MakeHist_TnP_Mu8Leg.h>

void MakeHist_TnP_Mu8Leg_Customized()
{
	TString basePath = "/u/user/kplee/SE_UserHome/SingleMuon";
	TString dataPath = "";
	TString outputFileName = "ROOTFile_Customized.root";

	HistProducer* producer = new HistProducer();
	producer->SetOutputFileName( outputFileName );

	// dataPath = basePath + "/crab_TSntuple_v20180311_DimuonLeg_SingleMuon_Run2017Fv1_Run305636_Customized/180311_021441/0000/*.root";
	// producer->AddDataPath(dataPath);

	dataPath = basePath + "/crab_TSntuple_v20180311_DimuonLeg_SingleMuon_Run2017Fv1_Run30832to62_Customized/180311_150642/0000/*.root";
	producer->AddDataPath(dataPath);

	producer->SetNEvent(1000000); // -- prevent memory problem
	producer->Produce();
}