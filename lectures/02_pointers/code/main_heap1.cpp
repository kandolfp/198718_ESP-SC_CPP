#include <iostream>

int main() {
  double dStatic = 0.1;
  double *dDynamic = new double; // allocate memory in heap
  *dDynamic = 0.1;

  std::cout << dStatic << " " << *dDynamic << std::endl;

  delete dDynamic; // free memory

  std::cout << dStatic << " " << *dDynamic << std::endl;

  return 0;
}