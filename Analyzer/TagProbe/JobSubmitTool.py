import os, sys, time
import subprocess
from shutil import copy2

TIME = time.strftime('%Y%m%d_%H%M%S', time.localtime(time.time())) # -- ex> 20180517_152233

class JobSubmitTool:
    def __init__(self):
        self.code = ""
        self.scenario = ""
        self.outputPath = ""
        self.doCompile = True

        # -- internal variable
        self.tempPath = os.environ['KP_TEMP_PATH'] # -- temporary path for intermediate products

    def Submit(self):
        self._CheckVar()
        self._PrintVar()

        dirPath = self._CreateTempWorkSpace()
        logFilePath = self._WriteScriptAndSubmit(dirPath)

        print "Job is submitted: "
        print "log file: %s" % logFilePath
        print "\n"

    def _CreateTempWorkSpace(self):
        dirName = '%s_%s_%s' % (TIME, self.code.split(".")[0], self.scenario)
        dirPath = '%s/%s' % (self.tempPath, dirName)
        if os.path.exists(dirPath):
            print "Directory with same name already exists ... path: ", dirPath
            sys.exit()

        os.mkdir( dirPath )

        # -- copy codes to temp. directory
        copy2( self.code, dirPath )
        for fileName in os.listdir('.'):
            if fileName.endswith('.h'): # -- also copy any header file
                copy2( fileName, dirPath )

        # # -- copy also .h files
        # cmd_cp = "cp %s *.h %s" % (self.code, dirPath)
        # os.system(cmd_cp)

        return dirPath

    def _WriteScriptAndSubmit(self, path):
        fileName = "script_run.sh"
        filePath = '%s/%s' % (path, fileName)

        rootCMD = "root -l -b -q '%s(\"%s\")'" % (self.code, self.scenario)
        if self.doCompile: rootCMD = rootCMD.replace(".cxx", ".cxx++")
        cpCMD = "cp *.root %s" % (self.outputPath)
        f = open(filePath, 'w')

        f.write(
"""
#!bin/bash

{_rootCMD}

{_cpCMD}

echo "*.root files are moved to {_outputPath}"

""".format(_rootCMD=rootCMD, _cpCMD=cpCMD, _outputPath=self.outputPath)
        )

        f.close()

        # -- run the script in temp drectory
        cwd = os.getcwd()
        os.chdir(path) # -- move to temp directory

        runCMD = 'source %s' % fileName
        logFileName = fileName.replace(".sh", ".log")
        f_log = open(logFileName, "w")
        subProc = subprocess.Popen(runCMD, stdout=f_log, stderr=f_log, shell=True, executable='/bin/bash') # -- bash shell should be specified (in case of KNU)

        os.chdir(cwd) # -- back to original directory

        logFilePath = "%s/%s" % (path, logFileName)
        return logFilePath

    def _CheckVar(self):
        if self.code == "" or self.scenario == "" or self.outputPath == "":
            print "Mandatory information is missing"
            _printVar()
            sys.exit()

    def _PrintVar(self):
        print "code =       %s" % self.code
        print "scenario =   %s" % self.scenario
        print "outputPath = %s" % self.outputPath