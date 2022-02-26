# Root
cmake_minimum_required(VERSION 3.22)
project(FracTool VERSION 0.1.0)

# Configure Project
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_FIND_FRAMEWORK LAST)
include_directories(include)
link_directories(/usr/local/lib)
if(NOT WIN32)
    add_compile_options(-pthread)
    add_link_options(-pthread)
endif()
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(BUILD_SHARED_LIBS ON)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# External Modules
include(ImportBoost)
include(ImportOpenCV)

# Source directory
add_subdirectory(src out)

# After install
if(APPLE)
    install(CODE "execute_process(COMMAND update_dyld_shared_cache)")
elseif(NOT WIN32)
    install(CODE "execute_process(COMMAND ldconfig)")
endif()