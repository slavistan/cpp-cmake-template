cmake_minimum_required(VERSION 3.11)


##
## Boilerplate Code
##

# Enable maximum level of error warnings
if(MSVC)
  add_compile_options(/W3 /Wx)
else()
  add_compile_options(-Wall -Wpedantic -Werror)
endif()

# Declare project
project(my-example-project)

# Put all executables into the build directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

##
## End of Boilerplate code
##

add_subdirectory(src)
