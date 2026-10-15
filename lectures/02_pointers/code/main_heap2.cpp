#include <iostream>

int main() {
  double *v = new double[2]; // allocate array of size 2 in heap
  v[0] = 0.1;
  v[1] = 0.12;

  for (int i = 0; i < 2; i++)
    std::cout << v[i] << " ";
  std::cout << std::endl;

  delete[] v; // free memory of entire array

  return 0;
}