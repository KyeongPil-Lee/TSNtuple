#!bin/bash

root -b -q 'MakeHist_IsoMu27overL1.cxx("default")' >&MakeHist_IsoMu27overL1_default.log&

root -b -q 'MakeHist_IsoMu27overL1.cxx("90")' >&MakeHist_IsoMu27overL1_90.log&

root -b -q 'MakeHist_IsoMu27overL1.cxx("80")' >&MakeHist_IsoMu27overL1_80.log&

root -b -q 'MakeHist_IsoMu27overL1.cxx("70")' >&MakeHist_IsoMu27overL1_70.log&

root -b -q 'MakeHist_IsoMu27overL1.cxx("60")' >&MakeHist_IsoMu27overL1_60.log&

root -b -q 'MakeHist_IsoMu27overL1.cxx("50")' >&MakeHist_IsoMu27overL1_50.log&

root -b -q 'MakeHist_IsoMu27overL1.cxx("0p05")' >&MakeHist_IsoMu27overL1_0p05.log&

echo "submitted"