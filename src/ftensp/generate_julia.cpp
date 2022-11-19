// Fractool
#include <fractool/macros.hpp>
#include <fractool/ftensp/generate_julia.hpp>

// Internal
#include <algorithm>
#include <complex>
#include <string>
#include <iostream>
#include <sstream>

// External
#include <boost/log/trivial.hpp>

/**
 * Operator to read complex numbers
 */
std::istream& operator>> (std::istream &in, std::complex<float> &c) {
    float real; float imag;
    char cm;
    in >> real;
    in >> cm;
    if (cm != ',') { 
        BOOST_LOG_TRIVIAL(error) << "Invalid character processing pair: \"" << cm << "\" expecting \",\""; 
        return in;
    }
    in >> imag;
    c = std::complex<float>(real, imag);
    return in;
}

/**
 * Run julia set generation algorithm
 */
void ZSquareSeedAlgorithm::generate(config cfg, unsigned size_x, unsigned size_y, unsigned char* param_buffer)
{
    // Print message
    BOOST_LOG_TRIVIAL(info) << "Generating julia...";

    // Parameter
    std::complex<float> c(-0.4, 0.6);

    // Set c parameter if available
    auto it = cfg.parameters.find("c");
    if (it != cfg.parameters.end()) {
        std::istringstream css(it->second);
        css >> c;
    }
    BOOST_LOG_TRIVIAL(debug) << "c parameter: " << c;

    // Helper variables
    float gsc = 4.0;                            // Grid scale
    float x0 = (float)size_x/2;                 // Center x value
    float y0 = (float)size_y/2;                 // Center y value
    float scl = gsc / std::min(size_x, size_y); // Final scale factor
    BOOST_LOG_TRIVIAL(debug) << "Grid scale: " << gsc;
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