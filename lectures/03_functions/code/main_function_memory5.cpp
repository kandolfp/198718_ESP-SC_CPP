#include <iostream>

void foo(double a) { a = 0.123; }

int main() {
  double a = 1.2;
  foo(a);
  std::cout << a << std::endl;
  return 0;
}
