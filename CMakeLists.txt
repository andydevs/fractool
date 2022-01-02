# Root
cmake_minimum_required(VERSION 3.0)
project(FracTool)

# Configure Project
set(CMAKE_CXX_STANDARD 14)
include_directories(include)
link_directories(/usr/local/lib)
add_compile_options(-pthread)
add_link_options(-pthread)

# External Project
include(ExternalProject)

# Configure opencv
ExternalProject_Add(
    opencv
    GIT_REPOSITORY "https://github.com/opencv/opencv.git"
    GIT_TAG "4.5.5"
    CMAKE_ARGS
        -DOPENCV_FORCE_3RDPARTY_BUILD=ON
        -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
)
ExternalProject_Get_Property(opencv install_dir)
include_directories(${install_dir}/include/opencv4)
add_library(opencv::core SHARED IMPORTED)
set_property(
    TARGET opencv::core 
    PROPERTY IMPORTED_LOCATION 
        ${install_dir}/lib/libopencv_core${CMAKE_SHARED_LIBRARY_SUFFIX})
add_dependencies(opencv::core opencv)
add_library(opencv::imgcodecs SHARED IMPORTED)
set_property(
    TARGET opencv::imgcodecs 
    PROPERTY IMPORTED_LOCATION 
        ${install_dir}/lib/libopencv_imgcodecs${CMAKE_SHARED_LIBRARY_SUFFIX})
add_dependencies(opencv::core opencv)

# Configure boost
ExternalProject_Add(
    boost
    URL "https://boostorg.jfrog.io/artifactory/main/release/1.78.0/source/boost_1_78_0.tar.gz"
    CONFIGURE_COMMAND <SOURCE_DIR>/bootstrap.sh
    BUILD_COMMAND <SOURCE_DIR>/b2
    INSTALL_COMMAND <SOURCE_DIR>/b2 install --prefix=<INSTALL_DIR>
    BUILD_IN_SOURCE 1
)
ExternalProject_Get_Property(boost install_dir)
include_directories(${install_dir}/include)
add_library(boost::log_setup SHARED IMPORTED)
set_property(
    TARGET boost::log_setup 
    PROPERTY IMPORTED_LOCATION 
        ${install_dir}/lib/libboost_log_setup${CMAKE_SHARED_LIBRARY_SUFFIX})
add_dependencies(boost::log_setup boost)
add_library(boost::log SHARED IMPORTED)
set_property(
    TARGET boost::log 
    PROPERTY IMPORTED_LOCATION 
        ${install_dir}/lib/libboost_log${CMAKE_SHARED_LIBRARY_SUFFIX})
add_dependencies(boost::log boost)
add_library(boost::program_options SHARED IMPORTED)
set_property(
    TARGET boost::program_options 
    PROPERTY IMPORTED_LOCATION 
        ${install_dir}/lib/libboost_program_options${CMAKE_SHARED_LIBRARY_SUFFIX})
add_dependencies(boost::program_options boost)
add_definitions(-DBOOST_LOG_DYN_LINK)

# Source directory
add_subdirectory(src out)