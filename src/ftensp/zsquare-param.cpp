// Fractool
#include <fractool/macros.hpp>
#include <fractool/ftensp/zsquare-param.hpp>

// Internal
#include <algorithm>
#include <complex>

// External
#include <boost/log/trivial.hpp>

/**
 * Constructor
 */
ZSquareParamAlgorithm::ZSquareParamAlgorithm(config cfg): Algorithm(cfg) {}

/**
 * Run mandelbrot set generation algorithm
 */
void ZSquareParamAlgorithm::generate(unsigned size_x, unsigned size_y, unsigned char* param_buffer)
{
    // Print message
    BOOST_LOG_TRIVIAL(info) << "Generating mandelbrot...";

    // Helper variables
    float x0 = (float)size_x/2;                        // Center x value
    float y0 = (float)size_y/2;                        // Center y value
    float scl = grid_scale / std::min(size_x, size_y); // Final scale factor
    BOOST_LOG_TRIVIAL(debug) << "Grid scale: " << grid_scale;
    BOOST_LOG_TRIVIAL(debug) << "Origin Point (x0, y0): (" << x0 << "," << y0 << ")";
    BOOST_LOG_TRIVIAL(debug) << "Final Scale: " << scl;

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

            // Log output
            BOOST_LOG_TRIVIAL(trace) 
                << "Pixel (" << i << "," << j << "): "
                << "c = " << c << " n = " << (int)n;
            
            // Set parameter
            param_buffer[ARRAY2D(size_x, i, j)] = n;
        }
    }
}