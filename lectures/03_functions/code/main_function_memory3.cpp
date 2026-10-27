#include <iostream>
#include <vector>

void print_value(std::vector<double> a) { std::cout << a[0] << std::endl; }
void print_ptr(std::vector<double> *a) { std::cout << (*a)[0] << std::endl; }
void print_reference(std::vector<double> &a) { std::cout << a[0] << std::endl; }

int main() {
  std::vector<double> a(10);
  std::cout << "Address in function " << &a << std::endl;
  print_value(a);
  return 0;
}
