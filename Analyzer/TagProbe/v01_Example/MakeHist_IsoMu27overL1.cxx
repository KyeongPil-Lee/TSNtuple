#include <TagProbe/TnPTool_New.h>
#include <memory>

class TnPPair: public TnPPairBase {
public:
  TnPPair( KPMuon tagCand, KPMuon probeCand, NtupleHandle* ntuple ): 
  TnPPairBase( tagCand, probeCand, ntuple )
  {

  }

  // -- user-defined tag condition -- //
  Bool_t IsTag() {
    // -- IsoMu27 final filter: hltL3crIsoL1sMu22Or25L1f0L2f10QL3f27QL3trkIsoFiltered0p07 -- //
    // -- Mu50 final filter: hltL3fL1sMu22Or25L1f0L2f10QL3Filtered50Q -- //
    Bool_t flag = kFALSE;

    if( tag_.IsHLTFilterMatched( ntuple_, "hltL3crIsoL1sMu22Or25L1f0L2f10QL3f27QL3trkIsoFiltered0p07" ) &&
        tag_.Pt > 29 &&
        fabs(tag_.Eta) < 2.4 &&
        tag_.IsTight && 
        tag_.RelPFIso_dBeta < 0.15 )
      flag = kTRUE;

    // if( flag )
    //   cout << "Tag is found" << endl;

    return flag;
  }

  // -- user-defined probe condition -- //
  Bool_t IsProbe() {
    Bool_t flag = kFALSE;

    if( probe_.IsTight && 
        probe_.RelPFIso_dBeta < 0.15 && 
        probe_.IsL1Matched(ntuple_, 22) )
      flag = kTRUE;

    return flag;
  }

  // -- user-defined passing probe condition -- //
  Bool_t IsPassingProbe() {
    Bool_t flag = kFALSE;
    if( probe_.IsMYHLTFilterMatched( ntuple_, "hltL3crIsoL1sMu22Or25L1f0L2f10QL3f27QL3trkIsoFiltered0p07" ) )
      flag = kTRUE;

    return flag;
  }

};

class HistProducer {
 public:

  void SetOutputFileName( TString outputFileName ) {
    outputFileName_ = outputFileName;
  }

  void AddDataPath( TString dataPath ) {
    printf("[Add data path: %s]\n", dataPath.Data() );
    dataPaths_.push_back( dataPath );
  }

  void Set_minPt( Double_t value ) {
    minPt_ = value;
  }

  void Produce() {

    TChain* chain = new TChain("ntupler/ntuple");
    for(const auto& dataPath : dataPaths_ )
      chain->Add(dataPath);

    NtupleHandle* ntuple = new NtupleHandle( chain );

    std::unique_ptr<TnPHistProducer> tnpHist( new TnPHistProducer() );
    tnpHist->Set_ptCut( minPt_ ); // -- only probes above this pT cut will be filled in histograms -- //

    Int_t nEvent = chain->GetEntries();
    std::cout << "[Total event: " << nEvent << "]" << std::endl;

    // nEvent = 1000000;
    for(Int_t i_ev=0; i_ev<nEvent; i_ev++) {
      loadBar(i_ev+1, nEvent, 100, 100);

      ntuple->GetEvent( i_ev );

      KPEvent event( ntuple );
      Double_t weight = event.IsRealData? 1.0 : event.GenEventWeight;

      for(Int_t i_mu=0; i_mu<event.nMuon; i_mu++) {
        KPMuon mu_ith( ntuple, i_mu );
        for(Int_t j_mu=i_mu+1; j_mu<event.nMuon; j_mu++) { // -- starts from i_mu+1: no duplication -- //
          KPMuon mu_jth( ntuple, j_mu );

          TnPPair *tnpPair_ij = new TnPPair( mu_ith, mu_jth, ntuple );
          if( tnpPair_ij->IsValid() )  {
            tnpHist->Fill( tnpPair_ij, weight );
          }
          else { // -- test the other combination
            TnPPair *tnpPair_ji = new TnPPair( mu_jth, mu_ith, ntuple );
            if( tnpPair_ji->IsValid() ) {
              tnpHist->Fill( tnpPair_ji, weight );
            }
            delete tnpPair_ji;
          }

          delete tnpPair_ij;
        } // -- end of j-th muon iteration
      } // -- end of i-th muon iteration

    } // -- end of event iteration

    TFile *f_output = TFile::Open(outputFileName_, "RECREATE");
    tnpHist->Save( f_output );
    f_output->Close();

    cout << "finished" << endl;

    delete ntuple;
    delete chain;
  }

private:
  TString outputFileName_;
  vector<TString> dataPaths_;
  Double_t minPt_;

};

void MakeHist_IsoMu27overL1() {
  std::unique_ptr<HistProducer> histProducer( new HistProducer() );
  histProducer->SetOutputFileName("ROOTFile_TnPHist_example.root");
  histProducer->AddDataPath("ntuple_9.root");
  histProducer->Set_minPt( 29 ); // -- min pT applied for eta, phi and vtx

  histProducer->Produce();
}
