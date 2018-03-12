#include <DZFilterEff/CalcDZFilterEffTool.h>

void CalcDZFilterEff_Customized()
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

	TString basePath = "/u/user/kplee/SE_UserHome";

	setup.addNtuplePath(basePath+"/EphemeralHLTPhysics1/crab_TSntuple_v20180309_Customized_EphemeralHLTPhysics1_Run2017Fv1_Run305636_GoldenJSON/180309_123548/0000/*.root");
	setup.addNtuplePath(basePath+"/EphemeralHLTPhysics2/crab_TSntuple_v20180309_Customized_EphemeralHLTPhysics2_Run2017Fv1_Run305636_GoldenJSON/180309_123602/0000/*.root");
	setup.addNtuplePath(basePath+"/EphemeralHLTPhysics4/crab_TSntuple_v20180309_Customized_EphemeralHLTPhysics4_Run2017Fv1_Run305636_GoldenJSON/180309_123627/0000/*.root");
	setup.addNtuplePath(basePath+"/EphemeralHLTPhysics7/crab_TSntuple_v20180309_Customized_EphemeralHLTPhysics7_Run2017Fv1_Run305636_GoldenJSON/180309_123705/0000/*.root");

	DZFilterEffTool *tool = new DZFilterEffTool( setup );
	tool->Calc();
}
