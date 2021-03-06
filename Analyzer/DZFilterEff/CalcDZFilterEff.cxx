#include <DZFilterEff/CalcDZFilterEffTool.h>

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

	TString basePath = "/u/user/kplee/SE_UserHome";

	setup.addNtuplePath(basePath+"/EphemeralHLTPhysics1/crab_TSntuple_v20180309_Default_EphemeralHLTPhysics1_Run2017Fv1_Run305636_GoldenJSON/180309_123314/0000/*.root");
	setup.addNtuplePath(basePath+"/EphemeralHLTPhysics2/crab_TSntuple_v20180309_Default_EphemeralHLTPhysics2_Run2017Fv1_Run305636_GoldenJSON/180309_123325/0000/*.root");
	setup.addNtuplePath(basePath+"/EphemeralHLTPhysics3/crab_TSntuple_v20180309_Default_EphemeralHLTPhysics3_Run2017Fv1_Run305636_GoldenJSON/180309_123336/0000/*.root");
	setup.addNtuplePath(basePath+"/EphemeralHLTPhysics5/crab_TSntuple_v20180309_Default_EphemeralHLTPhysics5_Run2017Fv1_Run305636_GoldenJSON/180309_123359/0000/*.root");
	setup.addNtuplePath(basePath+"/EphemeralHLTPhysics7/crab_TSntuple_v20180309_Default_EphemeralHLTPhysics7_Run2017Fv1_Run305636_GoldenJSON/180309_123421/0000/*.root");
	setup.addNtuplePath(basePath+"/EphemeralHLTPhysics8/crab_TSntuple_v20180309_Default_EphemeralHLTPhysics8_Run2017Fv1_Run305636_GoldenJSON/180309_123432/0000/*.root");

	DZFilterEffTool *tool = new DZFilterEffTool( setup );
	tool->Calc();
}
