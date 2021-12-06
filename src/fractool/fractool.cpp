// Fractool macros
#include <fractool/macros.hpp>

// FTCore
#include <fractool/ftcore/config.hpp>
#include <fractool/ftcore/map_color.hpp>
#include <fractool/ftcore/write_image.hpp>
#include <fractool/ftcore/generate_mandelbrot.hpp>
#include <fractool/ftcore/generate_julia.hpp>

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

    // Config struct
    config conf;
    conf.parse_args(argc, argv);

    // Resources
    unsigned char* param_buffer = new unsigned char[conf.image_size_x * conf.image_size_y];
    unsigned char* color_buffer = new unsigned char[conf.image_size_x * conf.image_size_y * NUM_CHANS];

    // Run stages
    generate_julia(conf.image_size_x, conf.image_size_y, param_buffer);
    map_color(conf.image_size_x, conf.image_size_y, param_buffer, color_buffer);
    write_image(conf.image_size_x, conf.image_size_y, color_buffer, "fractal.png");

    // Delete resources
    delete[] param_buffer;
    delete[] color_buffer;

    // Exit
    return 0;
}