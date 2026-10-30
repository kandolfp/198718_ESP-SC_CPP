// g++ -std=c++17 -o matrix.out main_matrix6.cpp matrix3.cpp
#include "matrix3.hpp"
#include <iostream>

int main() {
  SquareMatrix mat1(2);
  Matrix mat2(2, 2);

  // Set values
  mat1.setValue(0, 0, 1.0);
  mat1.setValue(0, 1, 2.0);
  mat1.setValue(1, 0, 3.0);
  mat1.setValue(1, 1, 4.0);

  mat2.setValue(0, 0, 5.0);
  mat2.setValue(0, 1, 6.0);
  mat2.setValue(1, 0, 7.0);
  mat2.setValue(1, 1, 8.0);

  std::cout << mat1 - mat2;
  std::cout << mat2.det() << std::endl;

  return 0;
}