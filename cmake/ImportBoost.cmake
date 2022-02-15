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

# ADD VERSION NUMBER IF WE'RE ON LINUX AAAAA!!!!!!!!!!!!
if(CMAKE_SHARED_LIBRARY_SUFFIX STREQUAL ".so")
    set(SUFF ${CMAKE_SHARED_LIBRARY_SUFFIX}.1.78.0)
else()
    set(SUFF ${CMAKE_SHARED_LIBRARY_SUFFIX})
endif()

# Log Setup library
add_library(boost::log_setup SHARED IMPORTED)
set_property(TARGET boost::log_setup 
             PROPERTY IMPORTED_LOCATION 
                ${install_dir}/lib/libboost_log_setup${SUFF})
add_dependencies(boost::log_setup boost)
install(IMPORTED_RUNTIME_ARTIFACTS boost::log_setup 
        RUNTIME DESTINATION lib)

# Log library
add_library(boost::log SHARED IMPORTED)
set_property(TARGET boost::log 
             PROPERTY IMPORTED_LOCATION 
                ${install_dir}/lib/libboost_log${SUFF})
add_dependencies(boost::log boost)
install(IMPORTED_RUNTIME_ARTIFACTS boost::log 
        RUNTIME DESTINATION lib)

# Program Options library
add_library(boost::program_options SHARED IMPORTED)
set_property(TARGET boost::program_options 
             PROPERTY IMPORTED_LOCATION 
                ${install_dir}/lib/libboost_program_options${SUFF})
add_dependencies(boost::program_options boost)
install(IMPORTED_RUNTIME_ARTIFACTS boost::program_options 
        RUNTIME DESTINATION lib)

# Thread library
add_library(boost::thread SHARED IMPORTED)
set_property(TARGET boost::thread 
             PROPERTY IMPORTED_LOCATION 
                ${install_dir}/lib/libboost_thread${SUFF})
add_dependencies(boost::thread boost)
install(IMPORTED_RUNTIME_ARTIFACTS boost::thread 
        RUNTIME DESTINATION lib)

# Filesystem library
add_library(boost::filesystem SHARED IMPORTED)
set_property(TARGET boost::filesystem 
             PROPERTY IMPORTED_LOCATION 
                ${install_dir}/lib/libboost_filesystem${SUFF})
add_dependencies(boost::filesystem boost)
install(IMPORTED_RUNTIME_ARTIFACTS boost::filesystem 
        RUNTIME DESTINATION lib)