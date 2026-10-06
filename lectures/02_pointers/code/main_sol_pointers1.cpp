#include <iostream>

int main() {
  int i = 1;
  int *p = &i;
  *p = 2;
  std::cout << "i = " << i << std::endl;

  return 0;
}