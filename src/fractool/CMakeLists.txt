# Debug mode settings
add_compile_definitions($<$<CONFIG:Debug>:DEBUG=1>)

# Target setting
add_executable(fractool 
    fractool.cpp 
    cli_parser.cpp)
target_link_libraries(fractool 
    PRIVATE 
        ftcore
        ftensp
        Boost::program_options)
install(TARGETS fractool RUNTIME)
