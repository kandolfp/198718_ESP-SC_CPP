// g++ -std=c++17 -o matrix.out main_smart_ptr_matrix_shared.cpp matrix3.cpp
#include "matrix3.hpp"
#include <iostream>
#include <memory>

int main() {
  std::shared_ptr<Matrix> A(new Matrix(2, 2));
  std::shared_ptr<Matrix> B;

  // Copy the address of A into B
  B = A;
  std::cout << "A.getRows() = " << A->getRows() << std::endl
            << "B.getRows() = " << B->getRows() << std::endl
            << "A.use_count() = " << A.use_count() << std::endl;
  return 0;
}