# Create a unit-test target which uses the Catch2 framework.
# The header file is included inside the project itself Catch2 does not
# provide a find_package().
add_executable(unit-tests unit-tests.cpp)
target_include_directories(unit-tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
