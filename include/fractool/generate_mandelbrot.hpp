#ifndef __FRACTOOL_GENERATEMANDELBROT_H__
#define __FRACTOOL_GENERATEMANDELBROT_H__


// External
#include <opencv2/opencv.hpp>

/**
 * Run mandelbrot set generation algorithm
 */
void generate_mandelbrot(unsigned size_x, unsigned size_y, uchar* param_buffer);


#endif // __FRACTOOL_GENERATEMANDELBROT_H__