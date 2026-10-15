#include <iostream>

int main() {
  bool condition = true;
  double *d;

  if (condition) {
    d = new double;
    *d = 0.1;
  }

  std::cout << *d << std::endl;

  return 0;
}