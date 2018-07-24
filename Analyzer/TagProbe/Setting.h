#include <TString.h>

#include <iostream>
#include <vector>

namespace Setting
{
  vector<TString> rootFilePaths_standard = \
  {
    "/pnfs/knu.ac.kr/data/cms/store/user/jskim/SingleMuon/crab_Ntupler_CMSSW_10_2_0_pre4_customiseIDStandard_Run2018B-PromptReco-v2/180719_104714/0000/*.root"
  };

  vector<TString> rootFilePaths_optiForEff = \
  {
    "/pnfs/knu.ac.kr/data/cms/store/user/jskim/SingleMuon/crab_Ntupler_CMSSW_10_2_0_pre4_customizerForOImaxeff_Run2018B-PromptReco-v2/180723_161059/0000/*.root"
  };

  vector<TString> rootFilePaths_optiForTim = \
  {
    "/pnfs/knu.ac.kr/data/cms/store/user/jskim/SingleMuon/crab_Ntupler_CMSSW_10_2_0_pre4_customizerForOItiming_Run2018B-PromptReco-v2/180723_161331/0000/*.root"
  };

  vector<TString> rootFilePathsForType( TString type )
  {
    vector<TString> rootFilePath_temp(0);

    if( type == "standard" )
      return Setting::rootFilePaths_standard;

    else if( type == "optiForEff" )
      return Setting::rootFilePaths_optiForEff;

    else if( type == "optiForTim" )
      return Setting::rootFilePaths_optiForTim;

    else
      cout << "no corresponding setup for " << type << endl;

    return rootFilePath_temp;
  }
}