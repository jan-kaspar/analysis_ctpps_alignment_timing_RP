all: distributions

distributions: distributions.cc config.h stat.h
	g++ `root-config --libs` -lGenVector `root-config --cflags` \
		-O3 --std=c++1z -Wall -Wextra -Wno-attributes\
		-I$(CMSSW_RELEASE_BASE)/src \
		-L$(CMSSW_RELEASE_BASE)/lib/slc7_amd64_gcc700 \
		-lDataFormatsFWLite -lDataFormatsCommon -lDataFormatsCTPPSDetId -lFWCoreParameterSet -lFWCorePythonParameterSet -lFWCoreParameterSetReader \
			distributions.cc -o distributions
