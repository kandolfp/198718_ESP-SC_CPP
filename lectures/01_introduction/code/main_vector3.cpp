#include <cmath>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v(2);
  v[0] = 0;
  v[1] = 0.1;
  v[2] = 0.2;

  std::vector<int> v1(2);
  v1 = v + v;

  std::cout << v1[0] << " " << v1[1] << " " << v1[2] << std::endl;

  return 0;
}