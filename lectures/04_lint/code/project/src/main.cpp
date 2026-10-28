#include <iostream>
#include <math_utils.hpp>

int main() {
  std::cout << "1 - (1 + 1) = " << sub(1, add(1, 1)) << std::endl;
  return 0;
}