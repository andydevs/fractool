#ifndef __FRACTOOL_WRITE_IMAGE_H__
#define __FRACTOOL_WRITE_IMAGE_H__

#include <fractool/macros.hpp>

/**
 * Write image to file
 *
 * @param size_x       horizontal image size
 * @param size_y       vertical image size
 * @param color_buffer color data buffer
 * @param filename     file name to save to
 */
void EXPORT write_image(const unsigned size_x, const unsigned size_y, unsigned char* color_buffer, const char* filename);

#endif // __FRACTOOL_WRITE_IMAGE_H__