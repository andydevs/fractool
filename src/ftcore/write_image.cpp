#include <fractool/ftcore/write_image.hpp>

// External
#include <opencv2/opencv.hpp>
#include <boost/log/trivial.hpp>


/**
 * Write image to file
 *
 * @param size_x       horizontal image size
 * @param size_y       vertical image size
 * @param color_buffer color data buffer
 * @param filename     file name to save to
 */
void write_image(const unsigned size_x, const unsigned size_y, unsigned char* color_buffer, const char* filename) {
    BOOST_LOG_TRIVIAL(info) << "Writing Image...";
    
    cv::Mat image(size_y, size_x, CV_8UC3, color_buffer);
    cv::imwrite(filename, image);
}