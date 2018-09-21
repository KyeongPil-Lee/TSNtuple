#pragma once

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include <vector>

#define ArrSize 2000

class NtupleHandle
{
public:
  TChain *chain;

  Bool_t          IsRealData;
  Int_t           RunNum;
  Int_t           LumiBlockNum;
  ULong64_t       EventNum;
  Int_t           nVertices;
  Double_t        Rho_Offline;
  Double_t        BX_ID;
  Double_t        InstLumi;
  Double_t        DataPU;
  Double_t        DataPURMS;
  Double_t        BunchLumi;
  Double_t        OfflineInstLumi;
  Double_t        OfflineDataPU;
  Double_t        OfflineDataPURMS;
  Double_t        OfflineBunchLumi;
  Int_t           TruePU;
  Double_t        Rho;
  Double_t        RhoECAL;
  Double_t        RhoHCAL;
  Double_t        GenEventWeight;
  Int_t           nGenParticle;
  Int_t           GenParticle_ID[ArrSize];   //[nGenParticle]
  Int_t           GenParticle_Status[ArrSize];   //[nGenParticle]
  Int_t           GenParticle_Mother[ArrSize];   //[nGenParticle]
  Double_t        GenParticle_Pt[ArrSize];   //[nGenParticle]
  Double_t        GenParticle_Eta[ArrSize];   //[nGenParticle]
  Double_t        GenParticle_Phi[ArrSize];   //[nGenParticle]
  Double_t        GenParticle_Px[ArrSize];   //[nGenParticle]
  Double_t        GenParticle_Py[ArrSize];   //[nGenParticle]
  Double_t        GenParticle_Pz[ArrSize];   //[nGenParticle]
  Double_t        GenParticle_E[ArrSize];   //[nGenParticle]
  Double_t        GenParticle_Charge[ArrSize];   //[nGenParticle]
  Int_t           GenParticle_isPrompt[ArrSize];   //[nGenParticle]
  Int_t           GenParticle_isPromptFinalState[ArrSize];   //[nGenParticle]
  Int_t           GenParticle_isTauDecayProduct[ArrSize];   //[nGenParticle]
  Int_t           GenParticle_isPromptTauDecayProduct[ArrSize];   //[nGenParticle]
  Int_t           GenParticle_isDirectPromptTauDecayProductFinalState[ArrSize];   //[nGenParticle]
  Int_t           GenParticle_isHardProcess[ArrSize];   //[nGenParticle]
  Int_t           GenParticle_isLastCopy[ArrSize];   //[nGenParticle]
  Int_t           GenParticle_isLastCopyBeforeFSR[ArrSize];   //[nGenParticle]
  Int_t           GenParticle_isPromptDecayed[ArrSize];   //[nGenParticle]
  Int_t           GenParticle_isDecayedLeptonHadron[ArrSize];   //[nGenParticle]
  Int_t           GenParticle_fromHardProcessBeforeFSR[ArrSize];   //[nGenParticle]
  Int_t           GenParticle_fromHardProcessDecayed[ArrSize];   //[nGenParticle]
  Int_t           GenParticle_fromHardProcessFinalState[ArrSize];   //[nGenParticle]
  Int_t           GenParticle_isMostlyLikePythia6Status3[ArrSize];   //[nGenParticle]
  vector<string>  *vec_FiredTrigger;
  vector<string>  *vec_FilterName;
  vector<double>  *vec_HLTObj_Pt;
  vector<double>  *vec_HLTObj_Eta;
  vector<double>  *vec_HLTObj_Phi;
  vector<string>  *vec_MyFiredTrigger;
  vector<string>  *vec_MyFilterName;
  vector<double>  *vec_MyHLTObj_Pt;
  vector<double>  *vec_MyHLTObj_Eta;
  vector<double>  *vec_MyHLTObj_Phi;

  Int_t           nMuon;
  Double_t        Muon_Pt[ArrSize];   //[nMuon]
  Double_t        Muon_Eta[ArrSize];   //[nMuon]
  Double_t        Muon_Phi[ArrSize];   //[nMuon]
  Double_t        Muon_Px[ArrSize];   //[nMuon]
  Double_t        Muon_Py[ArrSize];   //[nMuon]
  Double_t        Muon_Pz[ArrSize];   //[nMuon]
  Double_t        Muon_dB[ArrSize];   //[nMuon]
  Double_t        Muon_Charge[ArrSize];   //[nMuon]
  Int_t           Muon_IsGLB[ArrSize];   //[nMuon]
  Int_t           Muon_IsSTA[ArrSize];   //[nMuon]
  Int_t           Muon_IsTRK[ArrSize];   //[nMuon]
  Int_t           Muon_IsPF[ArrSize];   //[nMuon]
  Int_t           Muon_IsTight[ArrSize];   //[nMuon]
  Int_t           Muon_IsMedium[ArrSize];   //[nMuon]
  Int_t           Muon_IsLoose[ArrSize];   //[nMuon]
  Int_t           Muon_IsHighPt[ArrSize];   //[nMuon]
  Int_t           Muon_IsSoft[ArrSize];   //[nMuon]
  Double_t        Muon_Iso03_sumPt[ArrSize];   //[nMuon]
  Double_t        Muon_Iso03_hadEt[ArrSize];   //[nMuon]
  Double_t        Muon_Iso03_emEt[ArrSize];   //[nMuon]
  Double_t        Muon_PFIso03_Charged[ArrSize];   //[nMuon]
  Double_t        Muon_PFIso03_Neutral[ArrSize];   //[nMuon]
  Double_t        Muon_PFIso03_Photon[ArrSize];   //[nMuon]
  Double_t        Muon_PFIso03_SumPU[ArrSize];   //[nMuon]
  Double_t        Muon_PFIso04_Charged[ArrSize];   //[nMuon]
  Double_t        Muon_PFIso04_Neutral[ArrSize];   //[nMuon]
  Double_t        Muon_PFIso04_Photon[ArrSize];   //[nMuon]
  Double_t        Muon_PFIso04_SumPU[ArrSize];   //[nMuon]
  Double_t        Muon_PFCluster03_ECAL[ArrSize];   //[nMuon]
  Double_t        Muon_PFCluster03_HCAL[ArrSize];   //[nMuon]
  Double_t        Muon_PFCluster04_ECAL[ArrSize];   //[nMuon]
  Double_t        Muon_PFCluster04_HCAL[ArrSize];   //[nMuon]
  Double_t        Muon_NormChi2_GlbTrk[ArrSize];   //[nMuon]
  Int_t           Muon_nTrackerHit_GlbTrk[ArrSize];   //[nMuon]
  Int_t           Muon_nTrackerLayer_GlbTrk[ArrSize];   //[nMuon]
  Int_t           Muon_nPixelHit_GlbTrk[ArrSize];   //[nMuon]
  Int_t           Muon_nMuonHit_GlbTrk[ArrSize];   //[nMuon]
  Double_t        Muon_NormChi2_InnerTrk[ArrSize];   //[nMuon]
  Int_t           Muon_nTrackerHit_InnerTrk[ArrSize];   //[nMuon]
  Int_t           Muon_nTrackerLayer_InnerTrk[ArrSize];   //[nMuon]
  Int_t           Muon_nPixelHit_InnerTrk[ArrSize];   //[nMuon]
  Double_t        Muon_dxyVTX_BestTrk[ArrSize];   //[nMuon]
  Double_t        Muon_dzVTX_BestTrk[ArrSize];   //[nMuon]
  Int_t           Muon_nMatchedStation[ArrSize];   //[nMuon]
  Int_t           Muon_nMatchedRPCLayer[ArrSize];   //[nMuon]
  Int_t           Muon_StationMask[ArrSize];   //[nMuon]
  Int_t           nL3Muon;
  Double_t        L3Muon_Pt[ArrSize];   //[nL3Muon]
  Double_t        L3Muon_Eta[ArrSize];   //[nL3Muon]
  Double_t        L3Muon_Phi[ArrSize];   //[nL3Muon]
  Double_t        L3Muon_Charge[ArrSize];   //[nL3Muon]
  Double_t        L3Muon_TrkPt[ArrSize];   //[nL3Muon]
  Double_t        L3Muon_TrkIso[ArrSize];   //[nL3Muon]
  Double_t        L3Muon_ECALIso[ArrSize];   //[nL3Muon]
  Double_t        L3Muon_HCALIso[ArrSize];   //[nL3Muon]
  Int_t           nL2Muon;
  Double_t        L2Muon_Pt[ArrSize];   //[nL2Muon]
  Double_t        L2Muon_Eta[ArrSize];   //[nL2Muon]
  Double_t        L2Muon_Phi[ArrSize];   //[nL2Muon]
  Double_t        L2Muon_Charge[ArrSize];   //[nL2Muon]
  Double_t        L2Muon_TrkPt[ArrSize];   //[nL2Muon]
  Int_t           nTkMuon;
  Double_t        TkMuon_Pt[ArrSize];   //[nTkMuon]
  Double_t        TkMuon_Eta[ArrSize];   //[nTkMuon]
  Double_t        TkMuon_Phi[ArrSize];   //[nTkMuon]
  Double_t        TkMuon_Charge[ArrSize];   //[nTkMuon]
  Double_t        TkMuon_TrkPt[ArrSize];   //[nTkMuon]
  Int_t           nL1Muon;
  Double_t        L1Muon_Pt[ArrSize];   //[nL1Muon]
  Double_t        L1Muon_Eta[ArrSize];   //[nL1Muon]
  Double_t        L1Muon_Phi[ArrSize];   //[nL1Muon]
  Double_t        L1Muon_Charge[ArrSize];   //[nL1Muon]
  Double_t        L1Muon_Quality[ArrSize];   //[nL1Muon]

  Int_t           nIterL3OI;
  Double_t        IterL3OI_TK_Pt[ArrSize];  //TracKer
  Double_t        IterL3OI_TK_Eta[ArrSize];
  Double_t        IterL3OI_TK_Phi[ArrSize];
  Double_t        IterL3OI_TK_Charge[ArrSize];
  Double_t        IterL3OI_SA_Pt[ArrSize];  //StandAlone
  Double_t        IterL3OI_SA_Eta[ArrSize];
  Double_t        IterL3OI_SA_Phi[ArrSize];
  Double_t        IterL3OI_SA_Charge[ArrSize];
  Double_t        IterL3OI_GL_Pt[ArrSize];  //GLobal
  Double_t        IterL3OI_GL_Eta[ArrSize];
  Double_t        IterL3OI_GL_Phi[ArrSize];
  Double_t        IterL3OI_GL_Charge[ArrSize];

  Int_t           nIterL3IO_L2Seeded;
  Double_t        IterL3IO_L2Seeded_TK_Pt[ArrSize];  //TracKer
  Double_t        IterL3IO_L2Seeded_TK_Eta[ArrSize];
  Double_t        IterL3IO_L2Seeded_TK_Phi[ArrSize];
  Double_t        IterL3IO_L2Seeded_TK_Charge[ArrSize];
  Double_t        IterL3IO_L2Seeded_SA_Pt[ArrSize];  //StandAlone
  Double_t        IterL3IO_L2Seeded_SA_Eta[ArrSize];
  Double_t        IterL3IO_L2Seeded_SA_Phi[ArrSize];
  Double_t        IterL3IO_L2Seeded_SA_Charge[ArrSize];
  Double_t        IterL3IO_L2Seeded_GL_Pt[ArrSize];  //GLobal
  Double_t        IterL3IO_L2Seeded_GL_Eta[ArrSize];
  Double_t        IterL3IO_L2Seeded_GL_Phi[ArrSize];
  Double_t        IterL3IO_L2Seeded_GL_Charge[ArrSize];

  Int_t           nIterL3IO_FromL1;
  Double_t        IterL3IO_FromL1_Pt[ArrSize];  //reco::Tracks
  Double_t        IterL3IO_FromL1_Eta[ArrSize];
  Double_t        IterL3IO_FromL1_Phi[ArrSize];
  Double_t        IterL3IO_FromL1_Charge[ArrSize];

  Int_t           nIterL3_FromL2;
  Double_t        IterL3_FromL2_TK_Pt[ArrSize];  //TracKer
  Double_t        IterL3_FromL2_TK_Eta[ArrSize];
  Double_t        IterL3_FromL2_TK_Phi[ArrSize];
  Double_t        IterL3_FromL2_TK_Charge[ArrSize];
  Double_t        IterL3_FromL2_SA_Pt[ArrSize];  //StandAlone
  Double_t        IterL3_FromL2_SA_Eta[ArrSize];
  Double_t        IterL3_FromL2_SA_Phi[ArrSize];
  Double_t        IterL3_FromL2_SA_Charge[ArrSize];
  Double_t        IterL3_FromL2_GL_Pt[ArrSize];  //GLobal
  Double_t        IterL3_FromL2_GL_Eta[ArrSize];
  Double_t        IterL3_FromL2_GL_Phi[ArrSize];
  Double_t        IterL3_FromL2_GL_Charge[ArrSize];

  Int_t           nIterL3MuonNoID;
  Double_t        IterL3MuonNoID_Pt[ArrSize];
  Double_t        IterL3MuonNoID_Eta[ArrSize];
  Double_t        IterL3MuonNoID_Phi[ArrSize];
  Double_t        IterL3MuonNoID_Charge[ArrSize];
  Int_t           IterL3MuonNoID_IsGLB[ArrSize];
  Int_t           IterL3MuonNoID_IsSTA[ArrSize];
  Int_t           IterL3MuonNoID_IsTRK[ArrSize];

  NtupleHandle( TChain* _chain):
  vec_FiredTrigger(0),
  vec_FilterName(0),
  vec_HLTObj_Pt(0),
  vec_HLTObj_Eta(0),
  vec_HLTObj_Phi(0),
  vec_MyFiredTrigger(0),
  vec_MyFilterName(0),
  vec_MyHLTObj_Pt(0),
  vec_MyHLTObj_Eta(0),
  vec_MyHLTObj_Phi(0)
  {
    this->chain = _chain;
    // chain->SetBranchStatus("*", 0);

    this->TurnOnBranches_GenParticle();
    this->TurnOnBranches_Event();
    this->TurnOnBranches_HLT();
    this->TurnOnBranches_Muon();
    this->TurnOnBranches_HLTRerunObject();
    this->TurnOnBranches_IterL3OI();
    this->TurnOnBranches_IterL3IO_L2Seeded();
    this->TurnOnBranches_IterL3IO_FromL1();
    this->TurnOnBranches_IterL3_FromL2();
    this->TurnOnBranches_IterL3MuonNoID();
  }

  void GetEvent(Int_t i_event )
  {
    chain->GetEntry(i_event);
  }

  void TurnOffBranches_All()
  {
    chain->SetBranchStatus("*", 0);
  }

  void TurnOnBranches_Event()
  {
    chain->SetBranchStatus("IsRealData", 1);
    chain->SetBranchAddress("IsRealData", &IsRealData);

    chain->SetBranchStatus("RunNum", 1);
    chain->SetBranchAddress("RunNum", &RunNum);

    chain->SetBranchStatus("LumiBlockNum", 1);
    chain->SetBranchAddress("LumiBlockNum", &LumiBlockNum);

    chain->SetBranchStatus("EventNum", 1);
    chain->SetBranchAddress("EventNum", &EventNum);

    chain->SetBranchStatus("BX_ID", 1);
    chain->SetBranchAddress("BX_ID", &BX_ID);

    chain->SetBranchStatus("InstLumi", 1);
    chain->SetBranchAddress("InstLumi", &InstLumi);

    chain->SetBranchStatus("DataPU", 1);
    chain->SetBranchAddress("DataPU", &DataPU);

    chain->SetBranchStatus("DataPURMS", 1);
    chain->SetBranchAddress("DataPURMS", &DataPURMS);

    chain->SetBranchStatus("BunchLumi", 1);
    chain->SetBranchAddress("BunchLumi", &BunchLumi);

    chain->SetBranchStatus("OfflineInstLumi", 1);
    chain->SetBranchAddress("OfflineInstLumi", &OfflineInstLumi);

    chain->SetBranchStatus("OfflineDataPU", 1);
    chain->SetBranchAddress("OfflineDataPU", &OfflineDataPU);

    chain->SetBranchStatus("OfflineDataPURMS", 1);
    chain->SetBranchAddress("OfflineDataPURMS", &OfflineDataPURMS);

    chain->SetBranchStatus("OfflineBunchLumi", 1);
    chain->SetBranchAddress("OfflineBunchLumi", &OfflineBunchLumi);

    chain->SetBranchStatus("TruePU", 1);
    chain->SetBranchAddress("TruePU", &TruePU);

    chain->SetBranchStatus("nVertices", 1);
    chain->SetBranchAddress("nVertices", &nVertices);

    chain->SetBranchStatus("Rho_Offline", 1);
    chain->SetBranchAddress("Rho_Offline", &Rho_Offline);

    chain->SetBranchStatus("Rho", 1);
    chain->SetBranchAddress("Rho", &Rho);

    chain->SetBranchStatus("RhoECAL", 1);
    chain->SetBranchAddress("RhoECAL", &RhoECAL);

    chain->SetBranchStatus("RhoHCAL", 1);
    chain->SetBranchAddress("RhoHCAL", &RhoHCAL);

    chain->SetBranchStatus("GenEventWeight", 1);
    chain->SetBranchAddress("GenEventWeight", &GenEventWeight);

    chain->SetBranchStatus("vec_FiredTrigger", 1);
    chain->SetBranchAddress("vec_FiredTrigger", &vec_FiredTrigger);

    chain->SetBranchStatus("vec_FilterName", 1);
    chain->SetBranchAddress("vec_FilterName", &vec_FilterName);

    chain->SetBranchStatus("vec_MyFiredTrigger", 1);
    chain->SetBranchAddress("vec_MyFiredTrigger", &vec_MyFiredTrigger);

    chain->SetBranchStatus("vec_MyFilterName", 1);
    chain->SetBranchAddress("vec_MyFilterName", &vec_MyFilterName);

    // -- # particles -- //
    chain->SetBranchStatus("nGenParticle", 1);
    chain->SetBranchAddress("nGenParticle", &nGenParticle);

    chain->SetBranchStatus("nMuon", 1);
    chain->SetBranchAddress("nMuon", &nMuon);

    chain->SetBranchStatus("nL3Muon", 1);
    chain->SetBranchAddress("nL3Muon", &nL3Muon);

    chain->SetBranchStatus("nL2Muon", 1);
    chain->SetBranchAddress("nL2Muon", &nL2Muon);

    chain->SetBranchStatus("nTkMuon", 1);
    chain->SetBranchAddress("nTkMuon", &nTkMuon);

    chain->SetBranchStatus("nL1Muon", 1);
    chain->SetBranchAddress("nL1Muon", &nL1Muon);

    chain->SetBranchStatus("nIterL3OI", 1);
    chain->SetBranchAddress("nIterL3OI", &nIterL3OI);

    chain->SetBranchStatus("nIterL3IO_L2Seeded", 1);
    chain->SetBranchAddress("nIterL3IO_L2Seeded", &nIterL3IO_L2Seeded);

    chain->SetBranchStatus("nIterL3IO_FromL1", 1);
    chain->SetBranchAddress("nIterL3IO_FromL1", &nIterL3IO_FromL1);

    chain->SetBranchStatus("nIterL3_FromL2", 1);
    chain->SetBranchAddress("nIterL3_FromL2", &nIterL3_FromL2);

    chain->SetBranchStatus("nIterL3MuonNoID", 1);
    chain->SetBranchAddress("nIterL3MuonNoID", &nIterL3MuonNoID);
  }

  void TurnOnBranches_HLT()
  {
    chain->SetBranchStatus("vec_HLTObj_Pt", 1);
    chain->SetBranchAddress("vec_HLTObj_Pt", &vec_HLTObj_Pt);

    chain->SetBranchStatus("vec_HLTObj_Eta", 1);
    chain->SetBranchAddress("vec_HLTObj_Eta", &vec_HLTObj_Eta);

    chain->SetBranchStatus("vec_HLTObj_Phi", 1);
    chain->SetBranchAddress("vec_HLTObj_Phi", &vec_HLTObj_Phi);


    chain->SetBranchStatus("vec_MyHLTObj_Pt", 1);
    chain->SetBranchAddress("vec_MyHLTObj_Pt", &vec_MyHLTObj_Pt);

    chain->SetBranchStatus("vec_MyHLTObj_Eta", 1);
    chain->SetBranchAddress("vec_MyHLTObj_Eta", &vec_MyHLTObj_Eta);

    chain->SetBranchStatus("vec_MyHLTObj_Phi", 1);
    chain->SetBranchAddress("vec_MyHLTObj_Phi", &vec_MyHLTObj_Phi);
  }

  void TurnOnBranches_GenParticle()
  {
    chain->SetBranchStatus("GenParticle_ID", 1);
    chain->SetBranchAddress("GenParticle_ID", &GenParticle_ID);

    chain->SetBranchStatus("GenParticle_Status", 1);
    chain->SetBranchAddress("GenParticle_Status", &GenParticle_Status);

    chain->SetBranchStatus("GenParticle_Mother", 1);
    chain->SetBranchAddress("GenParticle_Mother", &GenParticle_Mother);

    chain->SetBranchStatus("GenParticle_Pt", 1);
    chain->SetBranchAddress("GenParticle_Pt", &GenParticle_Pt);

    chain->SetBranchStatus("GenParticle_Eta", 1);
    chain->SetBranchAddress("GenParticle_Eta", &GenParticle_Eta);

    chain->SetBranchStatus("GenParticle_Phi", 1);
    chain->SetBranchAddress("GenParticle_Phi", &GenParticle_Phi);

    chain->SetBranchStatus("GenParticle_Px", 1);
    chain->SetBranchAddress("GenParticle_Px", &GenParticle_Px);

    chain->SetBranchStatus("GenParticle_Py", 1);
    chain->SetBranchAddress("GenParticle_Py", &GenParticle_Py);

    chain->SetBranchStatus("GenParticle_Pz", 1);
    chain->SetBranchAddress("GenParticle_Pz", &GenParticle_Pz);

    chain->SetBranchStatus("GenParticle_E", 1);
    chain->SetBranchAddress("GenParticle_E", &GenParticle_E);

    chain->SetBranchStatus("GenParticle_Charge", 1);
    chain->SetBranchAddress("GenParticle_Charge", &GenParticle_Charge);

    chain->SetBranchStatus("GenParticle_isPrompt", 1);
    chain->SetBranchAddress("GenParticle_isPrompt", &GenParticle_isPrompt);

    chain->SetBranchStatus("GenParticle_isPromptFinalState", 1);
    chain->SetBranchAddress("GenParticle_isPromptFinalState", &GenParticle_isPromptFinalState);

    chain->SetBranchStatus("GenParticle_isTauDecayProduct", 1);
    chain->SetBranchAddress("GenParticle_isTauDecayProduct", &GenParticle_isTauDecayProduct);

    chain->SetBranchStatus("GenParticle_isPromptTauDecayProduct", 1);
    chain->SetBranchAddress("GenParticle_isPromptTauDecayProduct", &GenParticle_isPromptTauDecayProduct);

    chain->SetBranchStatus("GenParticle_isDirectPromptTauDecayProductFinalState", 1);
    chain->SetBranchAddress("GenParticle_isDirectPromptTauDecayProductFinalState", &GenParticle_isDirectPromptTauDecayProductFinalState);

    chain->SetBranchStatus("GenParticle_isHardProcess", 1);
    chain->SetBranchAddress("GenParticle_isHardProcess", &GenParticle_isHardProcess);

    chain->SetBranchStatus("GenParticle_isLastCopy", 1);
    chain->SetBranchAddress("GenParticle_isLastCopy", &GenParticle_isLastCopy);

    chain->SetBranchStatus("GenParticle_isLastCopyBeforeFSR", 1);
    chain->SetBranchAddress("GenParticle_isLastCopyBeforeFSR", &GenParticle_isLastCopyBeforeFSR);

    chain->SetBranchStatus("GenParticle_isPromptDecayed", 1);
    chain->SetBranchAddress("GenParticle_isPromptDecayed", &GenParticle_isPromptDecayed);

    chain->SetBranchStatus("GenParticle_isDecayedLeptonHadron", 1);
    chain->SetBranchAddress("GenParticle_isDecayedLeptonHadron", &GenParticle_isDecayedLeptonHadron);

    chain->SetBranchStatus("GenParticle_fromHardProcessBeforeFSR", 1);
    chain->SetBranchAddress("GenParticle_fromHardProcessBeforeFSR", &GenParticle_fromHardProcessBeforeFSR);

    chain->SetBranchStatus("GenParticle_fromHardProcessDecayed", 1);
    chain->SetBranchAddress("GenParticle_fromHardProcessDecayed", &GenParticle_fromHardProcessDecayed);

    chain->SetBranchStatus("GenParticle_fromHardProcessFinalState", 1);
    chain->SetBranchAddress("GenParticle_fromHardProcessFinalState", &GenParticle_fromHardProcessFinalState);

    chain->SetBranchStatus("GenParticle_isMostlyLikePythia6Status3", 1);
    chain->SetBranchAddress("GenParticle_isMostlyLikePythia6Status3", &GenParticle_isMostlyLikePythia6Status3);
  }

  void TurnOnBranches_Muon()
  {
    chain->SetBranchStatus("Muon_Pt", 1);
    chain->SetBranchAddress("Muon_Pt", &Muon_Pt);

    chain->SetBranchStatus("Muon_Eta", 1);
    chain->SetBranchAddress("Muon_Eta", &Muon_Eta);

    chain->SetBranchStatus("Muon_Phi", 1);
    chain->SetBranchAddress("Muon_Phi", &Muon_Phi);

    chain->SetBranchStatus("Muon_Px", 1);
    chain->SetBranchAddress("Muon_Px", &Muon_Px);

    chain->SetBranchStatus("Muon_Py", 1);
    chain->SetBranchAddress("Muon_Py", &Muon_Py);

    chain->SetBranchStatus("Muon_Pz", 1);
    chain->SetBranchAddress("Muon_Pz", &Muon_Pz);

    chain->SetBranchStatus("Muon_dB", 1);
    chain->SetBranchAddress("Muon_dB", &Muon_dB);

    chain->SetBranchStatus("Muon_Charge", 1);
    chain->SetBranchAddress("Muon_Charge", &Muon_Charge);

    chain->SetBranchStatus("Muon_IsGLB", 1);
    chain->SetBranchAddress("Muon_IsGLB", &Muon_IsGLB);

    chain->SetBranchStatus("Muon_IsSTA", 1);
    chain->SetBranchAddress("Muon_IsSTA", &Muon_IsSTA);

    chain->SetBranchStatus("Muon_IsTRK", 1);
    chain->SetBranchAddress("Muon_IsTRK", &Muon_IsTRK);

    chain->SetBranchStatus("Muon_IsPF", 1);
    chain->SetBranchAddress("Muon_IsPF", &Muon_IsPF);

    chain->SetBranchStatus("Muon_IsTight", 1);
    chain->SetBranchAddress("Muon_IsTight", &Muon_IsTight);

    chain->SetBranchStatus("Muon_IsMedium", 1);
    chain->SetBranchAddress("Muon_IsMedium", &Muon_IsMedium);

    chain->SetBranchStatus("Muon_IsLoose", 1);
    chain->SetBranchAddress("Muon_IsLoose", &Muon_IsLoose);

    chain->SetBranchStatus("Muon_IsHighPt", 1);
    chain->SetBranchAddress("Muon_IsHighPt", &Muon_IsHighPt);

    chain->SetBranchStatus("Muon_IsSoft", 1);
    chain->SetBranchAddress("Muon_IsSoft", &Muon_IsSoft);

    chain->SetBranchStatus("Muon_Iso03_sumPt", 1);
    chain->SetBranchAddress("Muon_Iso03_sumPt", &Muon_Iso03_sumPt);

    chain->SetBranchStatus("Muon_Iso03_hadEt", 1);
    chain->SetBranchAddress("Muon_Iso03_hadEt", &Muon_Iso03_hadEt);

    chain->SetBranchStatus("Muon_Iso03_emEt", 1);
    chain->SetBranchAddress("Muon_Iso03_emEt", &Muon_Iso03_emEt);

    chain->SetBranchStatus("Muon_PFIso03_Charged", 1);
    chain->SetBranchAddress("Muon_PFIso03_Charged", &Muon_PFIso03_Charged);

    chain->SetBranchStatus("Muon_PFIso03_Neutral", 1);
    chain->SetBranchAddress("Muon_PFIso03_Neutral", &Muon_PFIso03_Neutral);

    chain->SetBranchStatus("Muon_PFIso03_Photon", 1);
    chain->SetBranchAddress("Muon_PFIso03_Photon", &Muon_PFIso03_Photon);

    chain->SetBranchStatus("Muon_PFIso03_SumPU", 1);
    chain->SetBranchAddress("Muon_PFIso03_SumPU", &Muon_PFIso03_SumPU);

    chain->SetBranchStatus("Muon_PFIso04_Charged", 1);
    chain->SetBranchAddress("Muon_PFIso04_Charged", &Muon_PFIso04_Charged);

    chain->SetBranchStatus("Muon_PFIso04_Neutral", 1);
    chain->SetBranchAddress("Muon_PFIso04_Neutral", &Muon_PFIso04_Neutral);

    chain->SetBranchStatus("Muon_PFIso04_Photon", 1);
    chain->SetBranchAddress("Muon_PFIso04_Photon", &Muon_PFIso04_Photon);

    chain->SetBranchStatus("Muon_PFIso04_SumPU", 1);
    chain->SetBranchAddress("Muon_PFIso04_SumPU", &Muon_PFIso04_SumPU);

    chain->SetBranchStatus("Muon_PFCluster03_ECAL", 1);
    chain->SetBranchAddress("Muon_PFCluster03_ECAL", &Muon_PFCluster03_ECAL);

    chain->SetBranchStatus("Muon_PFCluster03_HCAL", 1);
    chain->SetBranchAddress("Muon_PFCluster03_HCAL", &Muon_PFCluster03_HCAL);

    chain->SetBranchStatus("Muon_PFCluster04_ECAL", 1);
    chain->SetBranchAddress("Muon_PFCluster04_ECAL", &Muon_PFCluster04_ECAL);

    chain->SetBranchStatus("Muon_PFCluster04_HCAL", 1);
    chain->SetBranchAddress("Muon_PFCluster04_HCAL", &Muon_PFCluster04_HCAL);

    chain->SetBranchStatus("Muon_NormChi2_GlbTrk", 1);
    chain->SetBranchAddress("Muon_NormChi2_GlbTrk", &Muon_NormChi2_GlbTrk);

    chain->SetBranchStatus("Muon_nTrackerHit_GlbTrk", 1);
    chain->SetBranchAddress("Muon_nTrackerHit_GlbTrk", &Muon_nTrackerHit_GlbTrk);

    chain->SetBranchStatus("Muon_nTrackerLayer_GlbTrk", 1);
    chain->SetBranchAddress("Muon_nTrackerLayer_GlbTrk", &Muon_nTrackerLayer_GlbTrk);

    chain->SetBranchStatus("Muon_nPixelHit_GlbTrk", 1);
    chain->SetBranchAddress("Muon_nPixelHit_GlbTrk", &Muon_nPixelHit_GlbTrk);

    chain->SetBranchStatus("Muon_nMuonHit_GlbTrk", 1);
    chain->SetBranchAddress("Muon_nMuonHit_GlbTrk", &Muon_nMuonHit_GlbTrk);

    chain->SetBranchStatus("Muon_NormChi2_InnerTrk", 1);
    chain->SetBranchAddress("Muon_NormChi2_InnerTrk", &Muon_NormChi2_InnerTrk);

    chain->SetBranchStatus("Muon_nTrackerHit_InnerTrk", 1);
    chain->SetBranchAddress("Muon_nTrackerHit_InnerTrk", &Muon_nTrackerHit_InnerTrk);

    chain->SetBranchStatus("Muon_nTrackerLayer_InnerTrk", 1);
    chain->SetBranchAddress("Muon_nTrackerLayer_InnerTrk", &Muon_nTrackerLayer_InnerTrk);

    chain->SetBranchStatus("Muon_nPixelHit_InnerTrk", 1);
    chain->SetBranchAddress("Muon_nPixelHit_InnerTrk", &Muon_nPixelHit_InnerTrk);

    chain->SetBranchStatus("Muon_dxyVTX_BestTrk", 1);
    chain->SetBranchAddress("Muon_dxyVTX_BestTrk", &Muon_dxyVTX_BestTrk);

    chain->SetBranchStatus("Muon_dxyVTX_BestTrk", 1);
    chain->SetBranchAddress("Muon_dxyVTX_BestTrk", &Muon_dxyVTX_BestTrk);

    chain->SetBranchStatus("Muon_dzVTX_BestTrk", 1);
    chain->SetBranchAddress("Muon_dzVTX_BestTrk", &Muon_dzVTX_BestTrk);

    chain->SetBranchStatus("Muon_nMatchedStation", 1);
    chain->SetBranchAddress("Muon_nMatchedStation", &Muon_nMatchedStation);

    chain->SetBranchStatus("Muon_nMatchedRPCLayer", 1);
    chain->SetBranchAddress("Muon_nMatchedRPCLayer", &Muon_nMatchedRPCLayer);

    chain->SetBranchStatus("Muon_StationMask", 1);
    chain->SetBranchAddress("Muon_StationMask", &Muon_StationMask);
  }

  void TurnOnBranches_HLTRerunObject()
  {
    chain->SetBranchStatus("L3Muon_Pt", 1);
    chain->SetBranchAddress("L3Muon_Pt", &L3Muon_Pt);

    chain->SetBranchStatus("L3Muon_Eta", 1);
    chain->SetBranchAddress("L3Muon_Eta", &L3Muon_Eta);

    chain->SetBranchStatus("L3Muon_Phi", 1);
    chain->SetBranchAddress("L3Muon_Phi", &L3Muon_Phi);

    chain->SetBranchStatus("L3Muon_Charge", 1);
    chain->SetBranchAddress("L3Muon_Charge", &L3Muon_Charge);

    chain->SetBranchStatus("L3Muon_TrkPt", 1);
    chain->SetBranchAddress("L3Muon_TrkPt", &L3Muon_TrkPt);

    chain->SetBranchStatus("L3Muon_TrkIso", 1);
    chain->SetBranchAddress("L3Muon_TrkIso", &L3Muon_TrkIso);

    chain->SetBranchStatus("L3Muon_ECALIso", 1);
    chain->SetBranchAddress("L3Muon_ECALIso", &L3Muon_ECALIso);

    chain->SetBranchStatus("L3Muon_HCALIso", 1);
    chain->SetBranchAddress("L3Muon_HCALIso", &L3Muon_HCALIso);

    chain->SetBranchStatus("L2Muon_Pt", 1);
    chain->SetBranchAddress("L2Muon_Pt", &L2Muon_Pt);

    chain->SetBranchStatus("L2Muon_Eta", 1);
    chain->SetBranchAddress("L2Muon_Eta", &L2Muon_Eta);

    chain->SetBranchStatus("L2Muon_Phi", 1);
    chain->SetBranchAddress("L2Muon_Phi", &L2Muon_Phi);

    chain->SetBranchStatus("L2Muon_Charge", 1);
    chain->SetBranchAddress("L2Muon_Charge", &L2Muon_Charge);

    chain->SetBranchStatus("L2Muon_TrkPt", 1);
    chain->SetBranchAddress("L2Muon_TrkPt", &L2Muon_TrkPt);

    chain->SetBranchStatus("TkMuon_Pt", 1);
    chain->SetBranchAddress("TkMuon_Pt", &TkMuon_Pt);

    chain->SetBranchStatus("TkMuon_Eta", 1);
    chain->SetBranchAddress("TkMuon_Eta", &TkMuon_Eta);

    chain->SetBranchStatus("TkMuon_Phi", 1);
    chain->SetBranchAddress("TkMuon_Phi", &TkMuon_Phi);

    chain->SetBranchStatus("TkMuon_Charge", 1);
    chain->SetBranchAddress("TkMuon_Charge", &TkMuon_Charge);

    chain->SetBranchStatus("TkMuon_TrkPt", 1);
    chain->SetBranchAddress("TkMuon_TrkPt", &TkMuon_TrkPt);

    chain->SetBranchStatus("L1Muon_Pt", 1);
    chain->SetBranchAddress("L1Muon_Pt", &L1Muon_Pt);

    chain->SetBranchStatus("L1Muon_Eta", 1);
    chain->SetBranchAddress("L1Muon_Eta", &L1Muon_Eta);

    chain->SetBranchStatus("L1Muon_Phi", 1);
    chain->SetBranchAddress("L1Muon_Phi", &L1Muon_Phi);

    chain->SetBranchStatus("L1Muon_Charge", 1);
    chain->SetBranchAddress("L1Muon_Charge", &L1Muon_Charge);

    chain->SetBranchStatus("L1Muon_Quality", 1);
    chain->SetBranchAddress("L1Muon_Quality", &L1Muon_Quality);
  }

  void TurnOnBranches_IterL3_FromL2()
  {
    chain->SetBranchStatus("IterL3_FromL2_TK_Pt", 1);
    chain->SetBranchAddress("IterL3_FromL2_TK_Pt", &IterL3_FromL2_TK_Pt);

    chain->SetBranchStatus("IterL3_FromL2_TK_Eta", 1);
    chain->SetBranchAddress("IterL3_FromL2_TK_Eta", &IterL3_FromL2_TK_Eta);

    chain->SetBranchStatus("IterL3_FromL2_TK_Phi", 1);
    chain->SetBranchAddress("IterL3_FromL2_TK_Phi", &IterL3_FromL2_TK_Phi);

    chain->SetBranchStatus("IterL3_FromL2_TK_Charge", 1);
    chain->SetBranchAddress("IterL3_FromL2_TK_Charge", &IterL3_FromL2_TK_Charge);

    chain->SetBranchStatus("IterL3_FromL2_SA_Pt", 1);
    chain->SetBranchAddress("IterL3_FromL2_SA_Pt", &IterL3_FromL2_SA_Pt);

    chain->SetBranchStatus("IterL3_FromL2_SA_Eta", 1);
    chain->SetBranchAddress("IterL3_FromL2_SA_Eta", &IterL3_FromL2_SA_Eta);

    chain->SetBranchStatus("IterL3_FromL2_SA_Phi", 1);
    chain->SetBranchAddress("IterL3_FromL2_SA_Phi", &IterL3_FromL2_SA_Phi);

    chain->SetBranchStatus("IterL3_FromL2_SA_Charge", 1);
    chain->SetBranchAddress("IterL3_FromL2_SA_Charge", &IterL3_FromL2_SA_Charge);

    chain->SetBranchStatus("IterL3_FromL2_GL_Pt", 1);
    chain->SetBranchAddress("IterL3_FromL2_GL_Pt", &IterL3_FromL2_GL_Pt);

    chain->SetBranchStatus("IterL3_FromL2_GL_Eta", 1);
    chain->SetBranchAddress("IterL3_FromL2_GL_Eta", &IterL3_FromL2_GL_Eta);

    chain->SetBranchStatus("IterL3_FromL2_GL_Phi", 1);
    chain->SetBranchAddress("IterL3_FromL2_GL_Phi", &IterL3_FromL2_GL_Phi);

    chain->SetBranchStatus("IterL3_FromL2_GL_Charge", 1);
    chain->SetBranchAddress("IterL3_FromL2_GL_Charge", &IterL3_FromL2_GL_Charge);
  }

  void TurnOnBranches_IterL3OI()
  {
    chain->SetBranchStatus("IterL3OI_TK_Pt", 1);
    chain->SetBranchAddress("IterL3OI_TK_Pt", &IterL3OI_TK_Pt);

    chain->SetBranchStatus("IterL3OI_TK_Eta", 1);
    chain->SetBranchAddress("IterL3OI_TK_Eta", &IterL3OI_TK_Eta);

    chain->SetBranchStatus("IterL3OI_TK_Phi", 1);
    chain->SetBranchAddress("IterL3OI_TK_Phi", &IterL3OI_TK_Phi);

    chain->SetBranchStatus("IterL3OI_TK_Charge", 1);
    chain->SetBranchAddress("IterL3OI_TK_Charge", &IterL3OI_TK_Charge);

    chain->SetBranchStatus("IterL3OI_SA_Pt", 1);
    chain->SetBranchAddress("IterL3OI_SA_Pt", &IterL3OI_SA_Pt);

    chain->SetBranchStatus("IterL3OI_SA_Eta", 1);
    chain->SetBranchAddress("IterL3OI_SA_Eta", &IterL3OI_SA_Eta);

    chain->SetBranchStatus("IterL3OI_SA_Phi", 1);
    chain->SetBranchAddress("IterL3OI_SA_Phi", &IterL3OI_SA_Phi);

    chain->SetBranchStatus("IterL3OI_SA_Charge", 1);
    chain->SetBranchAddress("IterL3OI_SA_Charge", &IterL3OI_SA_Charge);

    chain->SetBranchStatus("IterL3OI_GL_Pt", 1);
    chain->SetBranchAddress("IterL3OI_GL_Pt", &IterL3OI_GL_Pt);

    chain->SetBranchStatus("IterL3OI_GL_Eta", 1);
    chain->SetBranchAddress("IterL3OI_GL_Eta", &IterL3OI_GL_Eta);

    chain->SetBranchStatus("IterL3OI_GL_Phi", 1);
    chain->SetBranchAddress("IterL3OI_GL_Phi", &IterL3OI_GL_Phi);

    chain->SetBranchStatus("IterL3OI_GL_Charge", 1);
    chain->SetBranchAddress("IterL3OI_GL_Charge", &IterL3OI_GL_Charge);
  }

  void TurnOnBranches_IterL3IO_L2Seeded()
  {
    chain->SetBranchStatus("IterL3IO_L2Seeded_TK_Pt", 1);
    chain->SetBranchAddress("IterL3IO_L2Seeded_TK_Pt", &IterL3IO_L2Seeded_TK_Pt);

    chain->SetBranchStatus("IterL3IO_L2Seeded_TK_Eta", 1);
    chain->SetBranchAddress("IterL3IO_L2Seeded_TK_Eta", &IterL3IO_L2Seeded_TK_Eta);

    chain->SetBranchStatus("IterL3IO_L2Seeded_TK_Phi", 1);
    chain->SetBranchAddress("IterL3IO_L2Seeded_TK_Phi", &IterL3IO_L2Seeded_TK_Phi);

    chain->SetBranchStatus("IterL3IO_L2Seeded_TK_Charge", 1);
    chain->SetBranchAddress("IterL3IO_L2Seeded_TK_Charge", &IterL3IO_L2Seeded_TK_Charge);

    chain->SetBranchStatus("IterL3IO_L2Seeded_SA_Pt", 1);
    chain->SetBranchAddress("IterL3IO_L2Seeded_SA_Pt", &IterL3IO_L2Seeded_SA_Pt);

    chain->SetBranchStatus("IterL3IO_L2Seeded_SA_Eta", 1);
    chain->SetBranchAddress("IterL3IO_L2Seeded_SA_Eta", &IterL3IO_L2Seeded_SA_Eta);

    chain->SetBranchStatus("IterL3IO_L2Seeded_SA_Phi", 1);
    chain->SetBranchAddress("IterL3IO_L2Seeded_SA_Phi", &IterL3IO_L2Seeded_SA_Phi);

    chain->SetBranchStatus("IterL3IO_L2Seeded_SA_Charge", 1);
    chain->SetBranchAddress("IterL3IO_L2Seeded_SA_Charge", &IterL3IO_L2Seeded_SA_Charge);

    chain->SetBranchStatus("IterL3IO_L2Seeded_GL_Pt", 1);
    chain->SetBranchAddress("IterL3IO_L2Seeded_GL_Pt", &IterL3IO_L2Seeded_GL_Pt);

    chain->SetBranchStatus("IterL3IO_L2Seeded_GL_Eta", 1);
    chain->SetBranchAddress("IterL3IO_L2Seeded_GL_Eta", &IterL3IO_L2Seeded_GL_Eta);

    chain->SetBranchStatus("IterL3IO_L2Seeded_GL_Phi", 1);
    chain->SetBranchAddress("IterL3IO_L2Seeded_GL_Phi", &IterL3IO_L2Seeded_GL_Phi);

    chain->SetBranchStatus("IterL3IO_L2Seeded_GL_Charge", 1);
    chain->SetBranchAddress("IterL3IO_L2Seeded_GL_Charge", &IterL3IO_L2Seeded_GL_Charge);
  }

  void TurnOnBranches_IterL3IO_FromL1()
  {
    chain->SetBranchStatus("IterL3IO_FromL1_Pt", 1);
    chain->SetBranchAddress("IterL3IO_FromL1_Pt", &IterL3IO_FromL1_Pt);

    chain->SetBranchStatus("IterL3IO_FromL1_Eta", 1);
    chain->SetBranchAddress("IterL3IO_FromL1_Eta", &IterL3IO_FromL1_Eta);

    chain->SetBranchStatus("IterL3IO_FromL1_Phi", 1);
    chain->SetBranchAddress("IterL3IO_FromL1_Phi", &IterL3IO_FromL1_Phi);

    chain->SetBranchStatus("IterL3IO_FromL1_Charge", 1);
    chain->SetBranchAddress("IterL3IO_FromL1_Charge", &IterL3IO_FromL1_Charge);
  }

  void TurnOnBranches_IterL3MuonNoID()
  {
    chain->SetBranchStatus("IterL3MuonNoID_Pt", 1);
    chain->SetBranchAddress("IterL3MuonNoID_Pt", &IterL3MuonNoID_Pt);

    chain->SetBranchStatus("IterL3MuonNoID_Eta", 1);
    chain->SetBranchAddress("IterL3MuonNoID_Eta", &IterL3MuonNoID_Eta);

    chain->SetBranchStatus("IterL3MuonNoID_Phi", 1);
    chain->SetBranchAddress("IterL3MuonNoID_Phi", &IterL3MuonNoID_Phi);

    chain->SetBranchStatus("IterL3MuonNoID_Charge", 1);
    chain->SetBranchAddress("IterL3MuonNoID_Charge", &IterL3MuonNoID_Charge);

    chain->SetBranchStatus("IterL3MuonNoID_IsGLB", 1);
    chain->SetBranchAddress("IterL3MuonNoID_IsGLB", &IterL3MuonNoID_IsGLB);

    chain->SetBranchStatus("IterL3MuonNoID_IsSTA", 1);
    chain->SetBranchAddress("IterL3MuonNoID_IsSTA", &IterL3MuonNoID_IsSTA);

    chain->SetBranchStatus("IterL3MuonNoID_IsTRK", 1);
    chain->SetBranchAddress("IterL3MuonNoID_IsTRK", &IterL3MuonNoID_IsTRK);
  }

};