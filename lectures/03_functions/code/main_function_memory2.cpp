#include <iostream>

void print_address(double &a) {
  std::cout << "Address in function " << &a << std::endl;
  a = 5.0;
}

int main() {
  double a = 1.2;
  std::cout << "Address in function " << &a << std::endl;
  print_address(a);
  return 0;
}
