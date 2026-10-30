// g++ -std=c++17 -o matrix.out main_matrix7.cpp matrix3.cpp
#include "matrix3.hpp"
#include <iostream>

int main() {
  Matrix *mat1 = new SquareMatrix(2);

  // Set values
  mat1->setValue(0, 0, 1.0);
  mat1->setValue(0, 1, 2.0);
  mat1->setValue(1, 0, 3.0);
  mat1->setValue(1, 1, 4.0);

  std::cout << *mat1;

  return 0;
}