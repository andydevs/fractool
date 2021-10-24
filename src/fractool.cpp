// Fractool
#include <fractool/macros.hpp>
#include <fractool/map_color.hpp>
#include <fractool/generate_mandelbrot.hpp>

// External
#include <iostream>
#include <complex>
#include <algorithm>
#include <opencv2/opencv.hpp>


/**
 * Main program entrypoint
 */
int main(int argc, char **argv) {
    // Image parameters
    const unsigned size_x = 600;
    const unsigned size_y = 400;

    // Resources
    uchar* param_buffer = new uchar[size_x * size_y];
    uchar* color_buffer = new uchar[size_x * size_y * NUM_CHANS];

    // Run stages
    generate_mandelbrot(size_x, size_y, param_buffer);
    map_color(size_x, size_y, param_buffer, color_buffer);

    // Save image
    cv::Mat image(size_y, size_x, CV_8UC3, color_buffer);
    cv::imwrite("fractal.png", image);

    // Delete resources
    delete[] param_buffer;
    delete[] color_buffer;

    // Exit
    return 0;
}