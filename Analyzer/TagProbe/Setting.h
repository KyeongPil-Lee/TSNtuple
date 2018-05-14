#include <TString.h>

#include <iostream>
#include <vector>

namespace Setting
{
  vector<TString> rootFilePaths_default = \
  {
    "/u/user/kplee/SE_UserHome/SingleMuon/crab_TSNtuple_v20180513_3rdTry_OptimizeOI_Default/180513_164220/0000/ntuple*.root"
  };

  vector<TString> rootFilePaths_0p05 = \
  {
    "/u/user/kplee/SE_UserHome/SingleMuon/crab_TSNtuple_v20180513_3rdTry_OptimizeOI_0p05/180513_164232/0000/ntuple*.root"
  };

  TString rootFilePath_TEST = "/Users/KyeongPil_Lee/ServiceWorks/MuonHLT/v20180507_v01_UpdateTnPCode/TSNtuple/Analyzer/TagProbe/ExampleCodes/ntuple_9.root";

  vector<TString> rootFilePathsForType( TString type )
  {
    vector<TString> rootFilePath_temp(0);

    if( type == "default" )
      return Setting::rootFilePaths_default;

    else if( type == "0p05" )
      return Setting::rootFilePaths_0p05;
    
    else
      std::cout << "No corresponding rootFilePath! ... return NULL vector" << std::endl;

    return rootFilePath_temp;
  }
};