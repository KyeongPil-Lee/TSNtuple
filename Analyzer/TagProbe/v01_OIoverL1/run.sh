#!bin/bash

root -b -q MakeHist_beforeUpdate.cxx++ >&MakeHist_beforeUpdate.log&
root -b -q MakeHist_afterUpdate.cxx++ >&MakeHist_afterUpdate.log&

echo "submitted"