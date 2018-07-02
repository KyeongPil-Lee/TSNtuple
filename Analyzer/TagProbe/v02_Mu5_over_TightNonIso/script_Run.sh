#!bin/bash

root -b -q 'MakeHist.cxx++("menu2p0")' >&MakeHist_menu2p0.log&

sleep 30

root -b -q 'MakeHist.cxx++("menu2p1")' >&MakeHist_menu2p1.log&

echo "submission is finished"
