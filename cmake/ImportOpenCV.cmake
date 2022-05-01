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
        -DCMAKE_FIND_FRAMEWORK=LAST
)
ExternalProject_Get_Property(opencv INSTALL_DIR)

# Include directories
if(WIN32)
    include_directories(BEFORE ${INSTALL_DIR}/include)
else()
    include_directories(BEFORE ${INSTALL_DIR}/include/opencv4)
endif()

# Set cmake build rpath
set(CMAKE_BUILD_RPATH "${CMAKE_BUILD_RPATH};${INSTALL_DIR}/lib")

# Set opencv install Dir ("borrowed" from OpenCV CMake configuration)
if(MSVC_VERSION EQUAL 1400)
    set(OCVINST vc8)
elseif(MSVC_VERSION EQUAL 1500)
    set(OCVINST vc9)
elseif(MSVC_VERSION EQUAL 1600)
    set(OCVINST vc10)
elseif(MSVC_VERSION EQUAL 1700)
    set(OCVINST vc11)
elseif(MSVC_VERSION EQUAL 1800)
    set(OCVINST vc12)
elseif(MSVC_VERSION EQUAL 1900)
    set(OCVINST vc14)
elseif(MSVC_VERSION MATCHES "^191[0-9]$")
    set(OCVINST vc15)
elseif(MSVC_VERSION MATCHES "^192[0-9]$")
    set(OCVINST vc16)
elseif(MSVC_VERSION MATCHES "^193[0-9]$")
    set(OCVINST vc17)
endif()

# Setup library macro
macro(import_opencv_library libname)
    add_library(opencv::${libname} SHARED IMPORTED)
    
    # Set properties depending on operating system
    if(WIN32)
        set(SUFF "")
        if (CMAKE_BUILD_TYPE EQUAL Debug)
            set(SUFF "d")
        endif()
        set_target_properties(opencv::${libname}
            PROPERTIES
                IMPORTED_LOCATION ${INSTALL_DIR}/x64/${OCVINST}/bin/opencv_${libname}455${SUFF}.dll
                IMPORTED_IMPLIB ${INSTALL_DIR}/x64/${OCVINST}/lib/opencv_${libname}455${SUFF}.lib)
        install(IMPORTED_RUNTIME_ARTIFACTS opencv::${libname}
            RUNTIME DESTINATION bin
            LIBRARY DESTINATION lib)
    elseif(APPLE)
        set_target_properties(opencv::${libname}
            PROPERTIES
                IMPORTED_LOCATION ${INSTALL_DIR}/lib/libopencv_${libname}.4.5.5.dylib
                IMPORTED_SONAME "@rpath/libopencv_${libname}.405.dylib")
        install(IMPORTED_RUNTIME_ARTIFACTS opencv::${libname}
            LIBRARY DESTINATION lib)
    else()
        set_target_properties(opencv::${libname}
            PROPERTIES
                IMPORTED_LOCATION ${INSTALL_DIR}/lib/libopencv_${libname}.so.4.5.5)
        install(IMPORTED_RUNTIME_ARTIFACTS opencv::${libname}
            LIBRARY DESTINATION lib)
    endif()

    # Add dependencies to external project and create install config
    add_dependencies(opencv::${libname} opencv)
endmacro()

# Import libraries
import_opencv_library(core)
import_opencv_library(imgcodecs)
import_opencv_library(imgproc)