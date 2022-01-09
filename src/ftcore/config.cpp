// Fractool
#include <fractool/ftcore/config.hpp>

// External
#include <boost/log/trivial.hpp>
#include <iostream>

/**
 * Initialize with default parameters
 */
config::config(): 
    image_size_x(600),
    image_size_y(400),
    algorithm(ALGORITHM::MANDELBROT),
    cmap(COLORMAP_FLOWER) {};

/**
 * Print config parameters
 */
void config::print() {
    std::cout 
        << "config.image_size_x" << " = " << image_size_x << std::endl
        << "config.image_size_y" << " = " << image_size_y << std::endl;
};

/**
 * Log config parameters
 */
void config::log() {
    BOOST_LOG_TRIVIAL(debug) << "config.image_size_x = " << image_size_x;
    BOOST_LOG_TRIVIAL(debug) << "config.image_size_y = " << image_size_y;
};