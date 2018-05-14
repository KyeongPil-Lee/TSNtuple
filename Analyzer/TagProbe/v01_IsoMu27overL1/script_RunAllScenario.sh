#!bin/bash

root -b -q MakeHist_IsoMu27overL1_default.cxx++ >&MakeHist_IsoMu27overL1_default.log&

root -b -q MakeHist_IsoMu27overL1_0p05.cxx++ >&MakeHist_IsoMu27overL1_0p05.log&

echo "submitted"