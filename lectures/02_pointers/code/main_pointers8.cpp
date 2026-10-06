#include <iostream>

int main() {
  int i = 1, *p;
  *p = 2;
  std::cout << i + *p;

  return 0;
}