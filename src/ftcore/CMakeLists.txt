add_library(ftcore 
    config.cpp
    cli_parser.cpp
    map_color.cpp
    write_image.cpp
    generate_mandelbrot.cpp
    generate_julia.cpp)
target_link_libraries(ftcore 
    PUBLIC 
        png_static
        Boost::log 
        Boost::log_setup
        Boost::program_options
        Boost::thread
        Boost::filesystem)
install(TARGETS ftcore LIBRARY)