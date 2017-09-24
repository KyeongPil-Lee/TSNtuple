#pragma once

#include <TLorentzVector.h>

//customized header files
#include "NtupleHandle.h"

#define M_Mu 0.1056583715 // -- GeV -- //
#define M_Elec 0.000510998 // -- GeV -- //
#define M_Tau 1.77682 // -- GeV -- //

class KPEvent
{
public:
	Bool_t Flag_IsNonNull;

	Bool_t			Flag_IsMC;
	Int_t           RunNum;
	Int_t           LumiBlockNum;
	ULong64_t       EventNum;
	Int_t           nVertices;
	Double_t        Rho_Offline;
	Double_t        BX_ID;
	Double_t        InstLumi;
	Int_t           TruePU;
	Double_t        Rho;
	Double_t        RhoECAL;
	Double_t        RhoHCAL;
	Double_t        GenEventWeight;
	vector<string> *vec_FiredTrigger;

	Int_t           nGenParticle;
	Int_t           nMuon;
	Int_t			nHLTObject;
	Int_t			nFiredTrigger;
	Int_t			nL3Muon;
	Int_t			nTkMuon;
	Int_t			nL2Muon;
	Int_t			nL1Muon;

	KPEvent()
	{
		this->Flag_IsNonNull = kFALSE;
		this->Flag_IsMC = kFALSE;

		this->RunNum = 0;
		this->LumiBlockNum = 0;
		this->EventNum = 0;
		this->nVertices = 0;
		this->Rho_Offline = 0;
		this->BX_ID = 0;
		this->InstLumi = 0;
		this->TruePU = 0;
		this->Rho = 0;
		this->RhoECAL = 0;
		this->RhoHCAL = 0;
		this->GenEventWeight = 0;

		this->nGenParticle = -999;
		this->nMuon = -999;
	}

	KPEvent( NtupleHandle *ntuple, Bool_t IsMC )
	{
		this->Fill( ntuple, IsMC );
	}

	void Fill( NtupleHandle* ntuple, Bool_t IsMC )
	{
		this->Flag_IsNonNull = kTRUE;

		this->Flag_IsMC = IsMC;
		this->RunNum = ntuple->RunNum;
		this->LumiBlockNum = ntuple->LumiBlockNum;
		this->EventNum = ntuple->EventNum;
		this->nVertices = ntuple->nVertices;
		this->Rho_Offline = ntuple->Rho_Offline;
		this->BX_ID = ntuple->BX_ID;
		this->InstLumi = ntuple->InstLumi;
		this->TruePU = ntuple->TruePU;
		this->Rho = ntuple->Rho; // -- online -- //
		this->RhoECAL = ntuple->RhoECAL;
		this->RhoHCAL = ntuple->RhoHCAL;
		this->GenEventWeight = ntuple->GenEventWeight;
		this->vec_FiredTrigger = ntuple->vec_FiredTrigger;

		this->nGenParticle = ntuple->nGenParticle;
		this->nMuon = ntuple->nMuon;
		this->nHLTObject = (Int_t)ntuple->vec_FilterName->size();
		this->nFiredTrigger = (Int_t)this->vec_FiredTrigger->size();

		this->nL3Muon = ntuple->nL3Muon;
		this->nL2Muon = ntuple->nL2Muon;
		this->nTkMuon = ntuple->nTkMuon;
		this->nL1Muon = ntuple->nL1Muon;
	}
};

class KPObject
{
public:
	Bool_t Flag_IsNonNull;
	Double_t Px;
	Double_t Py;
	Double_t Pz;
	Double_t Pt;
	Double_t Eta;
	Double_t Phi;
	TLorentzVector LVec_P;

	KPObject()
	{
		this->Flag_IsNonNull = kFALSE;
		this->Px = 0;
		this->Py = 0;
		this->Pz = 0;
		this->Pt = 0;
		this->Eta = 0;
		this->Phi = 0;
		this->LVec_P.SetPxPyPzE(0,0,0,0);
	}

	// -- pure virtual class: should be defined in each child class -- //
	virtual void Init() = 0;
	virtual void Fill( NtupleHandle* ntuple, Int_t index ) = 0;
};

class KPGenParticle : public KPObject
{
public:
	Int_t           ID;
	Int_t           Status;
	Int_t           Mother;
	Double_t        Pt;
	Double_t        Eta;
	Double_t        Phi;
	Double_t        Px;
	Double_t        Py;
	Double_t        Pz;
	Double_t        E;
	Double_t        Charge;
	Int_t           isPrompt;
	Int_t           isPromptFinalState;
	Int_t           isTauDecayProduct;
	Int_t           isPromptTauDecayProduct;
	Int_t           isDirectPromptTauDecayProductFinalState;
	Int_t           isHardProcess;
	Int_t           isLastCopy;
	Int_t           isLastCopyBeforeFSR;
	Int_t           isPromptDecayed;
	Int_t           isDecayedLeptonHadron;
	Int_t           fromHardProcessBeforeFSR;
	Int_t           fromHardProcessDecayed;
	Int_t           fromHardProcessFinalState;
	Int_t           isMostlyLikePythia6Status3;

	KPGenParticle(): KPObject() { this->Init(); }
	KPGenParticle( NtupleHandle* ntuple, Int_t index )
	{ 
		this->Flag_IsNonNull = kTRUE;
		this->Fill(ntuple, index); 
	}

	void Fill( NtupleHandle* ntuple, Int_t index )
	{
		this->ID = ntuple->GenParticle_ID[index];
		this->Status = ntuple->GenParticle_Status[index];
		this->Mother = ntuple->GenParticle_Mother[index];
		this->Pt = ntuple->GenParticle_Pt[index];
		this->Eta = ntuple->GenParticle_Eta[index];
		this->Phi = ntuple->GenParticle_Phi[index];
		this->Px = ntuple->GenParticle_Px[index];
		this->Py = ntuple->GenParticle_Py[index];
		this->Pz = ntuple->GenParticle_Pz[index];
		this->E = ntuple->GenParticle_E[index];
		this->LVec_P.SetPxPyPzE( this->Px, this->Py, this->Pz, this->E );

		this->Charge = ntuple->GenParticle_Charge[index];
		this->isPrompt = ntuple->GenParticle_isPrompt[index];
		this->isPromptFinalState = ntuple->GenParticle_isPromptFinalState[index];
		this->isTauDecayProduct = ntuple->GenParticle_isTauDecayProduct[index];
		this->isPromptTauDecayProduct = ntuple->GenParticle_isPromptTauDecayProduct[index];
		this->isDirectPromptTauDecayProductFinalState = ntuple->GenParticle_isDirectPromptTauDecayProductFinalState[index];
		this->isHardProcess = ntuple->GenParticle_isHardProcess[index];
		this->isLastCopy = ntuple->GenParticle_isLastCopy[index];
		this->isLastCopyBeforeFSR = ntuple->GenParticle_isLastCopyBeforeFSR[index];
		this->isPromptDecayed = ntuple->GenParticle_isPromptDecayed[index];
		this->isDecayedLeptonHadron= ntuple->GenParticle_isDecayedLeptonHadron[index];
		this->fromHardProcessBeforeFSR = ntuple->GenParticle_fromHardProcessBeforeFSR[index];
		this->fromHardProcessDecayed = ntuple->GenParticle_fromHardProcessDecayed[index];
		this->fromHardProcessFinalState = ntuple->GenParticle_fromHardProcessFinalState[index];
		this->isMostlyLikePythia6Status3 = ntuple->GenParticle_isMostlyLikePythia6Status3[index];
	}

	void Init()
	{
		this->ID = 0;
		this->Status = 0;
		this->Mother = 0;
		this->Pt = 0;
		this->Eta = 0;
		this->Phi = 0;
		this->Px = 0;
		this->Py = 0;
		this->Pz = 0;
		this->E = 0;
		this->Charge = 0;
		this->isPrompt = 0;
		this->isPromptFinalState = 0;
		this->isTauDecayProduct = 0;
		this->isPromptTauDecayProduct = 0;
		this->isDirectPromptTauDecayProductFinalState = 0;
		this->isHardProcess = 0;
		this->isLastCopy = 0;
		this->isLastCopyBeforeFSR = 0;
		this->isPromptDecayed = 0;
		this->isDecayedLeptonHadron = 0;
		this->fromHardProcessBeforeFSR = 0;
		this->fromHardProcessDecayed = 0;
		this->fromHardProcessFinalState = 0;
		this->isMostlyLikePythia6Status3 = 0;
	}
};

class KPMuon: public KPObject
{
public:
	Double_t        dB;
	Double_t        Charge;
	Int_t           IsGLB;
	Int_t           IsSTA;
	Int_t           IsTRK;
	Int_t           IsPF;
	Int_t           IsTight;
	Int_t           IsMedium;
	Int_t           IsLoose;
	Double_t        PFIso03_Charged;
	Double_t        PFIso03_Neutral;
	Double_t        PFIso03_Photon;
	Double_t        PFIso03_SumPU;
	Double_t        PFIso04_Charged;
	Double_t        PFIso04_Neutral;
	Double_t        PFIso04_Photon;
	Double_t        PFIso04_SumPU;
	Double_t        PFCluster03_ECAL;
	Double_t        PFCluster03_HCAL;
	Double_t        PFCluster04_ECAL;
	Double_t        PFCluster04_HCAL;
	Double_t        NormChi2_GlbTrk;
	Int_t           nTrackerHit_GlbTrk;
	Int_t           nTrackerLayer_GlbTrk;
	Int_t           nPixelHit_GlbTrk;
	Int_t           nMuonHit_GlbTrk;
	Double_t        NormChi2_InnerTrk;
	Int_t           nTrackerHit_InnerTrk;
	Int_t           nTrackerLayer_InnerTrk;
	Int_t           nPixelHit_InnerTrk;
	Double_t        dxyVTX_BestTrk;
	Double_t        dzVTX_BestTrk;
	Int_t           nMatchedStation;
	Int_t           nMatchedRPCLayer;
	Int_t           StationMask;

	KPMuon(): KPObject() { this->Init(); }

	KPMuon( NtupleHandle *ntuple, Int_t index )
	{
		this->Flag_IsNonNull = kTRUE;
		this->Fill( ntuple, index );
	}

	void Fill( NtupleHandle* ntuple, Int_t index )
	{
		this->Pt = ntuple->Muon_Pt[index];
		this->Eta = ntuple->Muon_Eta[index];
		this->Phi = ntuple->Muon_Phi[index];
		this->Px = ntuple->Muon_Px[index];
		this->Py = ntuple->Muon_Py[index];
		this->Pz = ntuple->Muon_Pz[index];
		Double_t E = sqrt( Px*Px + Py*Py + Pz*Pz + M_Mu*M_Mu );
		this->LVec_P.SetPxPyPzE( this->Px, this->Py, this->Pz, E );

		this->dB = ntuple->Muon_dB[index];
		this->Charge = ntuple->Muon_Charge[index];
		this->IsGLB = ntuple->Muon_IsGLB[index];
		this->IsSTA = ntuple->Muon_IsSTA[index];
		this->IsTRK = ntuple->Muon_IsTRK[index];
		this->IsPF = ntuple->Muon_IsPF[index];
		this->IsTight = ntuple->Muon_IsTight[index];
		this->IsMedium = ntuple->Muon_IsMedium[index];
		this->IsLoose = ntuple->Muon_IsLoose[index];
		this->PFIso03_Charged = ntuple->Muon_PFIso03_Charged[index];
		this->PFIso03_Neutral = ntuple->Muon_PFIso03_Neutral[index];
		this->PFIso03_Photon = ntuple->Muon_PFIso03_Photon[index];
		this->PFIso03_SumPU = ntuple->Muon_PFIso03_SumPU[index];
		this->PFIso04_Charged = ntuple->Muon_PFIso04_Charged[index];
		this->PFIso04_Neutral = ntuple->Muon_PFIso04_Neutral[index];
		this->PFIso04_Photon = ntuple->Muon_PFIso04_Photon[index];
		this->PFIso04_SumPU = ntuple->Muon_PFIso04_SumPU[index];
		this->PFCluster03_ECAL = ntuple->Muon_PFCluster03_ECAL[index];
		this->PFCluster03_HCAL = ntuple->Muon_PFCluster03_HCAL[index];
		this->PFCluster04_ECAL = ntuple->Muon_PFCluster04_ECAL[index];
		this->PFCluster04_HCAL = ntuple->Muon_PFCluster04_HCAL[index];
		this->NormChi2_GlbTrk = ntuple->Muon_NormChi2_GlbTrk[index];
		this->nTrackerHit_GlbTrk = ntuple->Muon_nTrackerHit_GlbTrk[index];
		this->nTrackerLayer_GlbTrk = ntuple->Muon_nTrackerLayer_GlbTrk[index];
		this->nPixelHit_GlbTrk = ntuple->Muon_nPixelHit_GlbTrk[index];
		this->nMuonHit_GlbTrk = ntuple->Muon_nMuonHit_GlbTrk[index];
		this->NormChi2_InnerTrk = ntuple->Muon_NormChi2_InnerTrk[index];
		this->nTrackerHit_InnerTrk = ntuple->Muon_nTrackerHit_InnerTrk[index];
		this->nTrackerLayer_InnerTrk = ntuple->Muon_nTrackerLayer_InnerTrk[index];
		this->nPixelHit_InnerTrk = ntuple->Muon_nPixelHit_InnerTrk[index];
		this->dxyVTX_BestTrk = ntuple->Muon_dxyVTX_BestTrk[index];
		this->dzVTX_BestTrk = ntuple->Muon_dzVTX_BestTrk[index];
		this->nMatchedStation = ntuple->Muon_nMatchedStation[index];
		this->nMatchedRPCLayer = ntuple->Muon_nMatchedRPCLayer[index];
		this->StationMask = ntuple->Muon_StationMask[index];
	}

	void Init()
	{
		this->dB = 0;
		this->Charge = 0;
		this->IsGLB = 0;
		this->IsSTA = 0;
		this->IsTRK = 0;
		this->IsPF = 0;
		this->IsTight = 0;
		this->IsMedium = 0;
		this->IsLoose = 0;
		this->PFIso03_Charged = 0;
		this->PFIso03_Neutral = 0;
		this->PFIso03_Photon = 0;
		this->PFIso03_SumPU = 0;
		this->PFIso04_Charged = 0;
		this->PFIso04_Neutral = 0;
		this->PFIso04_Photon = 0;
		this->PFIso04_SumPU = 0;
		this->PFCluster03_ECAL = 0;
		this->PFCluster03_HCAL = 0;
		this->PFCluster04_ECAL = 0;
		this->PFCluster04_HCAL = 0;
		this->NormChi2_GlbTrk = 0;
		this->nTrackerHit_GlbTrk = 0;
		this->nTrackerLayer_GlbTrk = 0;
		this->nPixelHit_GlbTrk = 0;
		this->nMuonHit_GlbTrk = 0;
		this->NormChi2_InnerTrk = 0;
		this->nTrackerHit_InnerTrk = 0;
		this->nTrackerLayer_InnerTrk = 0;
		this->nPixelHit_InnerTrk = 0;
		this->dxyVTX_BestTrk = 0;
		this->dzVTX_BestTrk = 0;
		this->nMatchedStation = 0;
		this->nMatchedRPCLayer = 0;
		this->StationMask = 0;
	}
};

class KPHLTObject: public KPObject
{
public:
	TString FilterName;

	KPHLTObject(): KPObject() { this->Init(); }

	KPHLTObject(NtupleHandle* ntuple, Int_t index)
	{
		this->Flag_IsNonNull = kTRUE;
		this->Fill(ntuple, index);
	}

	void Fill(NtupleHandle* ntuple, Int_t index)
	{
		this->FilterName = ntuple->vec_FilterName->at(index);
		this->Pt = ntuple->vec_HLTObj_Pt->at(index);
		this->Eta = ntuple->vec_HLTObj_Eta->at(index);
		this->Phi = ntuple->vec_HLTObj_Phi->at(index);
	}

	void Init()
	{
		this->FilterName = "";
	}
};

class KPL3Muon: public KPObject
{
public:
	Double_t        Charge;
	Double_t        TrkPt;
	Double_t        TrkIso;
	Double_t        ECALIso;
	Double_t        HCALIso;

	KPL3Muon(): KPObject() { this->Init(); }

	KPL3Muon(NtupleHandle* ntuple, Int_t index)
	{
		this->Flag_IsNonNull = kTRUE;
		this->Fill(ntuple, index);
	}

	void Fill(NtupleHandle* ntuple, Int_t index)
	{
		this->Pt = ntuple->L3Muon_Pt[index];
		this->Eta = ntuple->L3Muon_Eta[index];
		this->Phi = ntuple->L3Muon_Phi[index];
		this->LVec_P.SetPtEtaPhiM( this->Pt, this->Eta, this->Phi, M_Mu );

		this->Charge = ntuple->L3Muon_Charge[index];
		this->TrkPt = ntuple->L3Muon_TrkPt[index];
		this->TrkIso = ntuple->L3Muon_TrkIso[index];
		this->ECALIso = ntuple->L3Muon_ECALIso[index];
		this->HCALIso = ntuple->L3Muon_HCALIso[index];
	}

	void Init()
	{
		this->Charge = 0;
		this->TrkPt = 0;
		this->TrkIso = 0;
		this->ECALIso = 0;
		this->HCALIso = 0;
	}
};

class KPL2Muon: public KPObject
{
public:
	Double_t        Charge;
	Double_t        TrkPt;

	KPL2Muon(): KPObject() { this->Init(); }

	KPL2Muon(NtupleHandle* ntuple, Int_t index)
	{
		this->Flag_IsNonNull = kTRUE;
		this->Fill(ntuple, index);
	}

	void Fill(NtupleHandle* ntuple, Int_t index)
	{
		this->Pt = ntuple->L2Muon_Pt[index];
		this->Eta = ntuple->L2Muon_Eta[index];
		this->Phi = ntuple->L2Muon_Phi[index];
		this->LVec_P.SetPtEtaPhiM( this->Pt, this->Eta, this->Phi, M_Mu );

		this->Charge = ntuple->L2Muon_Charge[index];
		this->TrkPt = ntuple->L2Muon_TrkPt[index];
	}

	void Init()
	{
		this->Charge = 0;
		this->TrkPt = 0;
	}
};

class KPTkMuon: public KPObject
{
public:
	Double_t        Charge;
	Double_t        TrkPt;

	KPTkMuon(): KPObject() { this->Init(); }

	KPTkMuon(NtupleHandle* ntuple, Int_t index)
	{
		this->Flag_IsNonNull = kTRUE;
		this->Fill(ntuple, index);
	}

	void Fill(NtupleHandle* ntuple, Int_t index)
	{
		this->Pt = ntuple->TkMuon_Pt[index];
		this->Eta = ntuple->TkMuon_Eta[index];
		this->Phi = ntuple->TkMuon_Phi[index];
		this->LVec_P.SetPtEtaPhiM( this->Pt, this->Eta, this->Phi, M_Mu );

		this->Charge = ntuple->TkMuon_Charge[index];
		this->TrkPt = ntuple->TkMuon_TrkPt[index];
	}

	void Init()
	{
		this->Charge = 0;
		this->TrkPt = 0;
	}
};

class KPL1Muon: public KPObject
{
public:
	Double_t        Charge;
	Double_t        Quality;

	KPL1Muon(): KPObject() { this->Init(); }

	KPL1Muon(NtupleHandle* ntuple, Int_t index)
	{
		this->Flag_IsNonNull = kTRUE;
		this->Fill(ntuple, index);
	}

	void Fill(NtupleHandle* ntuple, Int_t index)
	{
		this->Pt = ntuple->L1Muon_Pt[index];
		this->Eta = ntuple->L1Muon_Eta[index];
		this->Phi = ntuple->L1Muon_Phi[index];
		this->LVec_P.SetPtEtaPhiM( this->Pt, this->Eta, this->Phi, M_Mu );

		this->Charge = ntuple->L1Muon_Charge[index];
		this->Quality = ntuple->L1Muon_Quality[index];
	}

	void Init()
	{
		this->Charge = 0;
		this->Quality = 0;
	}
};