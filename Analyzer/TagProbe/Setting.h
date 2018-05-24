#include <TString.h>

#include <iostream>
#include <vector>

namespace Setting
{
  vector<TString> rootFilePaths_default = \
  {
    "/home/kplee/data1/TSNtuple/v20180523_Run305636_BadPixel_L1Emul_OptimizeOI/default/*.root"
  };

  vector<TString> rootFilePaths_0p05 = \
  {
    "/home/kplee/data1/TSNtuple/v20180523_Run305636_BadPixel_L1Emul_OptimizeOI/0p05ForAll/*.root"
  };

  vector<TString> rootFilePaths_90 = \
  {
    "/home/kplee/data1/TSNtuple/v20180523_Run305636_BadPixel_L1Emul_OptimizeOI/90Percent/*.root"
  };

  vector<TString> rootFilePaths_80 = \
  {
    "/home/kplee/data1/TSNtuple/v20180523_Run305636_BadPixel_L1Emul_OptimizeOI/80Percent/*.root"
  };

  vector<TString> rootFilePaths_70 = \
  {
    "/home/kplee/data1/TSNtuple/v20180523_Run305636_BadPixel_L1Emul_OptimizeOI/70Percent/*.root"
  };

  vector<TString> rootFilePaths_60 = \
  {
    "/home/kplee/data1/TSNtuple/v20180523_Run305636_BadPixel_L1Emul_OptimizeOI/60Percent/*.root"
  };

  vector<TString> rootFilePaths_50 = \
  {
    "/home/kplee/data1/TSNtuple/v20180523_Run305636_BadPixel_L1Emul_OptimizeOI/50Percent/*.root"
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