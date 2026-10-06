#include <iostream>

int main() {
  int i = 1;
  int *p = &i;
  int **pp = &p;
  **pp = 3;
  std::cout << "i = " << i << std::endl;

  return 0;
}