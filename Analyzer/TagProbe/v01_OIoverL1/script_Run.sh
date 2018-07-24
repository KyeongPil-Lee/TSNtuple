#!bin/bash

root -b -q 'MakeHist.cxx++("standard")' >&MakeHist_standard.log&

sleep 30

root -b -q 'MakeHist.cxx++("optiForEff")' >&MakeHist_optiForEff.log&

sleep 30

root -b -q 'MakeHist.cxx++("optiForTim")' >&MakeHist_optiForTim.log&

echo "submission is finished"