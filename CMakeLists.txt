cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

project(myproject VERSION 1.0.0)

add_library(myproject INTERFACE)
target_include_directories(myproject INTERFACE ${PROJECT_SOURCE_DIR}/include)
target_compile_features(myproject INTERFACE cxx_std_20)

# library dependencies
# target_link_libraries(myproject
#     INTERFACE
#         Eigen3::Eigen
#         TBB::tbb)

# MS-GSL: Configure behaviour of violations of pre- and post-conditions for debug and release builds (Expects & Ensures).
add_compile_definitions($<IF:$<CONFIG:Debug>,GSL_TERMINATE_ON_CONTRACT_VIOLATION,GSL_UNENFORCED_ON_CONTRACT_VIOLATION>)

option(BUILD_TESTS "Build tests" ON)
if(BUILD_TESTS)
    add_subdirectory(test)
endif()

# include external tools
include(cmake/external-tools.cmake)
