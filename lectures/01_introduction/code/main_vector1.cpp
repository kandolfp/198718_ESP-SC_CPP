#include <iostream>
#include <vector>

int main() {
  std::vector<double> v(5);
  v.reserve(10);
  v[0] = 1.0;
  v[2] = 1.0;
  std::cout << v.size() << std::endl;
  std::cout << v[0] << " " << v[1] << " " << v[2] << std::endl;

  return 0;
}