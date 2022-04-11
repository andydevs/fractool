#ifndef __FRACTOOL_MACROS_H__
#define __FRACTOOL_MACROS_H__

// Exports
#if _WIN32
#ifdef COMP_FTCORE
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif
#else
#define EXPORT
#endif

// 2D Array index computation
#define ARRAY2D(w, x, y) y*w + x

// Image/color macros
#define BLU_CHAN 0
#define GRN_CHAN 1
#define RED_CHAN 2
#define NUM_CHANS 3
#define COLORMAP_SIZE 256
#define IMAGE(w, x, y, c) (ARRAY2D(w, x, y))*NUM_CHANS + c
struct EXPORT colormap {
	unsigned char data[COLORMAP_SIZE*NUM_CHANS];
};

#endif // __FRACTOOL_MACROS_H__