FracTool
============================================================================

Fractool is a tool for generating abstract images using various 2D fractal 
generation algorithms

Check out the [docs](https://andydevs.github.io/fractool)

Dependencies
----------------------------------------------------------------------------

| Name   | Min Version | Used For                         |
|:-------|:------------|:---------------------------------|
| CMake  | 3.0         | Building                         |
| OpenCV | 4.5         | Image and video file writing     |
| Boost  | 1.73        | Logging, parsing command line    |
| Python | 3.0         | Integration test running for cli |

Build
----------------------------------------------------------------------------

### Linux/macOS

Open project folder in terminal. Run following commands

    cmake -S . -B build
    cmake --build build

### Windows

Open project in Visual Studio.

Click on "Build" tab

Click on "Build All"