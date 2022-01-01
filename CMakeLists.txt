# Root
cmake_minimum_required(VERSION 3.0)
project(FracTool)

# Build config
set(CMAKE_CXX_STANDARD 14)
include_directories(include)
link_directories(/usr/local/lib)

# External Project
include(ExternalProject)
ExternalProject_Add(
    opencv4
    GIT_REPOSITORY "https://github.com/opencv/opencv.git"
    GIT_TAG "4.5.5"
)
ExternalProject_Add(
    boost_1_78_0
    URL "https://boostorg.jfrog.io/artifactory/main/release/1.78.0/source/boost_1_78_0.tar.gz"
    CONFIGURE_COMMAND "./bootstrap.sh"
    BUILD_COMMAND "./b2"
    INSTALL_COMMAND "./b2 install"
)

# Packages
set(Boost_USE_STATIC_LIBS ON)
find_package(OpenCV 4.5 REQUIRED)
find_package(Boost 1.73 REQUIRED COMPONENTS log program_options thread)

# Source directories
add_subdirectory(src out)