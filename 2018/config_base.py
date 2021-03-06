import FWCore.ParameterSet.Config as cms

config = cms.PSet(
    fill = cms.uint32(0),
    xangle = cms.uint32(0),
    dataset = cms.string(""),

    alignment_files = cms.vstring("/afs/cern.ch/work/j/jkaspar/work/software/ctpps/development/TO_SAVE/ctpps_initial_proton_reconstruction_CMSSW_10_2_0/CMSSW_10_2_0/src/RecoCTPPS/ProtonReconstruction/data/alignment/2018/fit_alignments_2019_07_11.out"),

    alignment_corrections = cms.PSet(
      rp_L_2_F = cms.PSet(
        de_x = cms.double(-42.05)
      ),
      rp_L_1_F = cms.PSet(
        de_x = cms.double(-3.70)
      ),
      rp_R_1_F = cms.PSet(
        de_x = cms.double(-2.75)
      ),
      rp_R_2_F = cms.PSet(
        de_x = cms.double(-42.05)
      )
    ),

    aligned = cms.bool(False),

    n_si = cms.double(4.),

    sector_45 = cms.PSet(
	  cut_h_apply = cms.bool(True),
	  cut_h_a = cms.double(-1),
	  cut_h_c = cms.double(-0.08),
	  cut_h_si = cms.double(0.2),

	  cut_v_apply = cms.bool(True),
	  cut_v_a = cms.double(-1.07),
	  cut_v_c = cms.double(0.),
	  cut_v_si = cms.double(0.20)
    ),

    sector_56 = cms.PSet(
	  cut_h_apply = cms.bool(True),
	  cut_h_a = cms.double(-1),
	  cut_h_c = cms.double(+0.08),
	  cut_h_si = cms.double(0.2),

	  cut_v_apply = cms.bool(True),
	  cut_v_a = cms.double(-1.07),
	  cut_v_c = cms.double(0.),
	  cut_v_si = cms.double(0.25)
    ),

)
