#pragma once

#include <TH1D.h>
#include <TH2D.h>
#include <TColor.h>
#include <TLegend.h>
#include <TCanvas.h>
#include <TString.h>
#include <TLatex.h>
#include <TFile.h>
#include <TPad.h>
#include <TF1.h>
#include <TGraphAsymmErrors.h>

#include <vector>

namespace PlotTool {

TH1D* Get_Hist(TString fileName, TString histName, TString histName_new = "" )
{
  TH1::AddDirectory(kFALSE);

  TFile* f_input = TFile::Open( fileName );
  TH1D* h_temp = (TH1D*)f_input->Get(histName)->Clone();
  if( histName_new != "" )
    h_temp->SetName( histName_new );

  f_input->Close();

  return h_temp;
}


TGraphAsymmErrors* Get_Graph(TString fileName, TString graphName, TString graphName_New = "" )
{
  TFile *f_input = TFile::Open( fileName );
  TGraphAsymmErrors* g_temp = (TGraphAsymmErrors*)f_input->Get(graphName)->Clone();
  if( graphName_New != "" )
    g_temp->SetName( graphName_New );

  f_input->Close();

  return g_temp;
}

void SetLegend( TLegend *& legend, Double_t xMin = 0.75, Double_t yMin = 0.75, Double_t xMax = 0.95, Double_t yMax = 0.95 )
{
  legend = new TLegend( xMin, yMin, xMax, yMax );
  legend->SetFillStyle(0);
  legend->SetBorderSize(0);
  legend->SetTextFont( 62 );
}

void SetAxis_SinglePad( TAxis *axisX, TAxis *axisY, TString titleX, TString titleY )
{
  axisX->SetTitle( titleX );
  axisX->SetLabelSize(0.04);
  axisX->SetTitleOffset(1.1);
  axisX->SetTitleSize(0.05);
  axisX->SetNoExponent();
  axisX->SetMoreLogLabels();

  axisY->SetTitle( titleY );
  axisY->SetTitleSize(0.05);
  axisY->SetTitleOffset(1.2);
  axisY->SetLabelSize(0.045);
}

void SetAxis_TopPad( TAxis *axisX, TAxis *axisY, TString titleY )
{
  axisX->SetLabelFont(42);
  axisX->SetLabelSize(0.000);
  axisX->SetTitleSize(0.000);

  axisY->SetTitleFont(42);
  axisY->SetTitle( titleY );
  axisY->SetTitleSize(0.05);
  axisY->SetTitleFont(42);
  axisY->SetTitleOffset(1.25);
  axisY->SetLabelFont(42);
  axisY->SetLabelSize(0.04);
}

void SetAxis_BottomPad( TAxis *axisX, TAxis *axisY, TString titleX, TString titleY)
{
  axisX->SetMoreLogLabels();
  axisX->SetNoExponent();
  axisX->SetTitle( titleX );
  axisX->SetTitleOffset( 0.85 );
  axisX->SetTitleSize( 0.2 );
  axisX->SetLabelColor(1);
  axisX->SetLabelFont(42);
  axisX->SetLabelOffset(0.01);
  axisX->SetLabelSize(0.13);

  axisY->SetTitle( titleY );
  axisY->SetTitleOffset( 0.55 );
  axisY->SetTitleSize( 0.12);
  axisY->SetLabelSize( 0.10 );
}

void DrawLine( TF1*& f_line, Int_t color = kRed )
{
  f_line = new TF1("f_line", "1", -10000, 10000);
  f_line->SetLineColor(color);
  f_line->SetLineWidth(1);
  f_line->Draw("PSAME");
}

struct HistInfo
{
  TH1D* h;
  TString legend;
  Int_t color;
};

struct GraphInfo
{
  TGraphAsymmErrors* g;
  TString legend;
  Int_t color;
};

class CanvasBase
{
public:
  TCanvas* c_;
  TString canvasName_;

  TString titleX_;
  TString titleY_;

  Bool_t isLogX_;
  Bool_t isLogY_;

  Double_t legendMinX_;
  Double_t legendMaxX_;
  Double_t legendMinY_;
  Double_t legendMaxY_;

  Double_t minX_;
  Double_t maxX_;
  Bool_t setRangeX_;

  Double_t minY_;
  Double_t maxY_;
  Bool_t setRangeY_;

  TLatex latex_;
  Bool_t setLatexCMSPre_;
  Bool_t setLatexLumiEnergy_;
  Double_t lumi_;
  Int_t energy_;
  Bool_t setLatexCMSSim_;

  // -- for the canvas with ratio plot
  TPad* topPad_;
  TPad* bottomPad_;

  TString titleRatio_;

  Double_t minRatio_;
  Double_t maxRatio_;
  Bool_t setRangeRatio_;

  CanvasBase()
  {
    Init();
  }

  CanvasBase(TString canvasName, Bool_t isLogX = kFALSE, Bool_t isLogY = kFALSE )
  {
    canvasName_ = canvasName_;
    isLogX_ = isLogX;
    isLogY_ = isLogY;
  }

  void SetTitle( TString titleX, TString titleY )
  {
    titleX_ = titleX;
    titleY_ = titleY;
  }

  void SetTitle( TString titleX, TString titleY, TString titleRatio )
  {
    titleX_ = titleX;
    titleY_ = titleY;
    titleRatio_ = titleRatio;
  }

  void SetLegendPosition( Double_t minX, Double_t minY, Double_t maxX, Double_t maxY )
  {
    legendMinX_ = minX;
    legendMinY_ = minY;
    legendMaxX_ = maxX;
    legendMaxY_ = maxY;
  }

  void SetRangeX( Double_t min, Double_t max )
  {
    minX_ = min;
    maxX_ = max;
    setRangeX_ = kTRUE;
  }

  void SetRangeY( Double_t min, Double_t max )
  {
    minY_ = min;
    maxY_ = max;
    setRangeY_ = kTRUE;
  }

  void SetRangeRatio( Double_t min, Double_t max )
  {
    minRatio_ = min;
    maxRatio_ = max;
    setRangeRatio_ = kTRUE;
  }

  void Latex_CMSPre()
  {
    setLatexCMSPre_ = kTRUE;
  }

  void Latex_CMSPre(Double_t lumi, Int_t energy)
  {
    Latex_CMSPre();
    setLatexLumiEnergy_ = kTRUE;
    lumi_ = lumi;
    energy_ = energy;
  }

  void Latex_CMSSim()
  {
    setLatexCMSSim_ = kTRUE;
  }

  // -- implemented later
  virtual void Draw( TString drawOp )
  {

  }

  void Init()
  {
    canvasName_ = "undefined";
    isLogX_ = kFALSE;
    isLogY_ = kFALSE;

    titleX_ = "undefined";
    titleY_ = "undefined";

    legendMinX_ = 0.50;
    legendMinY_ = 0.70;
    legendMaxX_ = 0.95;
    legendMaxY_ = 0.95;

    setRangeX_ = kFALSE;
    minX_ = 0;
    maxX_ = 0;

    setRangeY_ = kFALSE;
    minY_ = 0;
    maxY_ = 0;

    setLatexCMSPre_ = kFALSE;
    setLatexLumiEnergy_ = kFALSE;
    lumi_ = -999;
    energy_ = -999;
    setLatexCMSSim_ = kFALSE;

    // -- for the canvas with ratio plot
    topPad_ = NULL;
    bottomPad_ = NULL;

    titleRatio_ = "undefined";

    setRangeRatio_ = kFALSE;
    minRatio_ = 0;
    maxRatio_ = 2.5;
  }

  void DrawLatex_CMSPre()
  {
    latex_.DrawLatexNDC(0.13, 0.96, "#font[62]{CMS}#font[42]{#it{#scale[0.8]{ Preliminary}}}");
  }

  void DrawLatex_CMSPreLumiEnergy()
  {
    DrawLatex_CMSPre();
    latex_.DrawLatexNDC(0.70, 0.96, "#font[42]{#scale[0.7]{"+TString::Format("%.1lf fb^{-1} (%d TeV)", lumi_, energy_)+"}}");
  }

  void DrawLatex_CMSSim()
  {
    latex_.DrawLatexNDC(0.13, 0.96, "#font[62]{CMS}#font[42]{#it{#scale[0.8]{ Simulation}}}");
    latex_.DrawLatexNDC(0.85, 0.96, "#font[42]{#scale[0.7]{13 TeV}}");
  }

  void SetCanvas_Square()
  {
    c_ = new TCanvas(canvasName_, "", 800, 800);
    c_->cd();
    
    c_->SetTopMargin(0.05);
    c_->SetLeftMargin(0.13);
    c_->SetRightMargin(0.045);
    c_->SetBottomMargin(0.13);

    if( isLogX_ )
      c_->SetLogx();
    if( isLogY_ )
      c_->SetLogy();
  }

  void SetCanvas_Ratio()
  {
    c_ = new TCanvas(canvasName_, "", 800, 800);
    c_->cd();

    topPad_ = new TPad("TopPad","TopPad", 0.01, 0.01, 0.99, 0.99 );
    topPad_->Draw();
    topPad_->cd();

    topPad_->SetTopMargin(0.05);
    topPad_->SetLeftMargin(0.13);
    topPad_->SetRightMargin(0.045);
    topPad_->SetBottomMargin(0.3);

    if( isLogX_ ) topPad_->SetLogx();
    if( isLogY_ ) topPad_->SetLogy();

    c_->cd();
    bottomPad_ = new TPad( "BottomPad", "BottomPad", 0.01, 0.01, 0.99, 0.29 );
    bottomPad_->Draw();
    bottomPad_->cd();
    bottomPad_->SetGridx();
    bottomPad_->SetGridy();
    bottomPad_->SetTopMargin(0.05);
    bottomPad_->SetBottomMargin(0.4);
    bottomPad_->SetRightMargin(0.045);
    bottomPad_->SetLeftMargin(0.13);

    if( isLogX_ ) bottomPad_->SetLogx();
  }
}; // class CanvasBase

class HistCanvas : public CanvasBase
{
public:
  vector<HistInfo> histInfos_;

  Double_t nRebin_;
  Bool_t setRebin_;

  HistCanvas()
  {
    // -- member variables are initialized by Init() in HistCanvasBase()
  }

  HistCanvas(TString canvasName, Bool_t isLogX = kFALSE, Bool_t isLogY = kFALSE ): HistCanvas()
  {
    canvasName_ = canvasName;
    isLogX_ = isLogX;
    isLogY_ = isLogY;
  }

  void Register( TH1D* h, TString legend, Int_t color  )
  {
    HistInfo histInfo{ (TH1D*)h->Clone(), legend, color };
    histInfos_.push_back( histInfo );
  }

  void SetRebin( Int_t n )
  {
    nRebin_ = n;
    setRebin_ = kTRUE;
  }

  void Draw( TString drawOp = "EPSAME" )
  {
    if( !drawOp.Contains("SAME") ) drawOp = drawOp + "SAME";

    TLegend *legend;
    PlotTool::SetLegend( legend, legendMinX_, legendMinY_, legendMaxX_, legendMaxY_ );

    // -- draw canvas
    SetCanvas_Square();

    c_->cd();

    Int_t nHist = histInfos_.size();
    for(Int_t i=0; i<nHist; i++)
    {
      TH1D*& h = histInfos_[i].h;
      TString legendName = histInfos_[i].legend;
      Int_t color = histInfos_[i].color;

      if( setRebin_ ) h->Rebin( nRebin_ );

      h->Draw(drawOp);
      h->SetStats(kFALSE);
      h->SetMarkerStyle(20);
      h->SetMarkerColor(color);
      h->SetLineColor(color);
      h->SetFillColorAlpha(kWhite, 0); 
      h->SetTitle("");

      if( i == 0 ) PlotTool::SetAxis_SinglePad( h->GetXaxis(), h->GetYaxis(), titleX_, titleY_ );
      if( setRangeX_ ) h->GetXaxis()->SetRangeUser( minX_, maxX_ );
      if( setRangeY_ ) h->GetYaxis()->SetRangeUser( minY_, maxY_ );

      legend->AddEntry( h, legendName );
    }

    legend->Draw();

    if( setLatexCMSPre_ )
    {
      if( setLatexLumiEnergy_ ) DrawLatex_CMSPreLumiEnergy();
      else                      DrawLatex_CMSPre();
    }

    if( setLatexCMSSim_ ) DrawLatex_CMSSim();

    c_->SaveAs(".pdf");
  }
}; // -- class HistCanvas

class HistCanvaswRatio: public HistCanvas
{
public:
  vector<HistInfo> histInfoRatios_;


  HistCanvaswRatio()
  {
    // -- member variables are initialized by Init() in HistCanvasBase()
  }

  HistCanvaswRatio(TString canvasName, Bool_t isLogX = kFALSE, Bool_t isLogY = kFALSE ): HistCanvaswRatio()
  {
    canvasName_ = canvasName;
    isLogX_ = isLogX;
    isLogY_ = isLogY;
  }

  void Draw( TString drawOp = "EPSAME" )
  {
    if( !drawOp.Contains("SAME") ) drawOp = drawOp + "SAME";

    TLegend *legend;
    PlotTool::SetLegend( legend, legendMinX_, legendMinY_, legendMaxX_, legendMaxY_ );

    // -- draw canvas
    SetCanvas_Ratio();

    c_->cd();
    topPad_->cd();

    Int_t nHist = histInfos_.size();
    for(Int_t i=0; i<nHist; i++)
    {
      TH1D*& h = histInfos_[i].h;
      TString legendName = histInfos_[i].legend;
      Int_t color = histInfos_[i].color;

      if( setRebin_ ) h->Rebin( nRebin_ );

      h->Draw(drawOp);
      h->SetStats(kFALSE);
      h->SetMarkerStyle(20);
      h->SetMarkerColor(color);
      h->SetLineColor(color);
      h->SetFillColorAlpha(kWhite, 0); 
      h->SetTitle("");

      if( i == 0 ) PlotTool::SetAxis_TopPad( h->GetXaxis(), h->GetYaxis(), titleY_ );
      if( setRangeX_ ) h->GetXaxis()->SetRangeUser( minX_, maxX_ );
      if( setRangeY_ ) h->GetYaxis()->SetRangeUser( minY_, maxY_ );

      legend->AddEntry( h, legendName );
    }

    legend->Draw();

    if( setLatexCMSPre_ )
    {
      if( setLatexLumiEnergy_ ) DrawLatex_CMSPreLumiEnergy();
      else                      DrawLatex_CMSPre();
    }

    if( setLatexCMSSim_ ) DrawLatex_CMSSim();

    // -- bottom pad
    c_->cd();
    bottomPad_->cd();

    CalcRatioHist();

    Int_t nHistRatio = histInfoRatios_.size();
    for(Int_t i=0; i<nHistRatio; i++)
    {
      TH1D*& h_ratio = histInfoRatios_[i].h;
      Int_t  color   = histInfoRatios_[i].color;

      h_ratio->Draw(drawOp);
      h_ratio->SetStats(kFALSE);
      h_ratio->SetMarkerStyle(20);
      h_ratio->SetMarkerColor(color);
      h_ratio->SetLineColor(color);
      h_ratio->SetFillColorAlpha(kWhite, 0); 
      h_ratio->SetTitle("");
      if( i == 0 ) SetAxis_BottomPad(h_ratio->GetXaxis(), h_ratio->GetYaxis(), titleX_, titleRatio_);
      if( setRangeRatio_ ) h_ratio->GetYaxis()->SetRangeUser( minRatio_, maxRatio_ );
    }

    TF1 *f_line;
    PlotTool::DrawLine(f_line);

    c_->SaveAs(".pdf");
  }

  void CalcRatioHist()
  {
    TH1D* h_ref = histInfos_[0].h;
    h_ref->Sumw2();

    Int_t nHist = histInfos_.size();
    for(Int_t i=1; i<nHist; i++) // -- starts with 1 -- //
    {
      TH1D* h_target = (TH1D*)histInfos_[i].h->Clone();
      h_target->Sumw2();
      
      TString legend = histInfos_[i].legend;
      Int_t color = histInfos_[i].color;

      TH1D* h_ratioTemp = (TH1D*)h_ref->Clone();
      h_ratioTemp->Divide( h_target, h_ref );

      HistInfo histInfoRatio{ h_ratioTemp, legend, color };
      histInfoRatios_.push_back( histInfoRatio );
    }
  }
};

class GraphCanvas: public CanvasBase
{
public:

};

}; // -- namespace PlotTool