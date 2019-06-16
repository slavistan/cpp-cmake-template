cmake_minimum_required(VERSION 3.12)

# Register our project
project(SaltShaker VERSION 1.0.0)

# Set sane default options
set(CMAKE_CXX_STANDARD 20) # set the C++ standard for the project's targets
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # generate a compilation database

#############
# Project Targets
############

### BookShelf - a header only-library
# add the library to the project using 'add_library' and 'INTERFACE' and declare the location of where the header files
# are to be found. Use the CMake variable 'PROJECT_SOURCE_DIR' which points the project's root path.
add_library(BookShelf INTERFACE)
target_include_directories(BookShelf INTERFACE ${PROJECT_SOURCE_DIR}/include/bookshelf)

### Clock - another header-only library with a dependency on BookShelf and an external library.
add_library(Clock INTERFACE)
target_include_directories(Clock INTERFACE ${PROJECT_SOURCE_DIR}/include/clock)
find_package(Eigen3) # imports the dependency's targets 
target_link_libraries(Clock
  INTERFACE
    BookShelf
    Eigen3::Eigen)


# Miscellaneous targets related to this project but not required for its usage (such as unit-tests).
option(BUILD_TESTS "Build tests" ON)
if(BUILD_TESTS)
    add_subdirectory(test)
endif()

# include external tools
include(cmake/external-tools.cmake)
