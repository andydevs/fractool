cmake_minimum_required(VERSION 3.0)
project(FracTool)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)

find_package(OpenCV 4.5 REQUIRED)
find_package(Boost 1.76 REQUIRED COMPONENTS log)
include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory(apps)
add_subdirectory(src)