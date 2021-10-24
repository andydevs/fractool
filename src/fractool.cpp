#include <iostream>
#include <opencv2/opencv.hpp>

#define RED_CHANNEL 0
#define GREEN_CHANNEL 1
#define BLUE_CHANNEL 2
#define NUM_CHANNELS 3

#define IMAGE(w, h, x, y, c) (y*w + x)*NUM_CHANNELS + c

int main(int argc, char **argv) {
    // Fractal buffer
    const unsigned size_x = 600;
    const unsigned size_y = 400;
    uchar* buffer = new uchar[size_x * size_y * NUM_CHANNELS];

    // Generate fractal
    uchar param;
    for (unsigned j = 0; j < size_y; ++j) {
        for (unsigned i = 0; i < size_x; ++i) {
            // Parameter
            param = 255 * (i + j) / (size_x + size_y);

            // Color
            buffer[IMAGE(size_x, size_y, i, j, RED_CHANNEL)] = 255 - param;
            buffer[IMAGE(size_x, size_y, i, j, BLUE_CHANNEL)] = param;
        }
    }

    // Save image
    cv::Mat image(size_y, size_x, CV_8UC3, buffer);
    cv::imwrite("fractal.png", image);

    // Delete resources
    delete[] buffer;
    return 0;
}