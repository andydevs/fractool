[Components](/fractool/components)
[Roadmap](/fractool/roadmap)

Build
-------------------------------------------------------------

_Requirements_

| Name   | Min Version | Used For                      |
|:-------|:------------|:------------------------------|
| CMake  | 3.0         | Building                      |
| OpenCV | 4.5         | Image and video file writing  |
| Boost  | 1.76        | Logging, parsing command line |

_How to Build (Linux/macOS)_

Open project in terminal. Run following commands

    mkdir build
    cd build
    cmake ..
    make

_How to Build (Windows)_

Open project in Visual Studio. Build project using GUI

Project Scope
-------------------------------------------------------------

FracTool is a personal application for generating fractal
images. It will mainly be used by individuals for the
purposes of creating such images for use in wallpapers,
banner images for social media, creative image assets, etc.

FracTool will _not_ implement a web solution, and will _not_
expose an API for use in other programs.