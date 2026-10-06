#include <iostream>

int main() {
  double a;
  double *p;
  p = &a;
  a = 0.1;
  std::cout << "Values: " << a << " " << *p << std::endl;
  std::cout << "Addresses: " << &a << " " << p << " " << &p;
  return 0;
}