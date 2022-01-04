# Debug mode settings
add_compile_definitions($<$<CONFIG:Debug>:DEBUG=1>)

# Target setting
add_executable(fractool fractool.cpp)
target_link_libraries(fractool 
    PRIVATE 
        ftcore 
        boost::log
        boost::log_setup)
install(
    TARGETS fractool
    RUNTIME DESTINATION bin
)