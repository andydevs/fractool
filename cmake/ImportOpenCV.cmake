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
ExternalProject_Get_Property(opencv INSTALL_DIR)
ExternalProject_Get_Property(opencv SOURCE_DIR)
include_directories(BEFORE
    ${INSTALL_DIR}/include/opencv4
    ${SOURCE_DIR}/3rdparty)

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
    set(SUFF .405${CMAKE_SHARED_LIBRARY_SUFFIX})
    set(LDIR lib)
endif()

# Core library
add_library(opencv::core SHARED IMPORTED)
set_property(TARGET opencv::core 
             PROPERTY IMPORTED_LOCATION 
                ${INSTALL_DIR}/${LDIR}/libopencv_core${SUFF})
add_dependencies(opencv::core opencv)
install(IMPORTED_RUNTIME_ARTIFACTS opencv::core 
	LIBRARY DESTINATION ${LDIR})

# Image Codecs library
add_library(opencv::imgcodecs SHARED IMPORTED)
set_property(TARGET opencv::imgcodecs 
             PROPERTY IMPORTED_LOCATION 
                ${INSTALL_DIR}/${LDIR}/libopencv_imgcodecs${SUFF})
add_dependencies(opencv::imgcodecs opencv)
install(IMPORTED_RUNTIME_ARTIFACTS opencv::imgcodecs 
	LIBRARY DESTINATION ${LDIR})
