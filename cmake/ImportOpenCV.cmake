# External Project
include(ExternalProject)

# Configure opencv
ExternalProject_Add(
    opencv
    GIT_REPOSITORY "https://github.com/opencv/opencv.git"
    GIT_TAG "4.5.5"
    CMAKE_ARGS
        -DOPENCV_FORCE_3RDPARTY_BUILD=ON
        -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
)
ExternalProject_Get_Property(opencv install_dir)
include_directories(${install_dir}/include/opencv4)

# Core library
add_library(opencv::core SHARED IMPORTED)
set_property(
    TARGET opencv::core 
    PROPERTY IMPORTED_LOCATION 
        ${install_dir}/lib/libopencv_core${CMAKE_SHARED_LIBRARY_SUFFIX})
add_dependencies(opencv::core opencv)

# Image Codecs library
add_library(opencv::imgcodecs SHARED IMPORTED)
set_property(
    TARGET opencv::imgcodecs 
    PROPERTY IMPORTED_LOCATION 
        ${install_dir}/lib/libopencv_imgcodecs${CMAKE_SHARED_LIBRARY_SUFFIX})
add_dependencies(opencv::imgcodecs opencv)

# Install targets
get_property(opencv_core_loc TARGET opencv::core PROPERTY IMPORTED_LOCATION)
get_property(opencv_imgcodecs_loc TARGET opencv::imgcodecs PROPERTY IMPORTED_LOCATION)
install(
    FILES ${opencv_core_loc} ${opencv_imgcodecs_loc}
    DESTINATION lib
)