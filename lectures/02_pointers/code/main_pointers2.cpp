#include <iostream>

int main() {
  double a = 1.0, *p = &a, **pp = &p;
  std::cout << "Values: " << a << " " << *p << " " << **pp << std::endl;
  return 0;
}