// g++ -std=c++17 -o matrix.out main_smart_ptr_matrix_unique.cpp matrix3.cpp
#include "matrix3.hpp"
#include <iostream>
#include <memory>

int main() {
  std::unique_ptr<Matrix> A(new Matrix(2, 2));
  std::cout << "A->getRows() = " << A->getRows() << std::endl;

  std::unique_ptr<Matrix> B;

  // Copy the address of A into B
  B = move(A);
  std::cout << "B->getRows() = " << B->getRows() << std::endl;
  return 0;
}