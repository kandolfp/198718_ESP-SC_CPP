#include <iostream>

int main() {
  double a, b;
  std::cout << "Addresses: " << &a << " " << &b << std::endl;
  a = 0.1;
  b = a;
  std::cout << "Addresses: "<< &a << " " << &b << std::endl;
  return 0;
}