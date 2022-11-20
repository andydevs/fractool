#ifndef __FRACTOOL_GENERATEMANDELBROT_H__
#define __FRACTOOL_GENERATEMANDELBROT_H__

// Include
#include <fractool/ftensp/algorithm.hpp>
#include <fractool/ftcore/config.hpp>

// ZSquare Param (Mandelbrot set) implementation of algorithm
class ZSquareParamAlgorithm : public Algorithm {
public:
    // Constants (final grid scale)
    static constexpr const float grid_scale = 4.0f;

    // Setup
    ZSquareParamAlgorithm(config cfg);

    // Run algorithm
    void generate(unsigned size_x, unsigned size_y, unsigned char* param_buffer) override;
};

#endif // __FRACTOOL_GENERATEMANDELBROT_H__