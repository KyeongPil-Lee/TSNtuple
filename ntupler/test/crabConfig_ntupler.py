from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = ''
config.General.workArea = 'CRABDir'

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = ''
config.JobType.numCores = 4
# config.JobType.maxMemoryMB = 2500
# config.JobType.maxJobRuntimeMin = 2000

config.Data.inputDataset = ''
config.Data.useParent = True

config.Data.inputDBS = 'global'
config.Data.splitting = 'Automatic'
# config.Data.unitsPerJob = 5
config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Site.storageSite = 'T2_KR_KNU'

config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions18/13TeV/DCSOnly/json_DCSONLY.txt'

version = '_v20180910_'

# 'MultiCRAB' part
if __name__ == '__main__':
    
    from CRABAPI.RawCommand import crabCommand

    config.General.requestName = 'TSNtuple'+version+'SingleMuon_Run2018D_Run322356_DCSOnly_Menuv3p4'
    config.Data.inputDataset = '/SingleMuon/Run2018D-PromptReco-v2/AOD'
    config.Data.runRange = '322356-322356'
    config.JobType.psetName = 'HLTCfgMu_Menuv3p4.py'
    crabCommand('submit', config = config)

    config.General.requestName = 'TSNtuple'+version+'SingleMuon_Run2018D_Run322381_DCSOnly_Menuv3p5'
    config.Data.inputDataset = '/SingleMuon/Run2018D-PromptReco-v2/AOD'
    config.Data.runRange = '322381-322381'
    config.JobType.psetName = 'HLTCfgMu_Menuv3p5.py'
    crabCommand('submit', config = config)

    # config.General.requestName = ''
    # config.Data.inputDataset = ''
    # crabCommand('submit', config = config)