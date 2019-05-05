cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# MS-GSL: Configure behaviour of violations of pre- and post-conditions for debug and release builds (Expects & Ensures).
add_compile_definitions($<IF:$<CONFIG:Debug>,GSL_TERMINATE_ON_CONTRACT_VIOLATION,GSL_UNENFORCED_ON_CONTRACT_VIOLATION>)

#
# Custom make targets to run external tools
#
# (Custom make targets.A) clang-tidy
#
find_program(RUN_CLANG_TIDY_EXECUTABLE
             NAMES "run-clang-tidy.py"
             DOC "Path to the run-clang-tidy.py executable.")
if (RUN_CLANG_TIDY_EXECUTABLE)
  message(STATUS "run-clang-tidy found at '${RUN_CLANG_TIDY_EXECUTABLE}'.")
  add_custom_target(clang-tidy run-clang-tidy.py -checks="*" -header-filter=".*")
endif()
# 2. (Custom make targets.B) cppcheck
find_program(CPPCHECK_EXECUTABLE
             NAMES "cppcheck"
             DOC "Path to the cppcheck executable.")
if (CPPCHECK_EXECUTABLE)
  message(STATUS "cppcheck found at '${CPPCHECK_EXECUTABLE}'.")
  add_custom_target(cppcheck cppcheck --max-ctu-depth=3 --enable="all" --inconclusive --project=compile_commands.json)
endif()

add_executable(test main.cpp)
