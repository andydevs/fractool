# Debug mode settings
add_compile_definitions($<$<CONFIG:Debug>:DEBUG=1>)

# Target setting
add_executable(fractool fractool.cpp)
target_include_directories(fractool PRIVATE
    ${Boost_INCLUDE_DIRS})
target_link_libraries(fractool PRIVATE
    ftcore
    ${Boost_LIBRARIES})