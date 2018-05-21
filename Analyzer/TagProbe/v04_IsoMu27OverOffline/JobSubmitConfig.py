import os

from TagProbe.JobSubmitTool import JobSubmitTool

tool = JobSubmitTool()
tool.outputPath = os.getcwd()
tool.code = "MakeHist_IsoMu27OverOffline.cxx"
tool.doCompile = True

tool.scenario = "default"
tool.Submit()

tool.scenario = "90"
tool.Submit()

tool.scenario = "80"
tool.Submit()

tool.scenario = "70"
tool.Submit()

tool.scenario = "60"
tool.Submit()

tool.scenario = "50"
tool.Submit()

tool.scenario = "0p05"
tool.Submit()

