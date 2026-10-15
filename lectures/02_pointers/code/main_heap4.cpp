#include <iostream>

int main() {
  double *d = new double;
  *d = 0.1;
  double *p = d;

  delete p;

  std::cout << *d << std::endl;

  return 0;
}