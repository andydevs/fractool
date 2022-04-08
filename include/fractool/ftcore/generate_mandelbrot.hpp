#ifndef __FRACTOOL_GENERATEMANDELBROT_H__
#define __FRACTOOL_GENERATEMANDELBROT_H__

#include <fractool/macros.hpp>

/**
 * Run mandelbrot set generation algorithm
 */
void EXPORT generate_mandelbrot(unsigned size_x, unsigned size_y, unsigned char* param_buffer);


#endif // __FRACTOOL_GENERATEMANDELBROT_H__