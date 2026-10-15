#include <iostream>

void print_address(double *pa) {
  std::cout << "Address in function " << pa << std::endl;
  *pa = 5.0;
}

int main() {
  double a = 1.2;
  std::cout << "Address in function " << &a << std::endl;
  print_address(&a);
  return 0;
}
