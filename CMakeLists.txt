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
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

# External packages
include(${PROJECT_SOURCE_DIR}/extern/libpng/libpng-install/lib/libpng/libpng16.cmake)
include_directories(${PROJECT_SOURCE_DIR}/extern/libpng/libpng-install/include)
set(BOOST_ROOT "${PROJECT_SOURCE_DIR}/extern/boost/boost-install")
find_package(Boost REQUIRED COMPONENTS log log_setup program_options)
include_directories(${Boost_INCLUDE_DIRS})

# Source code
add_subdirectory(src modules)

# After install
if(APPLE)
    install(CODE "execute_process(COMMAND update_dyld_shared_cache)")
elseif(NOT WIN32)
    install(CODE "execute_process(COMMAND ldconfig)")
endif()

# Add CPack
set(CPACK_PACKAGE_NAME "FracTool")
set(CPACK_PACKAGE_VENDOR "Andydevs")
set(CPACK_PACKAGE_DIRECTORY packages/${CMAKE_BUILD_TYPE}/)
set(CPACK_PACKAGE_FILE_NAME ${PROJECT_NAME}-${CMAKE_BUILD_TYPE}-${PROJECT_VERSION}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR})
if(APPLE)
    set(CPACK_GENERATOR "STGZ;TGZ")
elseif(WIN32)
    set(CPACK_GENERATOR "NSIS;ZIP")
endif()
include(CPack)