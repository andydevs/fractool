// Fractool
#include <fractool/ftcore/config.hpp>

// External
#include <boost/log/trivial.hpp>
#include <iostream>
#include <unistd.h>
#include <getopt.h>


/**
 * Initialize with default parameters
 */
config::config(): 
    image_size_x(600),
    image_size_y(400) {};

/**
 * Print help message
 */
void config::print_help() {
    BOOST_LOG_TRIVIAL(debug) << "Printing help message";
    std::cout << std::endl
        << "$ fractool [options]" << std::endl
        << std::endl << "Options:" << std::endl
        << "\t(-u | --image-size-x) <n>       Set horizontal image size" << std::endl
        << "\t(-v | --image-size-y) <n>       Set vertical image size" << std::endl
        << "\t(-h | --help)                   Print help message" << std::endl
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
    // Define options
    const char* const shortopts = "u:v:h";
    const option longopts[] {
        { "image-size-x", required_argument, nullptr, 'u' },
        { "image-size-y", required_argument, nullptr, 'v' },
        { "help",         no_argument,       nullptr, 'h' },
        { nullptr,        no_argument,       nullptr, 0 }
    };

    // Parse options
    int optint;
    while (( optint = getopt_long(argc, argv, shortopts, longopts, nullptr) ) != -1) {
        switch(optint) {
            case 'u':
                image_size_x = std::atoi(optarg);
                break;
            case 'v':
                image_size_y = std::atoi(optarg);
                break;
            case 'h':
                print_help();
                break;
            case '?':
                break;
            default:
                break;
        }
    }

    // Log final config
    log_config();
}