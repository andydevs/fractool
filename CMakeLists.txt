# Root
cmake_minimum_required(VERSION 3.22)
project(FracTool VERSION 0.1.0)

# Configure Project
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_FIND_FRAMEWORK LAST)
include_directories(include)
link_directories(/usr/local/lib)
add_compile_options(-pthread)
add_link_options(-pthread)
set(Boost_USE_STATIC_LIBS ON)
set(BOOST_INCLUDE_LIBRARIES "log;program_options")
set(PNG_BUILD_ZLIB ON)
set(PNG_BUILD_DLL OFF)
set(PNG_SHARED OFF)
set(ASM686 ON)
set(AMD64 ON)

# External packages
add_subdirectory(extern/boost)
add_subdirectory(extern/zlib)
add_subdirectory(extern/libpng)

# Disable targets except the ones we need


# Source code
add_subdirectory(src out)

# After install
if(APPLE)
    install(CODE "execute_process(COMMAND update_dyld_shared_cache)")
elseif(NOT WIN32)
    install(CODE "execute_process(COMMAND ldconfig)")
endif()
