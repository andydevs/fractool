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
set_target_properties(ftcore
    PROPERTIES
    VERSION ${CMAKE_PROJECT_VERSION}
    SOVERSION ${CMAKE_PROJECT_VERSION})
install(
    TARGETS ftcore
    LIBRARY DESTINATION lib)
