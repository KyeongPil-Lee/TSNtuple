#include <TString.h>

#include <iostream>
#include <vector>

namespace Setting
{
  vector<TString> rootFilePaths_default = \
  {
    "/pnfs/knu.ac.kr/data/cms/store/user/kplee/SingleMuon/crab_TSNtuple_v20180515_Run316110_2p0e34_OptimizeOI_Default/180515_102355/0000/ntuple*.root"
  };

  vector<TString> rootFilePaths_0p05 = \
  {
    "/pnfs/knu.ac.kr/data/cms/store/user/kplee/SingleMuon/crab_TSNtuple_v20180515_Run316110_2p0e34_OptimizeOI_0p05ForAll/180515_102409/0000/ntuple*.root"
  };

  vector<TString> rootFilePaths_90 = \
  {
    "/pnfs/knu.ac.kr/data/cms/store/user/kplee/SingleMuon/crab_TSNtuple_v20180515_Run316110_2p0e34_OptimizeOI_90Percent/180515_102422/0000/ntuple*.root"
  };

  vector<TString> rootFilePaths_80 = \
  {
    "/pnfs/knu.ac.kr/data/cms/store/user/kplee/SingleMuon/crab_TSNtuple_v20180515_Run316110_2p0e34_OptimizeOI_80Percent/180515_102436/0000/ntuple*.root"
  };

  vector<TString> rootFilePaths_70 = \
  {
    "/pnfs/knu.ac.kr/data/cms/store/user/kplee/SingleMuon/crab_TSNtuple_v20180515_Run316110_2p0e34_OptimizeOI_70Percent/180515_102450/0000/ntuple*.root"
  };

  vector<TString> rootFilePaths_60 = \
  {
    "/pnfs/knu.ac.kr/data/cms/store/user/kplee/SingleMuon/crab_TSNtuple_v20180515_Run316110_2p0e34_OptimizeOI_60Percent/180515_102503/0000/ntuple*.root"
  };

  vector<TString> rootFilePaths_50 = \
  {
    "/pnfs/knu.ac.kr/data/cms/store/user/kplee/SingleMuon/crab_TSNtuple_v20180515_Run316110_2p0e34_OptimizeOI_50Percent/180515_102516/0000/ntuple*.root"
  };

  vector<TString> rootFilePaths_test = \
  {
    "/Users/KyeongPil_Lee/ServiceWorks/MuonHLT/v20180507_v01_UpdateTnPCode/TSNtuple/Analyzer/TagProbe/ExampleCodes/ntuple_9.root"
  };

  vector<TString> rootFilePaths_test2 = \
  {
    "/Users/KyeongPil_Lee/ServiceWorks/MuonHLT/v20180507_v01_UpdateTnPCode/TSNtuple/Analyzer/TagProbe/ExampleCodes/ntuple_9.root"
  };

  vector<TString> rootFilePathsForType( TString type )
  {
    vector<TString> rootFilePath_temp(0);

    if( type == "default" )
      return Setting::rootFilePaths_default;

    else if( type == "0p05" )
      return Setting::rootFilePaths_0p05;

    else if( type == "90" )
      return Setting::rootFilePaths_90;

    else if( type == "80" )
      return Setting::rootFilePaths_80;

    else if( type == "70" )
      return Setting::rootFilePaths_70;

    else if( type == "60" )
      return Setting::rootFilePaths_60;

    else if( type == "50" )
      return Setting::rootFilePaths_50;

    else if( type == "test" )
      return Setting::rootFilePaths_test;

    else if( type == "test2" )
      return Setting::rootFilePaths_test2;
    
    else
      std::cout << "No corresponding rootFilePath! ... return NULL vector" << std::endl;

    return rootFilePath_temp;
  }
};