add_library(ftcore 
    config.cpp
    generate_mandelbrot.cpp 
    map_color.cpp
    write_image.cpp)
target_include_directories(ftcore PRIVATE 
    ${OpenCV_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS})
target_link_libraries(ftcore PRIVATE
    ${OpenCV_LIBS}
    ${Boost_LIBRARIES})