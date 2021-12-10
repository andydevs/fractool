# Root
cmake_minimum_required(VERSION 3.0)
project(FracTool)

# Build config
set(CMAKE_CXX_STANDARD 14)
include_directories(include)

# Packages
find_package(OpenCV 4.5 REQUIRED)
find_package(Boost 1.73 COMPONENTS log program_options REQUIRED)

# Source directories
add_subdirectory(src out)