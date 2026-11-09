cmake_minimum_required(VERSION 3.10)
project(Example VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CBLAS True)
include(FetchContent)
FetchContent_Declare(
    lapack
    GIT_REPOSITORY https://github.com/Reference-LAPACK/lapack/
    GIT_TAG v3.12.1
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(lapack)

# Add the include directory for headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the executable
add_executable(main src/blas.cpp)
target_link_libraries(main PRIVATE cblas) 
target_compile_options(main PRIVATE -Wall -Wextra -Wpedantic)
