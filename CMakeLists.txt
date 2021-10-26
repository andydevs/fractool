cmake_minimum_required(VERSION 3.0)
project(FracTool)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)

find_package(OpenCV 4.5 REQUIRED)

add_executable(fractool 
    src/fractool.cpp
    src/generate_mandelbrot.cpp
    src/map_color.cpp)
target_include_directories(fractool PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(fractool ${OpenCV_LIBS})