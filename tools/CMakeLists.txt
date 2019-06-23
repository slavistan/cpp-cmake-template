# define the tool's executable. It's dependent on clara for it's argument
# parsing. As clara does not offer a find_package() function for CMake
# we include the header-only library directly into the project.
add_executable(my-tool my-tool.cpp)
target_include_directories(my-tool PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

