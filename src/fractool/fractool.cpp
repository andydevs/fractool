// Fractool macros
#include <fractool/macros.hpp>
#include <fractool/colormap.hpp>

// FTCore
#include <fractool/ftcore/config.hpp>
#include <fractool/ftcore/map_color.hpp>
#include <fractool/ftcore/write_image.hpp>
#include <fractool/ftensp/algorithm.hpp>
#include <fractool/ftensp/generate_mandelbrot.hpp>
#include <fractool/ftensp/generate_julia.hpp>

// Fractool
#include <fractool/fractool/cli_parser.hpp>

// External
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

/**
 * Initialize logging severity level
 */
void init_logging() {
    boost::log::core::get()->set_filter(
#ifdef DEBUG
        boost::log::trivial::severity >= boost::log::trivial::debug
#else
        boost::log::trivial::severity >= boost::log::trivial::info
#endif
    );
    BOOST_LOG_TRIVIAL(debug) << "Logging initialized";
};

/**
 * Main program entrypoint
 */
int main(int argc, char **argv) {
    // Initialize logging
    init_logging();

    // Generate config struct from cli
    config conf = config_from_cli(argc, argv);
    conf.log();

    // Resources
    unsigned char* param_buffer = new unsigned char[conf.image_size_x * conf.image_size_y];
    unsigned char* color_buffer = new unsigned char[conf.image_size_x * conf.image_size_y * NUM_CHANS];

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
    if (algo == nullptr) {
        // Exit status 1
        BOOST_LOG_TRIVIAL(error) << "No algorithm was set! Exiting..." << std::endl;
        return 1;
    }

    // Run stages
    algo->generate(conf, conf.image_size_x, conf.image_size_y, param_buffer);
    map_color(conf.image_size_x, conf.image_size_y, conf.cmap, param_buffer, color_buffer);
    write_image(conf.image_size_x, conf.image_size_y, color_buffer, "fractal.png");

    // Delete resources
    delete[] param_buffer;
    delete[] color_buffer;
    if (algo != nullptr) delete algo;

    // Exit
    return 0;
}