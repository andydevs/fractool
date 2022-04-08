#ifndef __FRACTOOL_MAPCOLOR_H__
#define __FRACTOOL_MAPCOLOR_H__

#include <fractool/macros.hpp>

/**
 * Map parameter space to color space using colormap
 */
void EXPORT map_color(unsigned size_x, unsigned size_y, const colormap cmap, unsigned char* param_buffer, unsigned char* color_buffer);


#endif // __FRACTOOL_MAPCOLOR_H__