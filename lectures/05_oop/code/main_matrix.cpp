// g++ -std=c++17 -o matrix.out main_matrix.cpp matrix.cpp
#include "matrix.hpp"
#include <iostream>

int main() {
  // Create a matrix
  Matrix mat(2, 2);

  // Set values
  mat.setValue(0, 0, 1.0);
  mat.setValue(0, 1, 2.0);
  mat.setValue(1, 0, 3.0);
  mat.setValue(1, 1, 4.0);

  // Display the matrices
  std::cout << "Matrix:" << std::endl;
  mat.print(std::cout);

  return 0;
}