cmake_minimum_required(VERSION 3.10)
project(Example VERSION 1.0 LANGUAGES C CXX Fortran)

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

set(BLA_VENDOR NETLIB_BLAS)
# Tell SuiteSparse to use the BLAS/LAPACK we just built
set(SUITESPARSE_USE_EXTERNAL_BLAS_LAPACK ON CACHE BOOL "" FORCE)
# The LAPACK build defines plain targets "blas" and "lapack"
set(BLAS_LIBRARIES   blas  CACHE STRING "" FORCE)
set(LAPACK_LIBRARIES lapack CACHE STRING "" FORCE)
set(SUITESPARSE_ENABLE_PROJECTS "cholmod" CACHE STRING "" FORCE)

FetchContent_Declare(
    SuiteSparse
    GIT_REPOSITORY https://github.com/DrTimothyAldenDavis/SuiteSparse
    GIT_TAG v7.14.1
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(SuiteSparse)
FetchContent_Declare(
    eigen
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen
    GIT_TAG 5.0
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(eigen)

# Add the executable
add_executable(main src/eigen_colmod.cpp)
target_include_directories(main PRIVATE ${suitesparse_SOURCE_DIR}/CHOLMOD/Include)
target_link_libraries(main PRIVATE lapack SuiteSparse::CHOLMOD Eigen3::Eigen)
target_compile_options(main PRIVATE -Wall -Wextra -Wpedantic)
