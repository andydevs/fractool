#ifndef __FRACTOOL_CONFIG_H__
#define __FRACTOOL_CONFIG_H__

// Program options
#include <boost/program_options.hpp>

/**
 * Configuration object for tool
 */
struct config {
    // Config parameters
    unsigned image_size_x;
    unsigned image_size_y;

    // Boost program options
    boost::program_options::options_description options_desc;
    boost::program_options::variables_map options_map;

    /**
     * Initialize with default parameters
     */
    config();

    /**
     * Print help message
     */
    void print_help();

    /**
     * Print config parameters
     */
    void print_config();

    /**
     * Log config parameters
     */
    void log_config();

    /**
     * Parse command line arguments
     *
     * @param argc number of command line arguments
     * @param argv command line arguments buffer
     */
    void parse_args(int argc, char **argv);
};

#endif // __FRACTOOL_CONFIG_H__