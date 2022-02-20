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
include_directories(BEFORE ${INSTALL_DIR}/include/opencv4)
set(CMAKE_BUILD_RPATH "${CMAKE_BUILD_RPATH};${INSTALL_DIR}/lib")

# ADD VERSION NUMBER DIFFERENTLY IF WE'RE ON WINDOWS 
# OMGOMGOMGOMGOMGOMGOMGOMGOMG!!!!! ALSO DYNAMIC LIBS 
# ARE IN DIFFERENT LOCATION THAN STATIC LIBS OOOOOOOOOO!!!!!
# (also the names are slightly different between mac, 
# linux, and windows because my life is a cruel joke)
if (WIN32)
    set(SUFF 455${CMAKE_SHARED_LIBRARY_SUFFIX})
    set(LDIR bin)
elseif(CMAKE_SHARED_LIBRARY_SUFFIX STREQUAL ".so")
    set(SUFF ${CMAKE_SHARED_LIBRARY_SUFFIX}.4.5.5)
    set(LDIR lib)
else()
    set(SUFF .4.5.5${CMAKE_SHARED_LIBRARY_SUFFIX})
    set(LDIR lib)
endif()

# Core library
add_library(opencv::core SHARED IMPORTED)
set_property(TARGET opencv::core 
             PROPERTY IMPORTED_LOCATION 
                ${INSTALL_DIR}/${LDIR}/libopencv_core${SUFF})
if(APPLE)
    set_property(TARGET opencv::core
                PROPERTY IMPORTED_SONAME
                    "@rpath/libopencv_core.405.dylib")
endif()
add_dependencies(opencv::core opencv)
install(IMPORTED_RUNTIME_ARTIFACTS opencv::core 
	LIBRARY DESTINATION ${LDIR})

# Image Codecs library
add_library(opencv::imgcodecs SHARED IMPORTED)
set_property(TARGET opencv::imgcodecs 
             PROPERTY IMPORTED_LOCATION 
                ${INSTALL_DIR}/${LDIR}/libopencv_imgcodecs${SUFF})
if(APPLE)
    set_property(TARGET opencv::imgcodecs
                PROPERTY IMPORTED_SONAME
                    "@rpath/libopencv_imgcodecs.405.dylib")
endif()
add_dependencies(opencv::imgcodecs opencv)
install(IMPORTED_RUNTIME_ARTIFACTS opencv::imgcodecs 
	LIBRARY DESTINATION ${LDIR})
