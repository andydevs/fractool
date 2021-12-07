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
    image_size_y(400) {};

/**
 * Print config parameters
 */
void config::print_config() {
    std::cout 
        << "config.image_size_x" << " = " << image_size_x << std::endl
        << "config.image_size_y" << " = " << image_size_y << std::endl;
};

/**
 * Log config parameters
 */
void config::log_config() {
    BOOST_LOG_TRIVIAL(debug) << "config.image_size_x = " << image_size_x;
    BOOST_LOG_TRIVIAL(debug) << "config.image_size_y = " << image_size_y;
};