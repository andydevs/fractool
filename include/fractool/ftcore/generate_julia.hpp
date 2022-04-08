#ifndef __FRACTOOL_GENERATEJULIA_H__
#define __FRACTOOL_GENERATEJULIA_H__

#include <fractool/macros.hpp>

/**
 * Run julia set generation algorithm
 */
void EXPORT generate_julia(unsigned size_x, unsigned size_y, unsigned char* param_buffer);

#endif // __FRACTOOL_GENERATEJULIA_H__