#include <iostream>

void foo(double &a) { a = 0.123; }

int main() {
  double *p = new double;
  *p = 1.0;
  foo(*p);
  std::cout << *p << std::endl;
  return 0;
}
