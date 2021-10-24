#ifndef __FRACTOOL_MACROS_H__
#define __FRACTOOL_MACROS_H__

// 2D Array index computation
#define ARRAY2D(w, x, y) y*w + x

// Image-related macros
#define RED_CHAN 0
#define GRN_CHAN 1
#define BLU_CHAN 2
#define NUM_CHANS 3
#define IMAGE(w, x, y, c) (ARRAY2D(w, x, y))*NUM_CHANS + c

#endif