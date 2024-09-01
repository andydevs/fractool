# Root
cmake_minimum_required(VERSION 3.30.2)
project(FracTool VERSION 0.1.0)

# Configure Project
add_compile_definitions($<$<CONFIG:Debug>:DEBUG=1>)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_FIND_FRAMEWORK LAST)
if (NOT WIN32)
    link_directories(/usr/local/lib)
    add_compile_options(-pthread)
    add_link_options(-pthread)
endif()
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

# External packages
find_package(ZLIB REQUIRED)
find_package(Boost REQUIRED)
find_package(PNG REQUIRED)

# Source code
include_directories(include)

# FTCore
add_library(ftcore 
    src/ftcore/config.cpp
    src/ftcore/map_color.cpp
    src/ftcore/write_image.cpp)
target_link_libraries(ftcore
    PUBLIC
        PNG::PNG
        Boost::log
        Boost::log_setup
        Boost::thread
        Boost::filesystem)

# Fractool Engine Single-Process
add_library(ftensp
    src/ftensp/config.cpp
    src/ftensp/algorithm.cpp
    src/ftensp/zsquare-seed.cpp
    src/ftensp/zsquare-param.cpp)
target_link_libraries(ftensp PUBLIC ftcore)

# Fractool
add_executable(fractool 
    src/fractool/fractool.cpp 
    src/fractool/cli_parser.cpp)
target_link_libraries(fractool 
    PRIVATE 
        ftcore
        ftensp
        Boost::program_options)
        
# Install
install(TARGETS fractool RUNTIME)

# CPack
set(CPACK_PACKAGE_NAME "FracTool")
set(CPACK_PACKAGE_VENDOR "Andydevs")
set(CPACK_PACKAGE_DIRECTORY packages)
set(CPACK_PACKAGE_FILE_NAME ${PROJECT_NAME}-${CMAKE_BUILD_TYPE}-${PROJECT_VERSION}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR})
set(CPACK_PACKAGE_INSTALL_DIRECTORY "${PROJECT_NAME}")
set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE.txt")
set(CPACK_WIX_PATCH_FILE "${PROJECT_SOURCE_DIR}/WixPatch.xml")
if(WIN32)
    set(CPACK_GENERATOR "WIX;ZIP")
else()
    set(CPACK_GENERATOR "STGZ;TGZ")
endif()
include(CPack)