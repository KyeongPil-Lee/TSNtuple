#!bin/bash

root -b -q MakeHist_default.cxx++ >&MakeHist_default.log&

root -b -q MakeHist_0p05.cxx++ >&MakeHist_0p05.log&

echo "submitted"