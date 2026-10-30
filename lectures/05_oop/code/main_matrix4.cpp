// g++ -std=c++17 -o matrix.out main_matrix4.cpp matrix2.cpp
#include "matrix2.hpp"
#include <iostream>

int main() {
  // Create a matrix
  Matrix mat1(2, 2);

  // Set values
  mat1.setValue(0, 0, 1.0);
  mat1.setValue(0, 1, 2.0);
  mat1.setValue(1, 0, 3.0);
  mat1.setValue(1, 1, 4.0);

  std::cout << "mat1 * 2.0 = " << std::endl << mat1 * 2.0;

  std::cout << "(1. / 2.) * mat1 = " << std::endl << (1.0 / 2.0) * mat1;

  return 0;
}