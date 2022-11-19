#ifndef __FRACTOOL_GENERATEJULIA_H__
#define __FRACTOOL_GENERATEJULIA_H__

// Include
#include <fractool/ftensp/algorithm.hpp>
#include <fractool/ftcore/config.hpp>

// ZSquare Seed (Julia set) implementation of algorithm
class ZSquareSeedAlgorithm : public Algorithm {
public:
    void generate(config cfg, unsigned size_x, unsigned size_y, unsigned char* param_buffer) override;
};

#endif // __FRACTOOL_GENERATEJULIA_H__