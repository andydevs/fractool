cmake_minimum_required(VERSION 3.0)
project(FracTool)
set(CMAKE_CXX_STANDARD 14)

find_package(ImageMagick 7 REQUIRED COMPONENTS Magick++ MagickCore)

# Remove that weird warning thing
# Taken from: https://stackoverflow.com/questions/38546196/how-can-i-determine-magickcore-quantum-depth-and-magickcore-hdri-enable-during-c
if(ImageMagick_FOUND)
    # Find Magick++-config utility (Cache)
    file(GLOB_RECURSE MAGICK_CONFIG FOLLOW_SYMLINKS ${ImageMagick_EXECUTABLE_DIR}/Magick++-config)
    set(MAGICK_CONFIG ${MAGICK_CONFIG} CACHE STRING "Path to Magick++-config utility")
    message(DEBUG "MagickConfig: ${MAGICK_CONFIG}")

    # Get magick config variables
    execute_process(COMMAND "${MAGICK_CONFIG}" "--cxxflags" OUTPUT_VARIABLE MAGICK_CXX_FLAGS)
    execute_process(COMMAND "${MAGICK_CONFIG}" "--libs" OUTPUT_VARIABLE MAGICK_LD_FLAGS)
    
    # Add these to cache
    set(MAGICK_CXX_FLAGS "${MAGICK_CXX_FLAGS}" CACHE STRING "ImageMagick configuration specific compilation flags." )
    set(MAGICK_LD_FLAGS  "${MAGICK_LD_FLAGS}" CACHE STRING "ImageMagick configuration specific linking flags.")

    # Split into list:
    string(REGEX MATCHALL "([^\ ]+)" MAGICK_CXX_FLAGS "${MAGICK_CXX_FLAGS}")
    string(REGEX MATCHALL "([^\ ]+)" MAGICK_LD_FLAGS "${MAGICK_LD_FLAGS}")

    # Remove trailing whitespace (CMAKE warns about this)
    string(STRIP "${MAGICK_CXX_FLAGS}" MAGICK_CXX_FLAGS)
    string(STRIP "${MAGICK_LD_FLAGS}" MAGICK_LD_FLAGS)

    # Print debug message
    message(DEBUG "MagickConfig CXX Flags: ${MAGICK_CXX_FLAGS}")
    message(DEBUG "MagickConfig LD Flags: ${MAGICK_LD_FLAGS}")
endif(ImageMagick_FOUND)

# FracTool cli executable
add_executable(fractool src/fractool.cpp)
target_compile_options(fractool PRIVATE ${MAGICK_CXX_FLAGS})
target_include_directories(fractool PRIVATE ${ImageMagick_INCLUDE_DIRS})
target_link_libraries(fractool PRIVATE ${MAGICK_LD_FLAGS} ${ImageMagick_LIBRARIES})