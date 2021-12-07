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
     * Print config parameters
     */
    void print_config();

    /**
     * Log config parameters
     */
    void log_config();
};

#endif // __FRACTOOL_CONFIG_H__