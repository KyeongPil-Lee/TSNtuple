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
# config.Data.useParent = True

config.Data.inputDBS = 'global'

# config.Data.splitting = 'Automatic'
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = 5

config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Site.storageSite = 'T2_KR_KNU'

config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions18/13TeV/DCSOnly/json_DCSONLY.txt'

version = '_v20180928_2nd_'

# 'MultiCRAB' part
if __name__ == '__main__':
    
    from CRABAPI.RawCommand import crabCommand

    # -- for efficiency: useParent = True
    config.General.requestName = 'TSNtuple'+version+'SingleMuon_Run2018D_Run322625_DCSOnly_Menuv3p5'
    config.Data.inputDataset = '/SingleMuon/Run2018D-PromptReco-v2/AOD'
    config.Data.runRange = '322625-322625'
    config.JobType.psetName = 'HLTCfgMu_Menu3p5.py'
    config.Data.useParent = True
    crabCommand('submit', config = config)

    # -- for rate: no need to use parent, different run range (run need to be available in HLTPhysics) & JSON
    config.General.requestName = 'TSNtuple'+version+'EphemeralHLTPhysics1_Run2018D_Run321755_Golden_Menuv3p5'
    config.Data.inputDataset = '/EphemeralHLTPhysics1/Run2018D-v1/RAW'
    config.Data.runRange = '321755-321755'
    config.JobType.psetName = 'HLTCfgMu_Menu3p5.py'
    config.Data.useParent = False
    config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions18/13TeV/PromptReco/Cert_314472-322381_13TeV_PromptReco_Collisions18_JSON.txt'
    crabCommand('submit', config = config)

    config.General.requestName = 'TSNtuple'+version+'EphemeralHLTPhysics2_Run2018D_Run321755_Golden_Menuv3p5'
    config.Data.inputDataset = '/EphemeralHLTPhysics2/Run2018D-v1/RAW'
    config.Data.runRange = '321755-321755'
    config.JobType.psetName = 'HLTCfgMu_Menu3p5.py'
    config.Data.useParent = False
    config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions18/13TeV/PromptReco/Cert_314472-322381_13TeV_PromptReco_Collisions18_JSON.txt'
    crabCommand('submit', config = config)

    config.General.requestName = 'TSNtuple'+version+'EphemeralHLTPhysics3_Run2018D_Run321755_Golden_Menuv3p5'
    config.Data.inputDataset = '/EphemeralHLTPhysics3/Run2018D-v1/RAW'
    config.Data.runRange = '321755-321755'
    config.JobType.psetName = 'HLTCfgMu_Menu3p5.py'
    config.Data.useParent = False
    config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions18/13TeV/PromptReco/Cert_314472-322381_13TeV_PromptReco_Collisions18_JSON.txt'
    crabCommand('submit', config = config)

    config.General.requestName = 'TSNtuple'+version+'EphemeralHLTPhysics4_Run2018D_Run321755_Golden_Menuv3p5'
    config.Data.inputDataset = '/EphemeralHLTPhysics4/Run2018D-v1/RAW'
    config.Data.runRange = '321755-321755'
    config.JobType.psetName = 'HLTCfgMu_Menu3p5.py'
    config.Data.useParent = False
    config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions18/13TeV/PromptReco/Cert_314472-322381_13TeV_PromptReco_Collisions18_JSON.txt'
    crabCommand('submit', config = config)

    config.General.requestName = 'TSNtuple'+version+'EphemeralHLTPhysics5_Run2018D_Run321755_Golden_Menuv3p5'
    config.Data.inputDataset = '/EphemeralHLTPhysics5/Run2018D-v1/RAW'
    config.Data.runRange = '321755-321755'
    config.JobType.psetName = 'HLTCfgMu_Menu3p5.py'
    config.Data.useParent = False
    config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions18/13TeV/PromptReco/Cert_314472-322381_13TeV_PromptReco_Collisions18_JSON.txt'
    crabCommand('submit', config = config)

    config.General.requestName = 'TSNtuple'+version+'EphemeralHLTPhysics6_Run2018D_Run321755_Golden_Menuv3p5'
    config.Data.inputDataset = '/EphemeralHLTPhysics6/Run2018D-v1/RAW'
    config.Data.runRange = '321755-321755'
    config.JobType.psetName = 'HLTCfgMu_Menu3p5.py'
    config.Data.useParent = False
    config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions18/13TeV/PromptReco/Cert_314472-322381_13TeV_PromptReco_Collisions18_JSON.txt'
    crabCommand('submit', config = config)

    config.General.requestName = 'TSNtuple'+version+'EphemeralHLTPhysics7_Run2018D_Run321755_Golden_Menuv3p5'
    config.Data.inputDataset = '/EphemeralHLTPhysics7/Run2018D-v1/RAW'
    config.Data.runRange = '321755-321755'
    config.JobType.psetName = 'HLTCfgMu_Menu3p5.py'
    config.Data.useParent = False
    config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions18/13TeV/PromptReco/Cert_314472-322381_13TeV_PromptReco_Collisions18_JSON.txt'
    crabCommand('submit', config = config)

    config.General.requestName = 'TSNtuple'+version+'EphemeralHLTPhysics8_Run2018D_Run321755_Golden_Menuv3p5'
    config.Data.inputDataset = '/EphemeralHLTPhysics8/Run2018D-v1/RAW'
    config.Data.runRange = '321755-321755'
    config.JobType.psetName = 'HLTCfgMu_Menu3p5.py'
    config.Data.useParent = False
    config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions18/13TeV/PromptReco/Cert_314472-322381_13TeV_PromptReco_Collisions18_JSON.txt'
    crabCommand('submit', config = config)


