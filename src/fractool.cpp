#include <iostream>
#include <Magick++.h>

const char* size = "600x400";

int main(int argc, char **argv) {
    Magick::InitializeMagick(*argv);

    // Create image
    Magick::Image image("100x100", "gray");

    // Set image pixels
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            image.pixelColor(i, j, Magick::ColorGray((float)(i + j)/(100 + 100)));
        }
    }

    // Write image
    image.syncPixels();
    image.write("fractal.png");
    return 0;
}