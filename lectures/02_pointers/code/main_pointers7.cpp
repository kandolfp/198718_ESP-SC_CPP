#include <iostream>

int main() {
  int i = 1, j = 2;
  int *p = &i;
  *p = *p + 2;
  std::cout << i + j;

  return 0;
}