# Root
cmake_minimum_required(VERSION 3.0)
project(FracTool)

# Configure Project
set(CMAKE_CXX_STANDARD 14)
include_directories(include)
link_directories(/usr/local/lib)
add_compile_options(-pthread)
add_link_options(-pthread)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# External Modules
include(ImportBoost)
include(ImportOpenCV)

# Source directory
add_subdirectory(src out)