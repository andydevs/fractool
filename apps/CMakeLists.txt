add_executable(fractool fractool.cpp)
target_include_directories(fractool PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(fractool ${OpenCV_LIBS} fractoolcore)