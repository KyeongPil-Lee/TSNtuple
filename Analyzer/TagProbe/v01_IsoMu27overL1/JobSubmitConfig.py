import os

from TagProbe.JobSubmitTool import JobSubmitTool

tool = JobSubmitTool()
tool.outputPath = os.getcwd()
tool.code = "MakeHist_IsoMu27overL1.cxx"
tool.doCompile = False
tool.scenario = "test"
tool.Submit()

tool.scenario = "test2"
tool.Submit()

