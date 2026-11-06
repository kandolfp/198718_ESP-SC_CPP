// g++ -std=c++17 -o matrix.out main_smart_ptr_matrix_weak.cpp matrix3.cpp
#include "matrix3.hpp"
#include <iostream>
#include <memory>

int main() {
  std::shared_ptr<Matrix> A(new Matrix(2, 2));
  std::weak_ptr<Matrix> B;

  B = A;
  std::cout << "A.getRows() = " << A->getRows() << std::endl;
  // Convert weak_ptr to shared_ptr before accessing the object
  if (std::shared_ptr<Matrix> tmp = B.lock())
    std::cout << "B.getRows() = " << tmp->getRows() << std::endl;
  else
    std::cout << "The object no longer exists." << std::endl;

  std::cout << "A.use_count() = " << A.use_count() << std::endl;
  return 0;
}