* initialise environment
```
    source environment
```

* prepare working directories (for all fills, datasets, ...)
```
    cd build_work_dirs/
    ./build_for_physics_runs
```

* compile executables
```
    cd ..
    make
```

* make plots and extract alignment parameters (separately for all fills, datasets, ...)
```
    ./run distributions data/version4/*/*/
    # option -submit can be used to submit to HTCondor
```

* collect results from different fills, datasets etc., combine results from different pads on the same physical sensor, make fill-dependent fits, export corrections
```
    cd export/
    make
	./fit_timing_alignments
	# the output fit_timing_alignments.xml has the standard format used in CMSSW
```
