#include <TagProbe/v04_Mu8Leg/TnPTool_Mu8.h>

class DrawingTool
{
public:
	TnPEffTool *effTool_2017;
	TnPEffTool *effTool_2018;

	DrawingTool()
	{
		TString fileName_2017 = "./ROOTFile_Default.root";
		this->effTool_2017 = new TnPEffTool( fileName_2017 );

		TString fileName_2018 = "./ROOTFile_Customized.root";
		this->effTool_2018 = new TnPEffTool( fileName_2018 );
	}

	void ComparisonPlot_All()
	{
		this->ComparisonPlot( "Pt" );
		this->ComparisonPlot( "Eta" );
		// this->ComparisonPlot( "Phi" );
		// this->ComparisonPlot( "Vtx" );
	}

private:
	void ComparisonPlot( TString varName )
	{
		SampleInfo *sampleInfo_2017 = new SampleInfo( 1, "2017", "IterL3 v2017" );
		sampleInfo_2017->SetColor( kBlack );

		SampleInfo *sampleInfo_2018 = new SampleInfo( 1, "2018", "IterL3 v2018" );
		sampleInfo_2018->SetColor( kRed );

		TString titleX = this->GetTitleX( varName );
		HistInfo *histInfo = new HistInfo( "", titleX, "Efficiency");
		if( varName == "Pt" ) histInfo->SetYRange(0, 1.3);
		if( varName == "Eta" ) histInfo->SetYRange(0.7, 1.1);

		TH1D* h_2017 = this->effTool_2017->CalcTnPEff_CutAndCount( varName );
		TH1Ext *hext_2017 = new TH1Ext( sampleInfo_2017, histInfo, h_2017 );
		hext_2017->CalcRatio_DEN( hext_2017->h ); // -- dummy

		TH1D* h_2018 = this->effTool_2018->CalcTnPEff_CutAndCount( varName );
		TH1Ext *hext_2018 = new TH1Ext( sampleInfo_2018, histInfo, h_2018 );
		hext_2018->CalcRatio_DEN( hext_2017->h );

		TCanvas *c; TPad *TopPad; TPad *BottomPad;
		TString canvasName = "c_2017_vs_2018_Mu8Leg_"+varName;
		SetCanvas_Ratio( c, canvasName, TopPad, BottomPad, 0, 0 );
		c->cd();
		TopPad->cd();

		hext_2017->DrawAndSet( "EPSAME" );
		hext_2018->DrawAndSet( "EPSAME" );

		TLegend *legend;
		SetLegend( legend, 0.50, 0.83, 0.97, 0.95 );
		hext_2017->AddToLegend( legend );
		hext_2018->AddToLegend( legend );
		legend->Draw();

		TLatex latex;
		Latex_Preliminary_NoDataInfo( latex );
		latex.DrawLatexNDC( 0.75, 0.96, "#scale[0.8]{#font[42]{2017, 13 TeV}}" );
		latex.DrawLatexNDC( 0.16, 0.91, "#scale[0.6]{#font[42]{Mu8 leg}}" );

		c->cd();
		BottomPad->cd();

		hext_2018->DrawRatioAndSet( "EPSAME", "2018/2017", 0.7, 1.3 );

		TF1 *f_line;
		DrawLine( f_line );

		c->SaveAs(".pdf");
	}

	TString GetTitleX( TString  varName )
	{
		TString titleX = "";
		if( varName == "Pt" ) titleX = "P_{T} (#mu) [GeV]";
		if( varName == "Eta" ) titleX = "#eta (#mu)";
		if( varName == "Phi" ) titleX = "#phi (#mu)";
		if( varName == "Vtx" ) titleX = "# vertex";

		return titleX;
	}
};

void CalcAndDraw()
{
	DrawingTool* tool = new DrawingTool();
	tool->ComparisonPlot_All();	
}