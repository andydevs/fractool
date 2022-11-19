// Fractool
#include <fractool/macros.hpp>
#include <fractool/ftensp/zsquare-seed.hpp>
#include <fractool/ftensp/zsquare-param.hpp>

// External
#include <boost/log/trivial.hpp>


/**
 * Build algorithm from config file
 */
Algorithm* create_algorithm(config conf)
{
    // Get algorithm
    Algorithm *algo = nullptr;
    switch(conf.algorithm) {
        case ALGORITHM::MANDELBROT:
            algo = new ZSquareParamAlgorithm();
            break;
        case ALGORITHM::JULIA:
            algo = new ZSquareSeedAlgorithm();
            break;
        default:
            break;
    }
    return algo;
}