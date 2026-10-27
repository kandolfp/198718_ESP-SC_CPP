#include <iostream>

double add(double a, double b) {
  std::cout << "double+ ";
  return a + b;
}

int add(int a, int b) {
  std::cout << "int+ ";
  return a + b;
}

int main() {
  std::cout << add(1, 2) << std::endl;
  std::cout << add(1.0, 2.0) << std::endl;
  return 0;
}
