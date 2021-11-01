// Fractool
#include <fractool/generate_mandelbrot.hpp>
#include <fractool/macros.hpp>

// Internal
#include <algorithm>
#include <complex>

// External
#include <boost/log/trivial.hpp>

/**
 * Run mandelbrot set generation algorithm
 */
void generate_mandelbrot(unsigned size_x, unsigned size_y, unsigned char* param_buffer)
{
    BOOST_LOG_TRIVIAL(info) << "Generating...";

    // Helper variables
    float gsc = 4.0;                            // Grid scale
    float x0 = (float)size_x/2;                 // Center x value
    float y0 = (float)size_y/2;                 // Center y value
    float scl = gsc / std::min(size_x, size_y); // Final scale factor

    // Run iteration algorithm
    std::complex<float> z, c;
    unsigned char n;
    for (unsigned j = 0; j < size_y; ++j) {
        for (unsigned i = 0; i < size_x; ++i) {
            // Initialize z and c
            z = std::complex<float>(0, 0);
            c = std::complex<float>(i - x0, y0 - j) * scl;

            // Iteration
            n = 0;
            while (n < 255 && std::abs(z) < 2) {
                z = z*z + c;
                n += 1;
            }
            
            // Set parameter
            param_buffer[ARRAY2D(size_x, i, j)] = n;
        }
    }
}