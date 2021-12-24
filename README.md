FracTool
============================================================================

Fractool is a tool for generating abstract images using various 2D fractal 
generation algorithms

Check out the [docs](https://andydevs.github.io/fractool)

Dependencies
----------------------------------------------------------------------------

| Name   | Min Version | Used For                            |
|:-------|:------------|:------------------------------------|
| Boost  | 1.77        | Logging, parsing command line       |
| OpenCV | 4.5         | Image and video file writing        |
| CMake  | 3.0         | Building                            |
| Python | 3.0         | Testing/Development support scripts |

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
