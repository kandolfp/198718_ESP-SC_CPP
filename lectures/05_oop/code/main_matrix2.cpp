// g++ -std=c++17 -o matrix.out main_matrix2.cpp matrix2.cpp
#include "matrix2.hpp"
#include <iostream>

int main() {
  // Create a matrix
  Matrix mat(2, 2);

  // Set values
  mat.setValue(0, 0, 1.0);
  mat.setValue(0, 1, 2.0);
  mat.setValue(1, 0, 3.0);
  mat.setValue(1, 1, 4.0);

  std::cout << "This is a " << mat.getRows() << " x " << mat.getColumns()
            << " matrix with trace " << mat.trace() << std::endl;

  return 0;
}