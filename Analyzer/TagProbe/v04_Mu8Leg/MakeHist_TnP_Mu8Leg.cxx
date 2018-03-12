#include <TagProbe/v04_Mu8Leg/MakeHist_TnP_Mu8Leg.h>

void MakeHist_TnP_Mu8Leg(TString dataPath, TString outputFileName )
{
	HistProducer* producer = new HistProducer();
	producer->SetOutputFileName( outputFileName );
	producer->AddDataPath(dataPath);
	producer->Produce();
}