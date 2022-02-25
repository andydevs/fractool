# External Project
include(ExternalProject)

# Configure boost
if(WIN32)
    set(BOOTSTRAP "<SOURCE_DIR>\\bootstrap.bat")
    set(B2 "<SOURCE_DIR>\\b2.exe")
else()
    set(BOOTSTRAP "<SOURCE_DIR>/bootstrap.sh")
    set(B2 "<SOURCE_DIR>/b2")
endif()

# Add external projecct
ExternalProject_Add(
    boost
    URL "https://boostorg.jfrog.io/artifactory/main/release/1.78.0/source/boost_1_78_0.tar.gz"
    CONFIGURE_COMMAND ${BOOTSTRAP}
    BUILD_COMMAND ${B2}
    INSTALL_COMMAND ${B2} install --prefix=<INSTALL_DIR>
    BUILD_IN_SOURCE 1
)
add_definitions(-DBOOST_LOG_DYN_LINK)
ExternalProject_Get_Property(boost INSTALL_DIR)

# Include directories
if(WIN32)
    include_directories(${INSTALL_DIR}/include/boost-1_78)
else()
    include_directories(${INSTALL_DIR}/include)
endif()

# Set cmake build rpath
set(CMAKE_BUILD_RPATH "${CMAKE_BUILD_RPATH};${INSTALL_DIR}/lib")

# ADD VERSION NUMBER IF WE'RE ON LINUX AAAAA!!!!!!!!!!!!
if(CMAKE_SHARED_LIBRARY_SUFFIX STREQUAL ".so")
    set(SUFF ${CMAKE_SHARED_LIBRARY_SUFFIX}.1.78.0)
else()
    set(SUFF ${CMAKE_SHARED_LIBRARY_SUFFIX})
endif()

# Setup library macro
macro(import_boost_library libname)
    add_library(boost::${libname} SHARED IMPORTED)
    set_property(TARGET boost::${libname}
                 PROPERTY IMPORTED_LOCATION
                    ${INSTALL_DIR}/lib/libboost_${libname}${SUFF})
    if(WIN32)
        set_property(TARGET boost::${libname}
                     PROPERTY IMPORTED_IMPLIB
                        ${INSTALL_DIR}/lib/libboost_${libname}.lib)
    endif()
    add_dependencies(boost::${libname} boost)
    install(IMPORTED_RUNTIME_ARTIFACTS boost::${libname}
            RUNTIME DESTINATION lib)
endmacro()

# Import libraries
import_boost_library(log_setup)
import_boost_library(log)
import_boost_library(program_options)
import_boost_library(thread)
import_boost_library(filesystem)
import_boost_library(regex)
import_boost_library(chrono)
import_boost_library(atomic)