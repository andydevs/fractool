#ifndef __FRACTOOL_ALGORITHM_CONFIG_H__
#define __FRACTOOL_ALGORITHM_CONFIG_H__

// Includes
#include <iostream>
#include <map>

// Algorithm enum
enum ALGORITHM {
    _INVALID,

    // Algorithms
    MANDELBROT,
    JULIA
};

// Algorithm lookup table
const std::map<std::string, ALGORITHM> algo_lookup = {
    { "mandelbrot", ALGORITHM::MANDELBROT },
    { "julia",      ALGORITHM::JULIA }
};

/**
 * Operator to interpret algorithm from input string
 */
std::istream& operator>> (std::istream &in, ALGORITHM &algorithm);

/**
 * Print algorithm list
 */
void print_algos();

#endif // __FRACTOOL_ALGORITHM_CONFIG_H__