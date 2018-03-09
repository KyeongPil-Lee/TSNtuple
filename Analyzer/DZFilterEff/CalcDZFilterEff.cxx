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
	Double_t lowerLimitPt;
	Double_t lowerLimitM;
	Double_t upperLimitM;
	TString trigNameDZ;
	TString trigNameNonDZ;

	void addNtuplePath( TString path )
	{
		this->vec_ntuplePath.push_back( path );
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

	Int_t nPass_IsoMu27; // -- for x-check

	DZFilterEffTool()
	{
		this->h_mass = new TH1D("h_mass", "", 10000, 0, 10000 );

		this->nPass_nonDZ = 0;
		this->nPass_DZ = 0;
		this->nPass_IsoMu27 = 0;
	}

	DZFilterEffTool( Setup &_setup ): DZFilterEffTool()
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
				if( this->IsFired_MYHLT( event, this->setup.trigNameNonDZ) ) // -- count # events firing non-DZ path
				{
					this->nPass_nonDZ++;

					if( this->IsFired_MYHLT( event, this->setup.trigNameDZ) ) // -- count # events firing DZ path also
						this->nPass_DZ++;
				}

				if( this->IsFired_MYHLT( event, "HLT_IsoMu27_v14" ) )
					this->nPass_IsoMu27++;
			}
		} // -- end of event iteration

		Double_t dZFilterEff;
		if( this->nPass_nonDZ == 0 ) 
			dZFilterEff = 0;
		else 
			dZFilterEff = (Double_t)this->nPass_DZ / (Double_t)this->nPass_nonDZ;

		printf("non-DZ path: %s\n", this->setup.trigNameNonDZ.Data() );
		printf("DZ path: %s\n", this->setup.trigNameDZ.Data() );
		printf("DZ filter efficiency (DZ / non-DZ) = %d / %d = %.6lf\n", this->nPass_DZ, this->nPass_nonDZ, dZFilterEff );

		printf("\n# events passing IsoMu27 (for x-check): %d\n", this->nPass_IsoMu27);

		TFile *f_output = TFile::Open("ROOTFile_CalcDZFilterEff.root", "RECREATE");
		f_output->cd();
		this->h_mass->Write();
		f_output->Close();
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

	Bool_t IsFired_MYHLT( KPEvent &event, TString trigName )
	{
		Bool_t flag = kFALSE;
		if( std::find(event.vec_MyFiredTrigger->begin(), event.vec_MyFiredTrigger->end(), trigName) != event.vec_MyFiredTrigger->end() )
			flag = kTRUE;

		return flag;
	}

	static inline void loadBar(int x, int n, int r, int w)
	{
	    // Only update r times.
	    if( x == n )
	    	cout << endl;

	    if ( x % (n/r +1) != 0 ) return;

	 
	    // Calculuate the ratio of complete-to-incomplete.
	    float ratio = x/(float)n;
	    int   c     = ratio * w;
	 
	    // Show the percentage complete.
	    printf("%3d%% [", (int)(ratio*100) );
	 
	    // Show the load bar.
	    for (int x=0; x<c; x++) cout << "=";
	 
	    for (int x=c; x<w; x++) cout << " ";
	 
	    // ANSI Control codes to go back to the
	    // previous line and clear it.
		cout << "]\r" << flush;
	}
};

void CalcDZFilterEff()
{
	Setup setup;
	setup.lowerLimitPt = 8.0;
	// setup.lowerLimitM = 81.0;
	// setup.upperLimitM = 101.0;
	setup.lowerLimitM = 76.0;
	setup.upperLimitM = 106.0;
	setup.trigNameNonDZ = "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v13";
	// setup.trigNameDZ = "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v14";
	setup.trigNameDZ = "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v4";
	setup.addNtuplePath( "./ntuple_9*.root" );

	DZFilterEffTool *tool = new DZFilterEffTool( setup );
	tool->Calc();
}
