#ifndef __FRACTOOL_CONFIG_H__
#define __FRACTOOL_CONFIG_H__

/**
 * Configuration object for tool
 */
struct config {
    // Config parameters
    unsigned image_size_x;
    unsigned image_size_y;

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