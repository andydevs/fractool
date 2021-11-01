// Fractool
#include <fractool/macros.hpp>
#include <fractool/config.hpp>
#include <fractool/generate_mandelbrot.hpp>
#include <fractool/map_color.hpp>
#include <fractool/write_image.hpp>

// External
#include <boost/log/trivial.hpp>

/**
 * Main program entrypoint
 */
int main(int argc, char **argv) {
    // Config struct
    config conf;
    conf.parse_args(argc, argv);

    // Resources
    unsigned char* param_buffer = new unsigned char[conf.image_size_x * conf.image_size_y];
    unsigned char* color_buffer = new unsigned char[conf.image_size_x * conf.image_size_y * NUM_CHANS];

    // Run stages
    generate_mandelbrot(conf.image_size_x, conf.image_size_y, param_buffer);
    map_color(conf.image_size_x, conf.image_size_y, param_buffer, color_buffer);
    write_image(conf.image_size_x, conf.image_size_y, color_buffer, "fractal.png");

    // Delete resources
    delete[] param_buffer;
    delete[] color_buffer;

    // Exit
    return 0;
}