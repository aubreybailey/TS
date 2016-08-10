/* Copyright (C) 2015 Ion Torrent Systems, Inc. All Rights Reserved. */

//////////////////////////////////////////////////////////////////////////////
// Derived from QSimScan project, released under MIT license
// (https://github.com/abadona/qsimscan)
//////////////////////////////////////////////////////////////////////////////

#ifndef __align_batch_h__
#define __align_batch_h__

#include <tracer.h>


struct BATCH
{
    unsigned xpos;
    unsigned ypos;
    unsigned len;
    BATCH () : xpos ((unsigned) 0), ypos ((unsigned) 0), len ((unsigned) 0) {}
    BATCH (unsigned x, unsigned y, unsigned l) : xpos (x), ypos (y), len (l) {}
};

int align_score (const BATCH* bm, unsigned bno, const char* xseq, const char* yseq, int gip, int gep, int mat, int mis);

inline std::ostream& operator << (std::ostream& o, const BATCH& b)
{
    o << "x_" << b.xpos << ":y_" << b.ypos << ":l_" << b.len;
    return o;
}

inline void batch_dbgout (std::ostream& o, const BATCH* b, int bno, const char delim = ';', unsigned margin = 0)
{
    while (bno)
    {
        if (margin)
            o << std::setw (margin) << "" << std::setw (0);
        o << *b;
        b ++;
        bno --;
        if (bno) o << delim;
    }
}

inline void batch_dbgout (Logger& logger, const BATCH* b, int bno, const char delim = ';', unsigned margin = 0)
{
    if (logger.enabled ())
        batch_dbgout (logger.o_, b, bno, delim, margin);
}

#endif // __align_batch_h__
