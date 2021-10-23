#include <iostream>
#include <Magick++.h>

int main(int argc, char **argv) {
    std::cout << "Making image!" << std::endl;
    Magick::InitializeMagick(*argv);
    Magick::Image image("100x100", "blue");
    image.write("blue_picture.png");
    return 0;
}