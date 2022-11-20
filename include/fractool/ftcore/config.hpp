#ifndef __FRACTOOL_CONFIG_H__
#define __FRACTOOL_CONFIG_H__

// Includes
#include <fractool/colormap.hpp>
#include <fractool/ftensp/config.hpp>
#include <string>
#include <map>

/**
 * Configuration object for tool
 */
struct config {
    // Config values
    unsigned image_size_x;
    unsigned image_size_y;
    ALGORITHM algorithm;
    std::map<std::string, std::string> parameters;
    colormap cmap;

    /**
     * Initialize with default parameters
     */
    config();

    /**
     * Print config parameters
     */
    void print();

    /**
     * Log config parameters
     */
    void log();
};

#endif // __FRACTOOL_CONFIG_H__