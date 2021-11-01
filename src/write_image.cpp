#include <fractool/write_image.hpp>
#include <opencv2/opencv.hpp>


/**
 * Write image to file
 *
 * @param size_x       horizontal image size
 * @param size_y       vertical image size
 * @param color_buffer color data buffer
 * @param filename     file name to save to
 */
void write_image(const unsigned size_x, const unsigned size_y, unsigned char* color_buffer, const char* filename) {
    cv::Mat image(size_y, size_x, CV_8UC3, color_buffer);
    cv::imwrite(filename, image);
}