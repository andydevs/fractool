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
function(check_one_config RES)
    set(${RES} "" PARENT_SCOPE)
    if(NOT OpenCV_RUNTIME OR NOT OpenCV_ARCH)
        return()
    endif()
    set(candidates)
    if(OpenCV_STATIC)
        list(APPEND candidates "${OpenCV_ARCH}/${OpenCV_RUNTIME}/staticlib")
    endif()
    if(OpenCV_CUDA)
        list(APPEND candidates "gpu/${OpenCV_ARCH}/${OpenCV_RUNTIME}/lib")
    endif()
    if(OpenCV_CUDA AND OpenCV_STATIC)
        list(APPEND candidates "gpu/${OpenCV_ARCH}/${OpenCV_RUNTIME}/staticlib")
    endif()
        list(APPEND candidates "${OpenCV_ARCH}/${OpenCV_RUNTIME}/lib")
    foreach(c ${candidates})
        set(p "${OpenCV_CONFIG_PATH}/${c}")
        if(EXISTS "${p}/OpenCVConfig.cmake")
            set(${RES} "${p}" PARENT_SCOPE)
            return()
        endif()
    endforeach()
endfunction()
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
    check_one_config(has_VS2017)
    if(NOT has_VS2017)
        set(OCVINST vc14) # selecting previous compatible runtime version
    endif()
elseif(MSVC_VERSION MATCHES "^192[0-9]$")
    set(OCVINST vc16)
    check_one_config(has_VS2019)
    if(NOT has_VS2019)
        set(OCVINST vc15) # selecting previous compatible runtime version
        check_one_config(has_VS2017)
        if(NOT has_VS2017)
            set(OCVINST vc14) # selecting previous compatible runtime version
        endif()
    endif()
elseif(MSVC_VERSION MATCHES "^193[0-9]$")
    set(OCVINST vc17)
    check_one_config(has_VS2022)
    if(NOT has_VS2022)
        set(OCVINST vc16)
        check_one_config(has_VS2019)
        if(NOT has_VS2019)
            set(OCVINST vc15) # selecting previous compatible runtime version
            check_one_config(has_VS2017)
            if(NOT has_VS2017)
                set(OCVINST vc14) # selecting previous compatible runtime version
            endif()
        endif()
    endif()
endif()

# Setup library macro
macro(import_opencv_library libname)
    add_library(opencv::${libname} SHARED IMPORTED)
    
    # Set properties depending on operating system
    if(WIN32)
        set_target_properties(opencv::${libname}
            PROPERTIES
                IMPORTED_LOCATION ${INSTALL_DIR}/x64/${OCVINST}/bin/opencv_${libname}455d.dll
                IMPORTED_IMPLIB ${INSTALL_DIR}/x64/${OCVINST}/lib/opencv_${libname}455d.lib)
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