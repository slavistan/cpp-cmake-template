# Create a unit-test target which uses its own headers.
# The header file is included inside the project itself.
add_executable(unit-tests unit-tests.cpp)
target_include_directories(unit-tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(unit-tests BookShelf Clock)
