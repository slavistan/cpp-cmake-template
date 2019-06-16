# define the unit test executable
add_executable(unit-tests unit-tests.cpp)

# explicitly state the dependency on the targets your're referencing
target_link_libraries(unit-tests BookShelf Clock)
