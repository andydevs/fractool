#ifndef __FRACTOOL_GENERATEJULIA_H__
#define __FRACTOOL_GENERATEJULIA_H__

// Include
#include <fractool/ftcore/config.hpp>

/**
 * Run julia set generation algorithm
 */
void generate_julia(config cfg, unsigned size_x, unsigned size_y, unsigned char* param_buffer);

#endif // __FRACTOOL_GENERATEJULIA_H__