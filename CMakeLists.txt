cmake_minimum_required(VERSION 3.11)

##
## Developer Mode: Raise warnings to errors and, if available, utilize clang-tidy
##
option(DEVELOPER_MODE "Increases compiler verbosity and raises warnings to errors" OFF)
if(DEVELOPER_MODE)
  find_program(
    CLANG_TIDY_EXE
    NAMES "clang-tidy"
    DOC "Path to clang-tidy")
  if(NOT CLANG_TIDY_EXE)
    message(STATUS "clang-tidy not found")
  else()
    message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
    set(DO_CLANG_TIDY
      "${CLANG_TIDY_EXE}"
      "-checks=bugprone-*,cppcoreguidelines-*,clang-analzer-*,cert-*,google-*,hicpp-*,llvm-*,misc-*,modernize-*,performance-*,readability-*,-google-readability-namespace-comments,-llvm-namespace-comment"
      "-header-filter=${CMAKE_SOURCE_DIR}/include")
  endif()

  if(MSVC)
    add_compile_options(/W3 /Wx)
  else()
    add_compile_options(-Wall -Wpedantic -Werror)
  endif()
endif()

# Declare project
project(my-example-project)

# Put all executables into the build directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

add_subdirectory(src)
