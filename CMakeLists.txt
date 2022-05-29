# Root
cmake_minimum_required(VERSION 3.22)
project(FracTool VERSION 0.1.0)

# Configure Project
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_FIND_FRAMEWORK LAST)
include_directories(include)
if (NOT WIN32)
    link_directories(/usr/local/lib)
    add_compile_options(-pthread)
    add_link_options(-pthread)
endif()
set(Boost_USE_STATIC_LIBS ON)

# External packages
include(${PROJECT_SOURCE_DIR}/extern/libpng/libpng-install/lib/libpng/libpng16.cmake)
include_directories(${PROJECT_SOURCE_DIR}/extern/libpng/libpng-install/include)
find_package(Boost REQUIRED COMPONENTS log log_setup program_options PATHS "${PROJECT_SOURCE_DIR}/extern/boost/boost-install")

# Source code
add_subdirectory(src out)

# After install
if(APPLE)
    install(CODE "execute_process(COMMAND update_dyld_shared_cache)")
elseif(NOT WIN32)
    install(CODE "execute_process(COMMAND ldconfig)")
endif()
