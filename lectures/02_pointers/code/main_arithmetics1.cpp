#include <iostream>

int main() {
  double *d;
  d = new double[4];
  d[0] = 0.0;
  d[1] = 0.1;
  d[2] = 0.2;

  std::cout << *d << " " << *(d + 1) << std::endl;

  return 0;
}