#include <TString.h>

#include <iostream>
#include <vector>

namespace Setting
{
  vector<TString> rootFilePaths_menu2p0 = \
  {
    "/home/kplee/data1/TSNtuple/v20180626_NonIsoMuEff_SingleMuon_Run2018Av2_Run316361to2_Menu2p0/*.root"
  };

  vector<TString> rootFilePaths_menu2p1 = \
  {
    "/home/kplee/data1/TSNtuple/v20180626_NonIsoMuEff_SingleMuon_Run2018Av2_Run316361to2_Menu2p1/*.root"
  };

  vector<TString> rootFilePathsForType( TString type )
  {
    vector<TString> rootFilePath_temp(0);

    if( type == "menu2p0" )
      return Setting::rootFilePaths_menu2p0;

    else if( type == "menu2p1" )
      return Setting::rootFilePaths_menu2p1;

    else
      cout << "no corresponding setup for " << type << endl;

    return rootFilePath_temp;
  }
}