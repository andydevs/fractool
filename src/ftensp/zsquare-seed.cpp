// Fractool
#include <fractool/macros.hpp>
#include <fractool/ftensp/zsquare-seed.hpp>

// Internal
#include <algorithm>
#include <complex>
#include <string>
#include <iostream>
#include <sstream>

// External
#include <boost/log/trivial.hpp>

/**
 * Constructor
 */
ZSquareSeedAlgorithm::ZSquareSeedAlgorithm(config cfg): Algorithm(cfg) {
    // Set parameter c if available
    c = cfg.parameter("c", std::complex<float>(-0.4, 0.6));
    BOOST_LOG_TRIVIAL(debug) << "c parameter: " << c;
}

/**
 * Run julia set generation algorithm
 */
void ZSquareSeedAlgorithm::generate(unsigned size_x, unsigned size_y, unsigned char* param_buffer)
{
    // Print message
    BOOST_LOG_TRIVIAL(info) << "Generating julia...";

    // Helper variables
    float x0 = (float)size_x/2;                        // Center x value
    float y0 = (float)size_y/2;                        // Center y value
    float scl = grid_scale / std::min(size_x, size_y); // Final scale factor
    BOOST_LOG_TRIVIAL(debug) << "Grid scale: " << grid_scale;
    BOOST_LOG_TRIVIAL(debug) << "Origin Point (x0, y0): (" << x0 << "," << y0 << ")";
    BOOST_LOG_TRIVIAL(debug) << "Final Scale: " << scl;

    // Run iteration algorithm
    std::complex<float> z;
    unsigned char n;
    for (unsigned j = 0; j < size_y; ++j) {
        for (unsigned i = 0; i < size_x; ++i) {
            // Initialize z
            z = std::complex<float>(i - x0, y0 - j) * scl;

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