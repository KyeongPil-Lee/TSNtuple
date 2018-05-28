if [ $KP_ANALYZER_PATH ]; then
    echo "KP_ANALYZER_PATH is already defined: use a clean shell!"
    return 1
fi

# -- analyzer path (do not insert "/" in the end of the path)-- #
export KP_ANALYZER_PATH=$(pwd)
export KP_INCLUDE_PATH=$KP_ANALYZER_PATH/Include

# -- root setup -- #
export ROOT_INCLUDE_PATH=${KP_ANALYZER_PATH}:${ROOT_INCLUDE_PATH}

# -- python setup -- #
export PYTHONPATH=${KP_ANALYZER_PATH}:${PYTHONPATH}

# -- ntuple path -- #
export KP_DATA_PATH=""
if [[ "tamsa2.snu.ac.kr" == $HOSTNAME ]] || [[ "compute-" =~ "$HOSTNAME" ]]; # -- 147.47.242.67 -- # 
then
	echo "tamsa2 server setting"
	KP_DATA_PATH="/data5/Users/kplee/TriggerStudyNtuple"

	# -- cmssw setup -- #
	export SCRAM_ARCH=slc6_amd64_gcc530
	export VO_CMS_SW_DIR=/cvmfs/cms.cern.ch
	source $VO_CMS_SW_DIR/cmsset_default.sh

	cd /share_home/kplee/TagProbe/v20170815_1st_MuonPOG_92Xv2_TrkIter/CMSSW_9_2_4/src
	eval `scramv1 runtime -sh` # -- equivalent to cmsenv (cmsenv doesn't work. why?) -- #
	cd $KP_ANALYZER_PATH
	
elif [ "muon" == $HOSTNAME ]; 
then
	KP_DATA_PATH=/scratch/kplee/TSNtuple
fi

# -- temporary path for intermediate products
export KP_TEMP_PATH=""
if [ "/Users/KyeongPil_Lee" == $HOME ]; then # --personal laptop
	KP_TEMP_PATH=/Users/KyeongPil_Lee/Temp/TSNtuple
elif [ "cms.knu.ac.kr" == $HOSTNAME ]; then
	KP_TEMP_PATH=/d3/scratch/kplee/temp/TSNtuple
elif [ "muon" == $HOSTNAME ]; then
	KP_TEMP_PATH=/scratch/kplee/temp/TSNtuple
fi

echo "======= TSNtuple/Analzer ======="
echo "KP_ANALYZER_PATH:  " $KP_ANALYZER_PATH
echo "ROOT_INCLUDE_PATH: " $ROOT_INCLUDE_PATH
echo "PYTHONPATH:        " $PYTHONPATH
echo "KP_DATA_PATH:      " $KP_DATA_PATH
echo "KP_TEMP_PATH:      " $KP_TEMP_PATH
echo "==============================="