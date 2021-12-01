// Fractool
#include <fractool/ftcore/config.hpp>

// External
#include <boost/log/trivial.hpp>
#include <iostream>
#include <unistd.h>
#include <getopt.h>


// Program options namespace
namespace po = boost::program_options;

/**
 * Initialize with default parameters
 */
config::config(): 
    image_size_x(600),
    image_size_y(400),
    options_desc("Configuration Options") {
        options_desc.add_options()
            ("help,h", "Produce help message")
            ("image-size-x,u", po::value<int>(), "Set horizontal image size")
            ("image-size-y,v", po::value<int>(), "Set vertical image size");
    };

/**
 * Print help message
 */
void config::print_help() {
    BOOST_LOG_TRIVIAL(debug) << "Printing help message";
    std::cout << std::endl
        << "$ fractool [options]" 
        << std::endl << std::endl
        << options_desc 
        << std::endl;
    BOOST_LOG_TRIVIAL(debug) << "exiting...";
    exit(1);
};

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
}

/**
 * Parse command line arguments
 *
 * @param argc number of command line arguments
 * @param argv command line arguments buffer
 */
void config::parse_args(int argc, char **argv) {
    BOOST_LOG_TRIVIAL(debug) << "Parsing config from command line options";
    
    // Run options parsing
    po::store(po::parse_command_line(argc, argv, options_desc), options_map);
    po::notify(options_map);

    // Pull options
    if (options_map.count("help")) { print_help(); }
    if (options_map.count("image-size-x")) { image_size_x = options_map["image-size-x"].as<int>(); }
    if (options_map.count("image-size-y")) { image_size_y = options_map["image-size-y"].as<int>(); }

    // Log final config
    log_config();
}