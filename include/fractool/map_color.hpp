#ifndef __FRACTOOL_MAPCOLOR_H__
#define __FRACTOOL_MAPCOLOR_H__


// External
#include <opencv2/opencv.hpp>

/**
 * Map parameter space to color space using colormap
 */
void map_color(unsigned size_x, unsigned size_y, uchar* param_buffer, uchar* color_buffer);


#endif // __FRACTOOL_MAPCOLOR_H__