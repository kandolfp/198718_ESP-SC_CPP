#include <iostream>

int main() {
  int i = 1, *p = &i;
  *p = 2;
  std::cout << i + *p;

  return 0;
}