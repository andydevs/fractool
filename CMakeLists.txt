# Root
cmake_minimum_required(VERSION 3.22)
project(FracTool VERSION 0.1.0)

# Configure Project
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_FIND_FRAMEWORK LAST)
include_directories(include)
link_directories(/usr/local/lib)
add_compile_options(-pthread)
add_link_options(-pthread)

# External packages
find_package(OpenCV 4.5 REQUIRED 
    PATHS extern/opencv/install 
    NO_DEFAULT_PATH)
find_package(Boost 1.78 REQUIRED 
    COMPONENTS log log_setup program_options 
    PATHS extern/boost/install 
    NO_DEFAULT_PATH)

# Subdirectories
add_subdirectory(src out)

# After install
if(APPLE)
    install(CODE "execute_process(COMMAND update_dyld_shared_cache)")
elseif(NOT WIN32)
    install(CODE "execute_process(COMMAND ldconfig)")
endif()