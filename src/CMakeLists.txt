# Build 'private-lib'
add_library(private-lib
  private-lib.cpp)

target_include_directories(private-lib
  PRIVATE
    "${PROJECT_SOURCE_DIR}/src")

# Build library 'mylib' which depends on 'private-lib'
add_library(mylib
  mylib.cpp)

target_include_directories(mylib
  PRIVATE
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/src"
  )

target_link_libraries(mylib
  PRIVATE
    private-lib)

# Build main executable which depends on 'mylib'
add_executable(main
  main.cpp)

target_include_directories(main
  PUBLIC "${PROJECT_SOURCE_DIR}/include")

target_link_libraries(main
  mylib)
