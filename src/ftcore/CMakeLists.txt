add_library(ftcore 
    config.cpp
    cli_parser.cpp
    map_color.cpp
    write_image.cpp
    generate_mandelbrot.cpp
    generate_julia.cpp)
target_link_libraries(ftcore 
    PRIVATE 
        opencv::core 
        opencv::imgcodecs 
        boost::log 
        boost::log_setup
        boost::program_options
        boost::thread
        boost::filesystem)
if(WIN32)
    target_compile_definitions(ftcore PRIVATE COMP_FTCORE)
endif()
install(
    TARGETS ftcore
    LIBRARY DESTINATION lib)
