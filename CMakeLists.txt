cmake_minimum_required(VERSION 3.0)
project(FracTool)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)

find_package(OpenCV 4.5 REQUIRED)

add_subdirectory(apps)
add_subdirectory(src)