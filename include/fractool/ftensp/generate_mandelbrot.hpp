#ifndef __FRACTOOL_GENERATEMANDELBROT_H__
#define __FRACTOOL_GENERATEMANDELBROT_H__

// Include
#include <fractool/ftcore/config.hpp>

/**
 * Run mandelbrot set generation algorithm
 */
void generate_mandelbrot(config cfg, unsigned size_x, unsigned size_y, unsigned char* param_buffer);


#endif // __FRACTOOL_GENERATEMANDELBROT_H__