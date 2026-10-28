# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(Example VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG 52eb8108c5bdec04579160ae17225d66034bd723
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add the include directory for headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the static library
add_library(math_utils STATIC src/math_utils.cpp)

# Add the executable
add_executable(main src/main.cpp)

# Link the static library to the executable
target_link_libraries(main PRIVATE math_utils)

target_compile_options(main PRIVATE -Wall -Wextra -Wpedantic)

enable_testing()

add_executable(
    math_utils_test
    tests/math_utils.test.cpp
)

target_link_libraries(
    math_utils_test
    math_utils
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(math_utils_test)

# Add Cppcheck as a custom target
find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
if (CMAKE_CXX_CPPCHECK)
    add_custom_target(
        cppcheck
        COMMAND ${CMAKE_CXX_CPPCHECK}
        --enable=all
        --inconclusive
        --std=c++${CMAKE_CXX_STANDARD}
        --quiet
        --suppress=missingIncludeSystem
        --output-file=${CMAKE_BINARY_DIR}/cppcheck_report.txt
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/tests
        COMMENT "Running Cppcheck static analysis..."
        VERBATIM
    )
else()
    message(WARNING "Cppcheck not found! Static analysis will not be available.")
endif()
