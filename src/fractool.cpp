// Fractool
#include <fractool/macros.hpp>
#include <fractool/map_color.hpp>

// External
#include <iostream>
#include <complex>
#include <algorithm>
#include <opencv2/opencv.hpp>


/**
 * Run mandelbrot set generation algorithm
 */
void generate_mandelbrot(unsigned size_x, unsigned size_y, uchar* param_buffer)
{
    // Helper variables
    float gsc = 4.0;                            // Grid scale
    float x0 = (float)size_x/2;                 // Center x value
    float y0 = (float)size_y/2;                 // Center y value
    float scl = gsc / std::min(size_x, size_y); // Final scale factor

    // Run iteration algorithm
    std::complex<float> z, c;
    uchar n;
    for (unsigned j = 0; j < size_y; ++j) {
        for (unsigned i = 0; i < size_x; ++i) {
            // Initialize z and c
            z = std::complex<float>(0, 0);
            c = std::complex<float>(i - x0, y0 - j) * scl;

            // Iteration
            n = 0;
            while (n < 255 && std::abs(z) < 2) {
                z *= z;
                z += c;
                n += 1;
            }
            
            // Set parameter
            param_buffer[ARRAY2D(size_x, i, j)] = n;
        }
    }
}

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