#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
    // Fractal buffer
    const unsigned size_x = 600;
    const unsigned size_y = 400;
    uchar* buffer = new uchar[size_x*size_y];

    // Generate fractal
    for (unsigned j = 0; j < size_y; j++) {
        for (unsigned i = 0; i < size_x; i++) {
            buffer[j*size_x + i] = 255*(i + j)/(size_x + size_y);
        }
    }

    // Save image
    cv::Mat image(size_y, size_x, CV_8UC1, buffer);
    cv::imwrite("fractal.png", image);

    // Delete resources
    delete[] buffer;
    return 0;
}