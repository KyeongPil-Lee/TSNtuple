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
  axisX->SetTitleFont(42);
  axisX->SetTitleSize(0.05);
  axisX->SetTitleOffset(1.1);

  axisX->SetLabelFont(42);
  axisX->SetLabelSize(0.04);
  axisX->SetNoExponent();
  axisX->SetMoreLogLabels();

  axisY->SetTitle( titleY );
  axisY->SetTitleFont(42);
  axisY->SetTitleSize(0.05);
  axisY->SetTitleOffset(1.2);

  axisY->SetLabelFont(42);
  axisY->SetLabelSize(0.04);
}

void SetAxis_TopPad( TAxis *axisX, TAxis *axisY, TString titleY )
{
  axisX->SetLabelFont(42);
  axisX->SetLabelSize(0.000);
  axisX->SetTitleSize(0.000);

  axisY->SetTitle( titleY );
  axisY->SetTitleFont(42);
  axisY->SetTitleSize(0.05);
  axisY->SetTitleOffset(1.25);

  axisY->SetLabelFont(42);
  axisY->SetLabelSize(0.04);
}

void SetAxis_BottomPad( TAxis *axisX, TAxis *axisY, TString titleX, TString titleY)
{

  axisX->SetTitle( titleX );
  axisX->SetTitleFont(42);
  axisX->SetTitleSize( 0.2 );
  axisX->SetTitleOffset( 0.85 );

  axisX->SetLabelFont(42);
  axisX->SetLabelSize(0.13);
  axisX->SetLabelOffset(0.01);
  axisX->SetLabelColor(1);
  axisX->SetMoreLogLabels();
  axisX->SetNoExponent();


  axisY->SetTitle( titleY );
  axisY->SetTitleFont(42);
  axisY->SetTitleSize(0.12);
  axisY->SetTitleOffset( 0.55 );

  axisY->SetLabelFont(42);
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

struct LatexInfo
{
  Double_t x;
  Double_t y;
  TString content;
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

  // -- latex (CMS Preliminary, lumi. info, etc.)
  TLatex latex_;
  Bool_t setLatexCMSPre_;
  Bool_t setLatexLumiEnergy_;
  Double_t lumi_;
  Int_t energy_;
  Bool_t setLatexCMSSim_;

  // -- additional latex info.
  vector<LatexInfo> latexInfos_;
  Bool_t setLatexInfo_;

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

  void RegisterLatex( Double_t x, Double_t y, TString content )
  {
    setLatexInfo_ = kTRUE;
    LatexInfo latexInfo{x, y, content};
    latexInfos_.push_back( latexInfo );
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
    setLatexInfo_ = kFALSE;

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

  void DrawLatexAll()
  {
    if( setLatexCMSPre_ )
    {
      if( setLatexLumiEnergy_ ) DrawLatex_CMSPreLumiEnergy();
      else                      DrawLatex_CMSPre();
    }

    if( setLatexCMSSim_ ) DrawLatex_CMSSim();

    if( setLatexInfo_ )
    {
      for( auto latexInfo : latexInfos_ )
        latex_.DrawLatexNDC( latexInfo.x, latexInfo.y, latexInfo.content );
    }
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
    // -- member variables are initialized by Init() in CanvasBase()
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

    DrawLatexAll();

    c_->SaveAs(".pdf");
  }
}; // -- class HistCanvas

class HistCanvaswRatio: public HistCanvas
{
public:
  vector<HistInfo> histInfoRatios_;


  HistCanvaswRatio()
  {
    // -- member variables are initialized by Init() in CanvasBase()
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

    DrawLatexAll();

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
  vector<GraphInfo> graphInfos_;

  GraphCanvas()
  {
    // -- member variables are initialized by Init() in CanvasBase()
  }

  GraphCanvas(TString canvasName, Bool_t isLogX = kFALSE, Bool_t isLogY = kFALSE ): GraphCanvas()
  {
    canvasName_ = canvasName;
    isLogX_ = isLogX;
    isLogY_ = isLogY;
  }

  void Register( TGraphAsymmErrors* g, TString legend, Int_t color  )
  {
    GraphInfo graphInfo{ (TGraphAsymmErrors*)g->Clone(), legend, color };
    graphInfos_.push_back( graphInfo );
  }

  void Draw( TString drawOp = "EPSAME" )
  {
    if( !drawOp.Contains("SAME") ) drawOp = drawOp + "SAME";

    TLegend *legend;
    PlotTool::SetLegend( legend, legendMinX_, legendMinY_, legendMaxX_, legendMaxY_ );

    // -- draw canvas
    SetCanvas_Square();

    c_->cd();

    Int_t nGraph = graphInfos_.size();
    for(Int_t i=0; i<nGraph; i++)
    {
      TGraphAsymmErrors*& g = graphInfos_[i].g;
      TString legendName = graphInfos_[i].legend;
      Int_t color = graphInfos_[i].color;

      if( i == 0) g->Draw("A"+drawOp);
      else        g->Draw(drawOp);

      g->SetMarkerStyle(20);
      g->SetMarkerColor(color);
      g->SetMarkerSize(1.3);

      g->SetLineColor(color);
      g->SetLineWidth(1.0);

      g->SetFillColorAlpha(kWhite, 0); 
      g->SetTitle("");

      if( i == 0 ) PlotTool::SetAxis_SinglePad( g->GetXaxis(), g->GetYaxis(), titleX_, titleY_ );
      if( setRangeX_ ) g->GetXaxis()->SetLimits( minX_, maxX_ );
      if( setRangeY_ ) g->GetYaxis()->SetRangeUser( minY_, maxY_ );

      legend->AddEntry( g, legendName );
    }

    legend->Draw();

    DrawLatexAll();

    c_->SaveAs(".pdf");
  }
};

class GraphCanvaswRatio: public GraphCanvas
{
public:
  vector<GraphInfo> graphInfoRatios_;

  GraphCanvaswRatio()
  {
    // -- member variables are initialized by Init() in HistCanvasBase()
  }

  GraphCanvaswRatio(TString canvasName, Bool_t isLogX = kFALSE, Bool_t isLogY = kFALSE ): GraphCanvaswRatio()
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

    Int_t nGraph = graphInfos_.size();
    for(Int_t i=0; i<nGraph; i++)
    {
      TGraphAsymmErrors*& g = graphInfos_[i].g;
      TString legendName = graphInfos_[i].legend;
      Int_t color = graphInfos_[i].color;

      if( i == 0) g->Draw("A"+drawOp);
      else        g->Draw(drawOp);

      g->SetMarkerStyle(20);
      g->SetMarkerColor(color);
      g->SetMarkerSize(1.3);

      g->SetLineColor(color);
      g->SetLineWidth(1.0);

      g->SetFillColorAlpha(kWhite, 0); 
      g->SetTitle("");

      if( i == 0 ) PlotTool::SetAxis_TopPad( g->GetXaxis(), g->GetYaxis(), titleY_ );
      if( setRangeX_ ) g->GetXaxis()->SetLimits( minX_, maxX_ );
      if( setRangeY_ ) g->GetYaxis()->SetRangeUser( minY_, maxY_ );

      legend->AddEntry( g, legendName );
    }

    legend->Draw();

    DrawLatexAll();

    // -- bottom pad
    c_->cd();
    bottomPad_->cd();

    CalcRatioGraph();

    Int_t nGraphRatio = graphInfoRatios_.size();
    for(Int_t i=0; i<nGraphRatio; i++)
    {
      TGraphAsymmErrors*& g_ratio = graphInfoRatios_[i].g;
      Int_t               color   = graphInfoRatios_[i].color;

      if( i == 0) g_ratio->Draw("A"+drawOp);
      else        g_ratio->Draw(drawOp);

      g_ratio->SetMarkerStyle(20);
      g_ratio->SetMarkerColor(color);
      g_ratio->SetMarkerSize(1.3);

      g_ratio->SetLineColor(color);
      g_ratio->SetLineWidth(1.0);

      g_ratio->SetFillColorAlpha(kWhite, 0); 
      g_ratio->SetTitle("");

      if( i == 0 ) SetAxis_BottomPad(g_ratio->GetXaxis(), g_ratio->GetYaxis(), titleX_, titleRatio_);
      if( setRangeX_ )     g_ratio->GetXaxis()->SetLimits( minX_, maxX_ );
      if( setRangeRatio_ ) g_ratio->GetYaxis()->SetRangeUser( minRatio_, maxRatio_ );
    }

    TF1 *f_line;
    PlotTool::DrawLine(f_line);

    c_->SaveAs(".pdf");
  }

  void CalcRatioGraph()
  {
    TGraphAsymmErrors* g_ref = graphInfos_[0].g;

    Int_t nGraph = graphInfos_.size();
    for(Int_t i=1; i<nGraph; i++) // -- starts with 1 -- //
    {
      TGraphAsymmErrors* g_target = (TGraphAsymmErrors*)graphInfos_[i].g->Clone();

      TString legend = graphInfos_[i].legend;
      Int_t color = graphInfos_[i].color;

      TGraphAsymmErrors *g_ratioTemp = MakeRatioGraph( g_target, g_ref );

      GraphInfo graphInfoRatio{ g_ratioTemp, legend, color };
      graphInfoRatios_.push_back( graphInfoRatio );
    }
  }

  // -- NUM = Numerator
  // -- DEN = Denominator
  TGraphAsymmErrors* MakeRatioGraph(TGraphAsymmErrors *g_NUM, TGraphAsymmErrors *g_DEN)
  {
    TGraphAsymmErrors* g_ratio = (TGraphAsymmErrors*)g_DEN->Clone();
    g_ratio->Set(0); // --Remove all points (reset) -- //

    Int_t nPoint_NUM = g_NUM->GetN();
    Int_t nPoint_DEN = g_DEN->GetN();
    if( nPoint_NUM != nPoint_DEN )
      printf("# points is different bewteen two graph...be careful for the ratio plot\n");

    for(Int_t i_p=0; i_p<nPoint_NUM; i_p++)
    {
      Double_t x_NUM, y_NUM;
      g_NUM->GetPoint(i_p, x_NUM, y_NUM);
      Double_t error_NUMLow = g_NUM->GetErrorYlow(i_p);
      Double_t error_NUMHigh = g_NUM->GetErrorYhigh(i_p);
      // -- take the larger uncertainty
      Double_t error_NUM = error_NUMLow > error_NUMHigh ? error_NUMLow : error_NUMHigh;

      Double_t x_DEN, y_DEN;
      g_DEN->GetPoint(i_p, x_DEN, y_DEN);
      Double_t error_DENLow = g_DEN->GetErrorYlow(i_p);
      Double_t error_DENHigh = g_DEN->GetErrorYhigh(i_p);
      // -- take the larger uncertainty
      Double_t error_DEN = error_DENLow > error_DENHigh ? error_DENLow : error_DENHigh;

      Double_t ratio;
      Double_t ratio_error;
      if( (nPoint_NUM != nPoint_DEN) && i_p >= nPoint_DEN )
      {
        ratio = 0;
        ratio_error = 0;
      }
      // else if(y_Type1 != 0 && error_Type1 != 0 && y_Type2 != 0 && error_Type2 != 0)
      else if(y_DEN != 0)
      {
        ratio = y_NUM / y_DEN;
        ratio_error = this->Error_PropagatedAoverB(y_NUM, error_NUM, y_DEN, error_DEN);
        //calculate Scale Factor(Type1/Type2) & error

        // cout << "ratio: " << ratio << " ratio_error: " << ratio_error << endl;
      }
      else
      {
        cout << "Denominator is 0! ... ratio and its error are set as 0" << endl;
        ratio = 0;
        ratio_error = 0;
      }

      //Set Central value
      g_ratio->SetPoint(i_p, x_NUM, ratio);

      //Set the error
      Double_t error_XLow = g_NUM->GetErrorXlow(i_p);
      Double_t error_Xhigh = g_NUM->GetErrorXhigh(i_p);
      g_ratio->SetPointError(i_p, error_XLow, error_Xhigh, ratio_error, ratio_error);

      // cout << endl;
    }

    return g_ratio;
  }

  Double_t Error_PropagatedAoverB(Double_t A, Double_t sigma_A, Double_t B, Double_t sigma_B)
  {
    Double_t ratio_A = (sigma_A) / A;
    Double_t ratio_B = (sigma_B) / B;

    Double_t errorSquare = ratio_A * ratio_A + ratio_B * ratio_B;

    return (A/B) * sqrt(errorSquare);
  }
};

}; // -- namespace PlotTool