cmake_minimum_required(VERSION 3.0)
project(FracTool)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)

find_package(OpenCV REQUIRED)

add_executable(fractool src/fractool.cpp)
target_include_directories(fractool PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(fractool ${OpenCV_LIBS})