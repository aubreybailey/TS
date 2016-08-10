/* Copyright (C) 2010 Ion Torrent Systems, Inc. All Rights Reserved */
#ifndef REFINEFIT_H
#define REFINEFIT_H

#include "SignalProcessingMasterFitter.h"
#include "SingleFlowFit.h"
#include "ExpTailFitter.h"

// make this code look >just< like the GPU option
class RefineFit
{
  public:
    SignalProcessingMasterFitter &bkg; // reference to source class for now

    single_flow_optimizer my_single_fit;
    ExpTailBkgFitter my_exp_tail_fit;

    RefineFit (SignalProcessingMasterFitter &);
    void InitSingleFlowFit();
    void FitAmplitudePerFlow ( int flow_block_size, int flow_block_start );
    void FitAmplitudePerBeadPerFlow (int ibd, NucStep &cache_step, int flow_block_size, int flow_block_start);
    void SetupLocalEmphasis();

    void CrazyDumpToHDF5(BeadParams *p, int ibd, float * block_signal_predicted, float *block_signal_corrected, float *block_signal_original, float *block_signal_sbg,error_track &err_t, int flow_block_start );
    void CrazyDumpDebugBeads(BeadParams *p, int ibd, float * block_signal_predicted, float *block_signal_corrected, float *block_signal_original, float *block_signal_sbg,error_track &err_t, int flow_block_start );
    void CrazyDumpBestRegion(BeadParams *p, int ibd, float * block_signal_predicted, float *block_signal_corrected, float *block_signal_original, float *block_signal_sbg,error_track &err_t, int flow_block_start );
    void CrazyDumpXyFlow(BeadParams *p, int ibd, float * block_signal_predicted, float *block_signal_corrected, float *block_signal_original, float *block_signal_sbg,error_track &err_t, int flow_block_start );
    void CrazyDumpRegionSamples(BeadParams *p, int ibd, float * block_signal_predicted, float *block_signal_corrected, float *block_signal_original, float *block_signal_sbg,error_track &err_t, int flow_block_start );
      ~RefineFit();
};

#endif // REFINEFIT_H
