cmake_minimum_required(VERSION 3.0)
project(FracTool)

find_package(ImageMagick 7 REQUIRED COMPONENTS Magick++ MagickCore)

add_executable(fractool src/fractool.cpp)
target_include_directories(fractool PRIVATE ${ImageMagick_INCLUDE_DIRS})
target_link_libraries(fractool ${ImageMagick_LIBRARIES})