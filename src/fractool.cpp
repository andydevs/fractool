#include <iostream>
#include <Magick++.h>

const int sizeX = 600;
const int sizeY = 400;
const char* size = "600x400";

const int MAX_ITER = 256;

int main(int argc, char **argv) {
    Magick::InitializeMagick(*argv);

    // Create image
    Magick::Image image(size, "gray");

    // Set image pixels
    bool escape;
    for (int i = 0; i < sizeX; ++i) {
        for (int j = 0; j < sizeY; ++j) {
            escape = i + j > (sizeX + sizeY)/2;
            image.pixelColor(i, j, Magick::ColorMono(escape));
        }
    }

    // Write image
    image.syncPixels();
    image.write("fractal.png");
    return 0;
}