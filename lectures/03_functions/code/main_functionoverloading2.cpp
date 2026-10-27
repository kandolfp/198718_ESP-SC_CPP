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
  float a = 1.2, b = 2.2;
  std::cout << add(a, b) << std::endl;
  char c = 'c';
  long i = 1;
  std::cout << add(c, i) << std::endl;
  return 0;
}
