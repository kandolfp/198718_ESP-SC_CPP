#include <iostream>

void foo(double *a) { a[0] = 1.234; }

int main() {
  double *p = new double[3];
  p[0] = 0;
  p[1] = 1;
  p[2] = 2;
  foo(p);
  std::cout << *p << std::endl;
  delete[] p;
  
  return 0;
}
