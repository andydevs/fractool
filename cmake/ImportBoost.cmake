# External Project
include(ExternalProject)

# Configure boost
ExternalProject_Add(
    boost
    URL "https://boostorg.jfrog.io/artifactory/main/release/1.78.0/source/boost_1_78_0.tar.gz"
    CONFIGURE_COMMAND <SOURCE_DIR>/bootstrap.sh
    BUILD_COMMAND <SOURCE_DIR>/b2
    INSTALL_COMMAND <SOURCE_DIR>/b2 install --prefix=<INSTALL_DIR>
    BUILD_IN_SOURCE 1
)
ExternalProject_Get_Property(boost install_dir)
add_definitions(-DBOOST_LOG_DYN_LINK)
include_directories(${install_dir}/include)

# Log Setup library
add_library(boost::log_setup SHARED IMPORTED)
set_property(
    TARGET boost::log_setup 
    PROPERTY IMPORTED_LOCATION 
        ${install_dir}/lib/libboost_log_setup${CMAKE_SHARED_LIBRARY_SUFFIX})
add_dependencies(boost::log_setup boost)
install(IMPORTED_RUNTIME_ARTIFACTS boost::log_setup LIBRARY DESTINATION lib)

# Log library
add_library(boost::log SHARED IMPORTED)
set_property(
    TARGET boost::log 
    PROPERTY IMPORTED_LOCATION 
        ${install_dir}/lib/libboost_log${CMAKE_SHARED_LIBRARY_SUFFIX})
add_dependencies(boost::log boost)
install(IMPORTED_RUNTIME_ARTIFACTS boost::log LIBRARY DESTINATION lib)

# Program Options library
add_library(boost::program_options SHARED IMPORTED)
set_property(
    TARGET boost::program_options 
    PROPERTY IMPORTED_LOCATION 
        ${install_dir}/lib/libboost_program_options${CMAKE_SHARED_LIBRARY_SUFFIX})
add_dependencies(boost::program_options boost)
install(IMPORTED_RUNTIME_ARTIFACTS boost::program_options LIBRARY DESTINATION lib)