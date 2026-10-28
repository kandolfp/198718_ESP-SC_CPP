# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(Example VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directory for headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the static library
add_library(math_utils STATIC src/math_utils.cpp)

# Add the executable
add_executable(main src/main.cpp)

# Link the static library to the executable
target_link_libraries(main PRIVATE math_utils)

target_compile_options(main PRIVATE -Wall -Wextra -Wpedantic)