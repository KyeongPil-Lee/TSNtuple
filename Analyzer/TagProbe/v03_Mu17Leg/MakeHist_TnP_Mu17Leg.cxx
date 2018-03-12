#include <TagProbe/v03_Mu17Leg/MakeHist_TnP_Mu17Leg.h>

void MakeHist_TnP_Mu17Leg(TString dataPath, TString outputFileName )
{
	HistProducer* producer = new HistProducer();
	producer->SetOutputFileName( outputFileName );
	producer->AddDataPath(dataPath);
	producer->Produce();
}