// Fractool
#include <fractool/macros.hpp>
#include <fractool/map_color.hpp>
#include <fractool/generate_mandelbrot.hpp>

// External
#include <unistd.h>
#include <getopt.h>
#include <opencv2/opencv.hpp>

struct config {
    unsigned image_size_x;
    unsigned image_size_y;

    config():
        image_size_x(600),
        image_size_y(400) {}

    void parse(int argc, char **argv) {
        // Define options
        const char* const shortopts = "u:v:h";
        const option longopts[] {
            { "image-size-x", required_argument, nullptr, 'u' },
            { "image-size-y", required_argument, nullptr, 'v' },
            { "help", no_argument, nullptr, 'h' },
            { nullptr, no_argument, nullptr, 0 }
        };

        int optint;
        while (( optint = getopt_long(argc, argv, shortopts, longopts, nullptr) ) != -1) {
            switch(optint) {
                case 'u':
                    image_size_x = std::atoi(optarg);
                    break;
                case 'v':
                    image_size_y = std::atoi(optarg);
                    break;
                case '?':
                    break;
                default:
                    break;
            }
        }
    }
};

/**
 * Main program entrypoint
 */
int main(int argc, char **argv) {
    // Config struct
    config conf;
    conf.parse(argc, argv);

    // Debug message
    std::cout << "conf.image_size_x" << " = " << conf.image_size_x << std::endl;
    std::cout << "conf.image_size_y" << " = " << conf.image_size_y << std::endl;

    // Resources
    unsigned char* param_buffer = new unsigned char[conf.image_size_x * conf.image_size_y];
    unsigned char* color_buffer = new unsigned char[conf.image_size_x * conf.image_size_y * NUM_CHANS];

    // Run stages
    generate_mandelbrot(conf.image_size_x, conf.image_size_y, param_buffer);
    map_color(conf.image_size_x, conf.image_size_y, param_buffer, color_buffer);

    // Save image
    cv::Mat image(conf.image_size_y, conf.image_size_x, CV_8UC3, color_buffer);
    cv::imwrite("fractal.png", image);

    // Delete resources
    delete[] param_buffer;
    delete[] color_buffer;

    // Exit
    return 0;
}