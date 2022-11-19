#ifndef __FRACTOOL_ALGORITHM_H__
#define __FRACTOOL_ALGORITHM_H__

// Includes
#include <fractool/ftcore/config.hpp>

// Abstract
class Algorithm {
public:
    // Default teardown for algorithm (do nothing)
    virtual ~Algorithm() {}

    // REQUIRED Generate function
    virtual void generate(config cfg, unsigned size_x, unsigned size_y, unsigned char* param_buffer) = 0;
};

/**
 * Build algorithm from config file
 */
Algorithm* create_algorithm(config cfg);


#endif // __FRACTOOL_ALGORITHM_H__