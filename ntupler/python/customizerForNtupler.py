# -- custoimzer for ntupler that can be added to the HLT configuration for re-running HLT
# -- add two lines in the HLT config.:
# from TSNtuple.ntupler.customizerForNtupler import *
# customizerForNtuplerHLT(process, "MYHLT")

import FWCore.ParameterSet.Config as cms

def customizerForNtuplerHLT(process, newProcessName = "MYHLT"):
    if hasattr(process, "DQMOutput"):
        del process.DQMOutput

        flag_ReRun = True

        from TSNtuple.ntupler.ntupler_cfi import ntuplerBase

        process.ntupler = ntuplerBase.clone()
        process.ntupler.OfflineMuon = cms.untracked.InputTag("muons")
        process.ntupler.L3Muon = cms.untracked.InputTag("hltIterL3MuonCandidates")
        process.ntupler.L2Muon = cms.untracked.InputTag("hltL2MuonCandidates")
        process.ntupler.TriggerResults = cms.untracked.InputTag("TriggerResults", "", "HLT")
        process.ntupler.TriggerEvent = cms.untracked.InputTag("hltTriggerSummaryAOD", "", "HLT")
        process.ntupler.OfflineLumiScaler = cms.untracked.InputTag("scalersRawToDigi")

        if flag_ReRun: # -- after HLT re-run -- #
          process.ntupler.L1Muon           = cms.untracked.InputTag("hltGtStage2Digis", "Muon", newProcessName)
          process.ntupler.MyTriggerResults = cms.untracked.InputTag("TriggerResults", "", newProcessName) # -- result after rerun HLT -- #
          process.ntupler.MyTriggerEvent   = cms.untracked.InputTag("hltTriggerSummaryAOD", "", newProcessName) # -- result after rerun HLT -- #
          process.ntupler.LumiScaler       = cms.untracked.InputTag("hltScalersRawToDigi", "", newProcessName)
          process.ntupler.IterL3MuonNoID   = cms.untracked.InputTag("hltIterL3MuonsNoID", "", newProcessName)
        else: # -- without HLT re-run -- #
          process.ntupler.L1Muon = cms.untracked.InputTag("gmtStage2Digis", "Muon", "RECO")
          process.ntupler.MyTriggerResults = cms.untracked.InputTag("TriggerResults")
          process.ntupler.MyTriggerEvent = cms.untracked.InputTag("hltTriggerSummaryAOD")
          process.ntupler.LumiScaler = cms.untracked.InputTag("scalersRawToDigi") # -- same with OfflineLumiScaler

        process.TFileService = cms.Service("TFileService",
          fileName = cms.string("ntuple.root"),
          closeFileFast = cms.untracked.bool(False),
          )

        process.mypath = cms.EndPath(process.ntupler)


