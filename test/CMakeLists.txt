# define the unit test executable
add_executable(test tests.cpp)

# explicitly state the dependency on our header-only library, or the included headers won't be found
target_link_libraries(test PRIVATE myproject)
