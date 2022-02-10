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
        -DBUILD_LIST=core,imgcodecs
)
ExternalProject_Get_Property(opencv install_dir)
include_directories(${install_dir}/include/opencv4)

# ADD VERSION NUMBER DIFFERENTLY IF WE'RE ON WINDOWS OMGOMGOMGOMGOMGOMGOMGOMGOMG!!!!!
# ALSO DYNAMIC LIBS ARE IN DIFFERENT LOCATION THAN STATIC LIBS OOOOOOOOOO!!!!!
if (WIN32)
    set(SUFF 455${CMAKE_SHARED_LIBRARY_SUFFIX})
    set(LDIR bin)
else()
    set(SUFF .4.5.5${CMAKE_SHARED_LIBRARY_SUFFIX})
    set(LDIR lib)
endif()

# Core library
add_library(opencv::core SHARED IMPORTED)
set_property(TARGET opencv::core PROPERTY IMPORTED_LOCATION ${install_dir}/${LDIR}/libopencv_core${SUFF})
add_dependencies(opencv::core opencv)
install(IMPORTED_RUNTIME_ARTIFACTS opencv::core RUNTIME DESTINATION ${LDIR})

# Image Codecs library
add_library(opencv::imgcodecs SHARED IMPORTED)
set_property(TARGET opencv::imgcodecs PROPERTY IMPORTED_LOCATION ${install_dir}/${LDIR}/libopencv_imgcodecs${SUFF})
add_dependencies(opencv::imgcodecs opencv)
install(IMPORTED_RUNTIME_ARTIFACTS opencv::imgcodecs RUNTIME DESTINATION ${LDIR})