add_library(fractoolcore 
    config.cpp
    generate_mandelbrot.cpp 
    map_color.cpp
    write_image.cpp)
target_include_directories(fractoolcore PRIVATE 
    ${OpenCV_INCLUDE_DIRS})