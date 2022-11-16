add_library(ftcore 
    config.cpp
    map_color.cpp
    write_image.cpp
    generate_mandelbrot.cpp
    generate_julia.cpp)
target_link_libraries(ftcore 
    PUBLIC 
        png_static
        Boost::log 
        Boost::log_setup
        Boost::thread
        Boost::filesystem)
install(TARGETS ftcore LIBRARY)