# Root
cmake_minimum_required(VERSION 3.0)
project(FracTool)

# Build config
set(CMAKE_CXX_STANDARD 14)
include_directories(include)
link_directories(/usr/local/lib)

# Packages
set(Boost_USE_STATIC_LIBS ON)
find_package(OpenCV 4.5 REQUIRED)
find_package(Boost 1.73 REQUIRED COMPONENTS log program_options thread)

# Source directories
add_subdirectory(src out)