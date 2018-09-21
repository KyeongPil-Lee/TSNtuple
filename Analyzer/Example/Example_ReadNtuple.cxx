#include <Include/Object.h>
#include <iostream>
using namespace std;

void Example_ReadNtuple()
{
	TChain *chain = new TChain("ntupler/ntuple");
	// chain->Add("Local/ntuple_withoutFix.root");
	// chain->Add("/Users/KyeongPil_Lee/ServiceWorks/TriggerStudyNtuple/Analyzer/Rate/Local/ntuple_*.root");
	chain->Add("/Users/KyeongPil_Lee/ServiceWorks/HLTReRun/v20171109_Menu3p1_3p2_4p0_Efficiency/ntuple_Menu3p1.root");

	NtupleHandle *ntuple = new NtupleHandle( chain );
	// ntuple->TurnOffBranches_All();

	Int_t nEvent = chain->GetEntries();
	std::cout << "[Total event: " << nEvent << "]" << std::endl;

	// nEvent = 100;

	for(Int_t i_ev=0; i_ev<nEvent; i_ev++)
	{
		ntuple->GetEvent( i_ev );

		KPEvent event( ntuple );
		printf("[%d event]\n", i_ev);
		printf("\t(run, rumi, event, BX_ID, InstLumi, OfflineInstLumi) = (%d, %d, %llu, %lf, %e, %e)\n", event.RunNum, event.LumiBlockNum, event.EventNum, event.BX_ID, event.InstLumi, event.OfflineInstLumi);
		printf("\t(nFiredTrigger, nHLTObj, nMyFiredTrigger, nMyHLTObj, nMuon, nL3Muon, nL2Muon, nTKMuon, nL1Muon) = (%d, %d, %d, %d, %d, %d, %d, %d, %d)\n", 
			event.nFiredTrigger, event.nHLTObject, event.nMyFiredTrigger, event.nMyHLTObject, event.nMuon, event.nL3Muon, event.nL2Muon, event.nTkMuon, event.nL1Muon );

		Bool_t Flag_Print = kFALSE;
		if( event.nFiredTrigger != 0 ) Flag_Print = kTRUE;

		if( Flag_Print )
		{
			cout << "[Full list of fired muon trigger]" << endl;
			for( const auto& trigger : *event.vec_FiredTrigger )
				cout << "\t" << trigger << endl;

			cout << "[Full list of fired muon trigger AFTER RERUN HLT]" << endl;
			for( const auto& trigger : *event.vec_MyFiredTrigger )
				cout << "\t" << trigger << endl;
		}

		////////////////////////
		// -- offline muon -- //
		////////////////////////
		for(Int_t i_mu=0; i_mu<event.nMuon; i_mu++)
		{
			KPMuon mu( ntuple, i_mu );

			if( Flag_Print )
			{
				printf("\t[%d muon]\n", i_mu);
				printf("\t\t(Pt, Eta, Phi, IsGLB, IsTRK, IsLoose, IsMedium, IsTight) = (%lf, %lf, %lf, %d, %d, %d, %d, %d)\n",
					mu.Pt, mu.Eta, mu.Phi, mu.IsGLB, mu.IsTRK, mu.IsLoose, mu.IsMedium, mu.IsTight);
			}
		}

		///////////////////////
		// -- HLT objects -- //
		///////////////////////
		for(Int_t i_hlt=0; i_hlt<event.nHLTObject; i_hlt++)
		{
			KPHLTObject HLTObj( ntuple, i_hlt );
			if( Flag_Print )
			{
				printf("\t[%d HLT object]\n", i_hlt);
				printf("\t\t(FilterName, Pt, Eta, Phi) = (%s, %lf, %lf, %lf)\n", HLTObj.FilterName.Data(), HLTObj.Pt, HLTObj.Eta, HLTObj.Phi);
			}
		}

		///////////////////////////////////////
		// -- HLT objects after rerun HLT -- //
		///////////////////////////////////////
		for(Int_t i_hlt=0; i_hlt<event.nMyHLTObject; i_hlt++)
		{
			KPMYHLTObject MYHLTObj( ntuple, i_hlt );
			if( Flag_Print )
			{
				printf("\t[%d HLT object]\n", i_hlt);
				printf("\t\t(FilterName, Pt, Eta, Phi) = (%s, %lf, %lf, %lf)\n", MYHLTObj.FilterName.Data(), MYHLTObj.Pt, MYHLTObj.Eta, MYHLTObj.Phi);
			}
		}

		///////////////////
		// -- L3 muon -- //
		///////////////////
		for(Int_t i_l3=0; i_l3<event.nL3Muon; i_l3++)
		{
			KPL3Muon l3mu( ntuple, i_l3 );
			if( Flag_Print )
			{
				printf("\t[%d L3 muon]\n", i_l3);
				printf("\t\t(Pt, eta, phi, charge, TrkPt) = (%lf, %lf, %lf, %lf, %lf)\n", l3mu.Pt, l3mu.Eta, l3mu.Phi, l3mu.Charge, l3mu.TrkPt);
			}
		}

		///////////////////
		// -- L2 muon -- //
		///////////////////
		for(Int_t i_l2=0; i_l2<event.nL2Muon; i_l2++)
		{
			KPL2Muon l2mu( ntuple, i_l2 );
			if( Flag_Print )
			{
				printf("\t[%d L2 muon]\n", i_l2);
				printf("\t\t(Pt, eta, phi, charge, TrkPt) = (%lf, %lf, %lf, %lf, %lf)\n", l2mu.Pt, l2mu.Eta, l2mu.Phi, l2mu.Charge, l2mu.TrkPt);
			}
		}

		///////////////////
		// -- TK muon -- //
		///////////////////
		for(Int_t i_tk=0; i_tk<event.nTkMuon; i_tk++)
		{
			KPTkMuon tkmu( ntuple, i_tk );
			if( Flag_Print )
			{
				printf("\t[%d Tk muon]\n", i_tk);
				printf("\t\t(Pt, eta, phi, charge, TrkPt) = (%lf, %lf, %lf, %lf, %lf)\n", tkmu.Pt, tkmu.Eta, tkmu.Phi, tkmu.Charge, tkmu.TrkPt);
			}
		}

		///////////////////
		// -- L1 muon -- //
		///////////////////
		for(Int_t i_l1=0; i_l1<event.nL1Muon; i_l1++)
		{
			KPL1Muon l1mu( ntuple, i_l1 );
			if( Flag_Print )
			{
				printf("\t[%d L1 muon]\n", i_l1);
				printf("\t\t(Pt, eta, phi, charge, Quality) = (%lf, %lf, %lf, %lf, %lf)\n", l1mu.Pt, l1mu.Eta, l1mu.Phi, l1mu.Charge, l1mu.Quality);
			}
		}

	}

	std::cout << "Finished" << std::endl;
}