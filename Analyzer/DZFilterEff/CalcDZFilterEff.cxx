#include <TChain.h>
#include <TFile.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TLorentzVector.h>
#include <TStopwatch.h>
#include <TTimeStamp.h>
#include <TString.h>
#include <TLegend.h>
#include <THStack.h>
#include <TPad.h>
#include <TCanvas.h>
#include <TColor.h>
#include <TAttMarker.h>
#include <TF1.h>
#include <TStyle.h>
#include <TROOT.h>
#include <TApplication.h>
#include <vector>
#include <TMath.h>
#include <TSystem.h>

#include <Include/NtupleHandle.h>
#include <Include/Object.h>
#include <Include/PlotTools.h>

class Setup
{
public:
	vector< TString > vec_ntuplePath;
	Double_t lowerLimitM;
	Double_t upperLimitM;
	TString trigNameDZ;
	TString trigNameNonDZ;

	void addNtuplePath( TString path )
	{
		this->vec_ntuplePath.push_back( path )
		cout << "ntuple path: " << path << endl;
	}
};

class DZFilterEffTool
{
public:
	Setup setup;

	TH1D* h_mass; // -- for x-check

	Int_t nPass_nonDZ;
	Int_t nPass_DZ;

	DZFilterEffTool()
	{
		this->h_mass = new TH1D("h_mass", "", 10000, 0, 10000 );

		this->nPass_nonDZ = 0;
		this->nPass_DZ = 0;
	}

	DZFilterEffTool( Setup &_setup )
	{
		this->setup = _setup;
	}

	void Calc()
	{
		TChain *chain = new TChain("ntupler/ntuple");
		for(const auto& ntuplePath : this->setup.vec_ntuplePath )
			chain->Add(ntuplePath);

		NtupleHandle *ntuple = new NtupleHandle( chain );

		Int_t nEvent = chain->GetEntries();
		std::cout << "[Total event: " << nEvent << "]" << std::endl;

		// nEvent = 1000000;
		for(Int_t i_ev=0; i_ev<nEvent; i_ev++)
		{
			loadBar(i_ev+1, nEvent, 100, 100);

			ntuple->GetEvent( i_ev );

			KPEvent event( ntuple );

			if( this->IsZEvent( ntuple, event ) ) // -- only for Z events (signal-like events)
			{
				if( this->IsFired( event, this->setup.trigNameNonDZ) ) // -- count # events firing non-DZ path
				{
					this->nPass_nonDZ++;

					if( this->IsFired( event, this->setup.trigNameDZ) ) // -- count # events firing DZ path also
						this->nPass_DZ++;
				}
			}
		} // -- end of event iteration

		Double_t dZFilterEff = (Double_t)this->nPass_DZ / (Double_t)this->nPass_nonDZ;
		printf("non-DZ path: %s\n", this->setup.trigNameNonDZ.Data() );
		printf("DZ path: %s\n", this->setup.trigNameDZ.Data() );
		printf("DZ filter efficiency (DZ / non-DZ) = %d / %d = %.6lf\n", this->nPass_DZ, this->nPass_nonDZ, dZFilterEff );
	}
	
private:
	Bool_t IsZEvent( NtupleHandle* ntuple, KPEvent &event )
	{
		Bool_t flag = kFALSE;

		for(Int_t i_mu=0; i_mu<event.nMuon; i_mu++)
		{
			KPMuon mu_ith( ntuple, i_mu );
			for(Int_t j_mu=i_mu+1; j_mu<event.nMuon; j_mu++) // -- starts from i_mu+1: no duplication -- //
			{
				KPMuon mu_jth( ntuple, j_mu );

				if( this->IsGoodMuon( mu_ith ) && this->IsGoodMuon( mu_jth ) )
				{
					Double_t mass = (mu_ith.LVec_P + mu_jth.LVec_P).M();

					if( mass > this->setup.lowerLimitM && mass < this->setup.upperLimitM )
					{
						flag = kTRUE;
						h_mass->Fill( mass );
						break; // -- break if at least one pair is found ...
					}
				}
			} // -- j-th iteration

			if( flag ) break;
		} // -- i-th iteration

		return flag;
	}

	Bool_t IsGoodMuon( KPMuon &mu )
	{
		Bool_t flag = kFALSE;

		if( mu.IsTight && 
			mu.RelPFIso_dBeta < 0.15 && 
			mu.Pt > this->setup.lowerLimitPt ) flag = kTRUE;

		return flag;
	}

	Bool_t IsFired( KPEvent &event, TString trigName )
	{
		Bool_t flag = kFALSE;
		if( std::find(event.vec_FiredTrigger->begin(), event.vec_FiredTrigger->end(), trigName) != event.vec_FiredTrigger->end() )
			flag = kTRUE;

		return flag;
	}

};

void CalcDZFilterEff()
{
	Setup setup;
	setup.lowerLimitPt = 8.0;
	setup.lowerLimitM = 81.0;
	setup.upperLimitM = 101.0;
	setup.trigNameNonDZ = "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v13";
	setup.trigNameDZ = "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v14";
	// setup.trigNameDZ = "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v4";
	setup.addNtuplePath( "" );

	DZFilterEffTool *tool = new DZFilterEffTool( setup );
	tool->Calc();
}
