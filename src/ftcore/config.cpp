// Fractool
#include <fractool/ftcore/config.hpp>

// External
#include <boost/log/trivial.hpp>
#include <iostream>
#include <sstream>
#include <complex>

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
    for (std::pair<std::string, std::string> p : parameters) {
        BOOST_LOG_TRIVIAL(debug) << "config.parameters[\"" << p.first << "\"] = " << p.second;    
    }
};

// Explicit instantiation of template parameter get
template std::complex<float> config::parameter(std::string name, std::complex<float> defVal);

/**
 * Get parameter or default
 */
template <typename T>
T config::parameter(std::string name, T defVal) {
    // Get parameter c if available
    T val;
    auto it = parameters.find(name);
    if (it != parameters.end()) {
        std::istringstream valss(it->second);
        valss >> val;
        return val;
    } else {
        return defVal;
    }
}
