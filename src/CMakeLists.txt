add_library(fractoolcore generate_mandelbrot.cpp map_color.cpp)
target_include_directories(fractoolcore PRIVATE ${OpenCV_INCLUDE_DIRS})