#include <iostream>

int main() {
  int a = 1;
  int *p = &a;
  int **pp = &p;

  std::cout << " &a = " << *pp << " " << " = " << &a << std::endl;
  std::cout << " &p = " << pp << " " << " = " << &p << std::endl;
  std::cout << " &pp = " << &pp << std::endl;

  return 0;
}