#include <iostream>

double add(double a, double b) {
  double c = a + b;
  return c;
}

int main() {
  std::cout << "add(1, 2) = " << add(1, 2) << std::endl;
  return 0;
}