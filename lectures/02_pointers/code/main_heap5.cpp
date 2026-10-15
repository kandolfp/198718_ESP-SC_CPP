#include <iostream>

int main() {
  bool condition = true;

  if (condition) {
    double *d = new double;
    *d = 0.1;
  }

  std::cout << *d << std::endl;

  return 0;
}