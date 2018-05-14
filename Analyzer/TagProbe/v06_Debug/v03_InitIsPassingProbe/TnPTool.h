#include <Include/NtupleHandle.h>
#include <Include/Object.h>
#include <Include/SimplePlotTools.h>
#include <TEfficiency.h>

static inline void loadBar(int x, int n, int r, int w) {
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

class TnPPairBase {
public:

  KPMuon tag_;
  KPMuon probe_;
  Bool_t isValid_;
  Bool_t isPassingProbe_;

  Double_t mass_;
  Int_t nVtx_;

  NtupleHandle* ntuple_;

  TnPPairBase( KPMuon tagCand, KPMuon probeCand, NtupleHandle* ntuple ):
  tag_(tagCand),
  probe_(probeCand),
  ntuple_(ntuple) 
  {
    Init();
  }

  Bool_t IsValid() {
    // cout << "isValid_: " << isValid_ << endl;

    if( IsTag() && IsProbe() ) {
      mass_ = (tag_.LVec_P + probe_.LVec_P).M(); // -- used in IsGoodPair

      if( IsGoodPair() ) {
        isValid_ = kTRUE;
        nVtx_ = ntuple_->nVertices;

        // printf("\t\t[Valid T&P pair is found]\n");

        if( IsPassingProbe() ) isPassingProbe_ = kTRUE;

        // if( isPassingProbe_) 
        //   printf("\t\t\tProbe: Passing probe\n");
        // else
        //   printf("\t\t\tProbe: Failing probe\n");

        // if( isPassingProbe_) cout << "\tPassing probe" << endl;
      }
    }

    return isValid_;
  }

  Double_t Mass() {
    if( !isValid_ ) {
      cout << "Call mass value of invalid Tag & Probe pair! ... please check the code" << endl;
      return -999;
    }

    return mass_;
  }

  Double_t ProbePt() { return probe_.Pt; }
  Double_t ProbeEta() { return probe_.Eta; }
  Double_t ProbePhi() { return probe_.Phi; }
  Int_t nVtx() { return nVtx_; }

  Bool_t Get_isPassingProbe() {
    return isPassingProbe_;
  }

  void Init() {
    isValid_ = kFALSE;
    mass_ = -999;
    nVtx_ = -999;
    isPassingProbe_ = kFALSE;
  }

  // -- user-defined tag condition
  virtual Bool_t IsTag() {
    Bool_t flag = kFALSE;

    cout << "default IsTag" << endl;

    return flag;
  }

  // -- user-defined probe condition
  virtual Bool_t IsProbe() {
    Bool_t flag = kFALSE;

    cout << "default IsProbe" << endl;

    return flag;
  }

  // -- user-defined probe condition
  virtual Bool_t IsPassingProbe() {
    Bool_t flag = kFALSE;

    cout << "default IsPassingProbe" << endl;

    return flag;
  }

  // -- could be re-defined
  virtual Bool_t IsGoodPair() {
    Bool_t flag = kFALSE;

    Double_t deltaR = tag_.LVec_P.DeltaR(probe_.LVec_P);

    if( mass_ > 49.9 && mass_ < 130.1 && deltaR > 0.3 )
      flag = kTRUE;

    return flag;
  }
};

// -- contains all necessary histograms for TnP
// ---- pair mass histograms for each bin
// ------ passing probes
// ------ failing probes
// ---- template histogram for the efficiency plot
class TnPHist {
public:

  TnPHist() {
    cout << "Default constructor" << endl;
    cout << "Use TnPHist( TString binType, vector<Double_t> vec_BinEdge )" << endl;
  }

  TnPHist( TString binType, Double_t minPtCut, vector<Double_t> vec_BinEdge ) {
    binType_ = binType;
    minPtCut_ = minPtCut;

    nBin_ = (Int_t)vec_BinEdge.size()-1; // -- # bins = # bin edges - 1

    BinEdges_ = new Double_t[nBin_+1]; // -- dynamic allocation   
    for(Int_t i=0; i<nBin_+1; i++)
      BinEdges_[i] = vec_BinEdge[i];

    GenerateHists();
  }

  ~TnPHist() {
    delete BinEdges_;

    for( auto passHist : passHists_ ) delete passHist;
    for( auto failHist : failHists_ ) delete failHist;

    delete hEffTemplate_;
  }

  void Fill( TnPPairBase* pair, Double_t value, Double_t weight = 1.0 ) {

    if( pair->ProbePt() < minPtCut_ ) return;

    Int_t i_hist = FindBinNumber(value);
    if( i_hist < 0 ) return; // -- out of bin range

    Double_t mass = pair->Mass();
    if( pair->Get_isPassingProbe() )
      passHists_[i_hist]->Fill( mass, weight );
    else
      failHists_[i_hist]->Fill( mass, weight );
  }

  void Save( TFile* f_output ) {
    for(const auto& passHist : passHists_ ) passHist->Write();
    for(const auto& failHist : failHists_ ) failHist->Write();

    hEffTemplate_->Write();
  }

  TH1D* hEffTemplate() { return hEffTemplate_; }

private:
  TString binType_;
  Double_t minPtCut_;

  Int_t nBin_;
  Double_t* BinEdges_;

  vector<TH1D*> passHists_;
  vector<TH1D*> failHists_;

  // -- template histogram for the efficiency plot
  TH1D* hEffTemplate_;

  void GenerateHists() {
    Double_t minMass = 50;
    Double_t maxMass = 130;
    Int_t nMassBin = (Int_t)(maxMass - minMass); // -- bin size = 1 GeV -- //

    TString histNameBase = TString::Format("h%s", binType_.Data());

    for(Int_t i=0; i<nBin_; i++)
    {
      TString binInfo = TString::Format("%02dbin", i);

      TString histNamePass = histNameBase + "Pass_" + binInfo;
      TH1D* hTempPass = new TH1D(histNamePass, "", nMassBin, minMass, maxMass );
      passHists_.push_back( hTempPass );

      TString histNameFail = histNameBase + "Fail_" + binInfo;
      TH1D* hTempFail = new TH1D(histNameFail, "", nMassBin, minMass, maxMass );
      failHists_.push_back( hTempFail );
    }

    hEffTemplate_ = new TH1D("hEffTemplate"+binType_, "", nBin_, BinEdges_);
  }

  Int_t FindBinNumber(Double_t value) {
    Int_t i_return = -1;

    for(Int_t i=0; i<nBin_; i++) {
      if( value > BinEdges_[i] && value < BinEdges_[i+1] ) {       
        i_return = i;
        break;
      }
    }

    return i_return;
  }
};

class TnPHistProducer {
public:
  TnPHistProducer() {
    Init();
  }

  ~TnPHistProducer() {
    delete TnPHistPt_;
    delete TnPHistHighPt_;
    delete TnPHistEta_;
    delete TnPHistPhi_;
    delete TnPHistVtx_;
  }

  void Set_ptCut( Double_t ptCut ) {
    ptCut_ = ptCut;
  }

  void Fill( TnPPairBase* pair, Double_t weight = 1.0 ) {
    TnPHistPt_->Fill( pair, pair->ProbePt(), weight );
    TnPHistHighPt_->Fill( pair, pair->ProbePt(), weight );
    TnPHistEta_->Fill( pair, pair->ProbeEta(), weight );
    TnPHistPhi_->Fill( pair, pair->ProbePhi(), weight );
    TnPHistVtx_->Fill( pair, pair->nVtx(), weight );
  }

  void Save( TFile *f_output ) {
    TnPHistPt_->Save( f_output );
    TnPHistHighPt_->Save( f_output );
    TnPHistEta_->Save( f_output );
    TnPHistPhi_->Save( f_output );
    TnPHistVtx_->Save( f_output );
  }

private:
  Double_t ptCut_;
  TnPHist* TnPHistPt_;
  TnPHist* TnPHistHighPt_;
  TnPHist* TnPHistEta_;
  TnPHist* TnPHistPhi_;
  TnPHist* TnPHistVtx_;

  void Init() {
    // -- binnig
    vector<Double_t> vec_PtBinEdge = {0, 10, 15, 20, 22, 24, 26, 27, 28, 30, 40, 50, 60, 80, 120, 200, 500};
    vector<Double_t> vec_HighPtBinEdge = {0, 10, 15, 20, 25, 30, 40, 45, 48, 50, 52, 55, 60, 80, 120, 200, 500};
    vector<Double_t> vec_EtaBinEdge = {-2.4, -2.1, -1.6, -1.2, -0.9, -0.3, -0.2, 0, 0.2, 0.3, 0.9, 1.2, 1.6, 2.1, 2.4};
    Double_t degree15 = 3.141592 / 12.0;
    vector<Double_t> vec_PhiBinEdge =
    {
      (-1)*degree15*12, (-1)*degree15*11, (-1)*degree15*9, (-1)*degree15*7, (-1)*degree15*5, 
      (-1)*degree15*3, (-1)*degree15*1, degree15*1, degree15*3, degree15*5, 
      degree15*7, degree15*9, degree15*11, degree15*12
    };
    vector<Double_t> vec_VtxBinEdge = 
    {
      2.5, 4.5, 6.5, 8.5, 10.5, 12.5, 14.5, 16.5, 18.5, 20.5, 
      22.5, 24.5, 26.5, 28.5, 30.5, 32.5, 34.5, 36.5, 38.5, 40.5,
      42.5, 44.5, 46.5, 48.5, 50.5
    };

    TnPHistPt_ = new TnPHist("Pt", 0, vec_PtBinEdge);
    TnPHistHighPt_ = new TnPHist("HighPt", 0, vec_HighPtBinEdge);
    TnPHistEta_ = new TnPHist("Eta", ptCut_, vec_EtaBinEdge);
    TnPHistPhi_ = new TnPHist("Phi", ptCut_, vec_PhiBinEdge);
    TnPHistVtx_ = new TnPHist("Vtx", ptCut_, vec_VtxBinEdge);
  }

};

class TnPEffTool {
public:
  TnPEffTool() {
    Init();
  }

  TnPEffTool( TString inputFileName ) : TnPEffTool() {
    inputFileName_ = inputFileName;
  }

  void SetCutAndCountRange(Double_t min, Double_t max)
  {
    minMass_ = min;
    maxMass_ = max;
  }

  TGraphAsymmErrors* CalcTnPEff_CutAndCount( TString varName ) {
    TH1D* hEffTemp = PlotTool::Get_Hist( inputFileName_, "hEffTemplate"+varName, "hEff"+varName);
    Int_t nBin = hEffTemp->GetNbinsX();

    vector< TH1D* > passHists;
    vector< TH1D* > failHists;

    TString histNameBase = TString::Format("h%s", varName.Data());
    for(Int_t i=0; i<nBin; i++) {
      TString binInfo = TString::Format("%02dbin", i);

      TString histNamePass = histNameBase + "Pass_" + binInfo;
      TH1D* hTempPass = PlotTool::Get_Hist( inputFileName_, histNamePass );
      passHists.push_back( hTempPass );

      TString histNameFail = histNameBase + "Fail_" + binInfo;
      TH1D* hTempFail = PlotTool::Get_Hist( inputFileName_, histNameFail );
      failHists.push_back( hTempFail );
    }

    TH1D* h_nPass = (TH1D*)hEffTemp->Clone();
    TH1D* h_nTotal = (TH1D*)hEffTemp->Clone();

    Double_t sum_nPass = 0;
    Double_t sum_nTotal = 0;
    for(Int_t i=0; i<nBin; i++) {
      Int_t i_bin = i+1;

      Double_t nEventPass = CountEvent( passHists[i] );
      h_nPass->SetBinContent(i_bin, nEventPass );
      h_nPass->SetBinError( i_bin, sqrt(nEventPass) );

      Double_t nEventFail = CountEvent( failHists[i] );
      Double_t nEventTotal = nEventPass + nEventFail;
      h_nTotal->SetBinContent(i_bin, nEventTotal );
      h_nTotal->SetBinError(i_bin, sqrt(nEventTotal) );

      sum_nPass += nEventPass;
      sum_nTotal += nEventTotal;
    }

    TEfficiency *TEff = new TEfficiency(*h_nPass, *h_nTotal);
    TGraphAsymmErrors *gEff = (TGraphAsymmErrors*)TEff->CreateGraph()->Clone();

    for(Int_t i=0; i<nBin; i++) {
      Int_t i_bin = i+1;
      Double_t nEventPass = h_nPass->GetBinContent(i_bin);
      Double_t nEventTotal = h_nTotal->GetBinContent(i_bin);

      Double_t binCenter, eff;
      gEff->GetPoint(i, binCenter, eff);

      Double_t effErrHigh = gEff->GetErrorYhigh(i);
      Double_t relEffErrHigh = (effErrHigh / eff) * 100;
      Double_t effErrLow = gEff->GetErrorYlow(i);
      Double_t relEffErrLow = (effErrLow / eff) * 100;

      printf("[%02d bin] (%6.1lf to %6.1lf): eff (%8.1lf / %8.1lf) = %.3lf + %.3lf(%.3lf%%) - %.3lf(%.3lf%%)\n",
              i_bin, hEffTemp->GetBinLowEdge(i_bin), hEffTemp->GetBinLowEdge(i_bin+1), nEventPass, nEventTotal, eff, effErrHigh, relEffErrHigh, effErrLow, relEffErrLow);
    }

    Calc_OverallEff( sum_nPass, sum_nTotal );

    cout << endl;

    return gEff;
  }

private:
  Double_t minMass_;
  Double_t maxMass_;
  TString inputFileName_;

  void Init() {
    inputFileName_ = "";
    minMass_ = 81;
    maxMass_ = 101;
    cout << "==========================================================" << endl;
    cout << "Default cut & count mass range: " << minMass_ << " < M < " << maxMass_ << " GeV" << endl;
    cout << "==========================================================" << endl;
  }

  Double_t CountEvent( TH1D* h )
  {
    Double_t nTotEvent = 0;

    Int_t nBin = h->GetNbinsX();
    for(Int_t i=0; i<nBin; i++)
    {
      Int_t i_bin = i+1;
      Double_t BinCenter = h->GetBinCenter(i_bin);
      if( BinCenter > minMass_ && BinCenter < maxMass_ )
      {
        Double_t nEvent = h->GetBinContent(i_bin);
        nTotEvent += nEvent;
      }
    }
    return nTotEvent;
  }

  void Calc_OverallEff( Double_t nPass, Double_t nTotal )
  {
    TH1D* h_singleBin = new TH1D("h_singleBin", "", 1, 0, 1 );
    TH1D* h_nPass = (TH1D*)h_singleBin->Clone();
    h_nPass->SetBinContent(1, nPass);
    h_nPass->SetBinError(1, sqrt(nPass));

    TH1D* h_nTotal = (TH1D*)h_singleBin->Clone();
    h_nTotal->SetBinContent(1, nTotal);
    h_nTotal->SetBinError(1, sqrt(nTotal));

    TEfficiency *TEff = new TEfficiency(*h_nPass, *h_nTotal);
    TGraphAsymmErrors *gEff = (TGraphAsymmErrors*)TEff->CreateGraph()->Clone();

    Double_t binCenter, eff;
    gEff->GetPoint(0, binCenter, eff);

    Double_t effErrHigh = gEff->GetErrorYhigh(0);
    Double_t relEffErrHigh = (effErrHigh / eff) * 100;
    Double_t effErrLow = gEff->GetErrorYlow(0);
    Double_t relEffErrLow = (effErrLow / eff) * 100;

    cout << "[Overall efficiency]" << endl;
    printf("eff (%.1lf / %.1lf) = %.3lf + %.3lf(%.3lf%%) - %.3lf(%.3lf%%)\n",
            nPass, nTotal, eff, effErrHigh, relEffErrHigh, effErrLow, relEffErrLow );
  }

};