# TriggerStudyNtuple
   * Reference: https://github.com/sarafiorendi/MuonHLTNtuples



## OI performance check after OI update

OI update was introduced in the menu v3.5 (Run >= 322381)



### data

```
/SingleMuon/Run2018D-v1/RAW
/SingleMuon/Run2018D-PromptReco-v2/AOD
```



* Menu v3.4: [Run 322356](https://cmswbm.cern.ch/cmsdb/servlet/RunSummary?RUN=322356) (~236 /pb)
  * In just one before fill
  * /cdaq/physics/Run2018/2e34/v3.4.2/HLT/V1
* Menu v3.5: [Run 322381](https://cmswbm.cern.ch/cmsdb/servlet/RunSummary?RUN=322381&SUBMIT=Submit) (~181 /pb)
  * /cdaq/physics/Run2018/2e34/v3.5/HLT/V2

### Recipe

```
cmsrel CMSSW_10_1_10
cd CMSSW_10_1_10/src
cmsenv

git clone git@github.com:KyeongPil-Lee/TSNtuple.git -b OIPerfAfterUpdate
scram b -j 4 >&scram.log&
tail -f scram.log

cd TSNtuple/ntupler/test

# -- menu v3.4
hltGetConfiguration orcoff:/cdaq/physics/Run2018/2e34/v3.4.2/HLT/V1 \
--globaltag 101X_dataRun2_HLT_v7 \
--path HLTriggerFirstPath,\
HLT_IsoMu24_v*,HLT_Mu50_v*,HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v*,\
HLTriggerFinalPath,HLTAnalyzerEndpath \
--input file:/eos/cms/store/data/Run2018D/SingleMuon/RAW/v1/000/322/381/00000/FEFB6051-93B2-E811-BFEF-FA163E467136.root \
--process MYHLT --full --offline \
--prescale none --max-events 500 --output none > HLTCfgMu_Menuv3p4.py

# -- (add two lines at the end of config.)
# from TSNtuple.ntupler.customizerForNtupler import *
# customizerForNtuplerHLT(process, "MYHLT")

# -- menu v3.5
hltGetConfiguration orcoff:/cdaq/physics/Run2018/2e34/v3.5/HLT/V2 \
--globaltag 101X_dataRun2_HLT_v7 \
--path HLTriggerFirstPath,\
HLT_IsoMu24_v*,HLT_Mu50_v*,HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v*,\
HLTriggerFinalPath,HLTAnalyzerEndpath \
--input file:/eos/cms/store/data/Run2018D/SingleMuon/RAW/v1/000/322/381/00000/FEFB6051-93B2-E811-BFEF-FA163E467136.root \
--process MYHLT --full --offline \
--prescale none --max-events 500 --output none > HLTCfgMu_Menuv3p5.py

# -- (add two lines at the end of config.)
# from TSNtuple.ntupler.customizerForNtupler import *
# customizerForNtuplerHLT(process, "MYHLT")

# -- submit the CRAB jobs
python crabConfig_ntupler.py






```

