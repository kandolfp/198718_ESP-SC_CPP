// g++ -std=c++17 -o main.out template_variable.cpp
#include <iomanip>
#include <iostream>

template <typename T>
constexpr T pi = T(3.141592653589793238462643383279502884197169399);

int main() {
  // Using pi with different types
  std::cout << std::setprecision(64) << "Pi as float: \t\t"
            << pi<float> << std::endl
            << "Pi as double: \t\t" << pi<double> << std::endl
            << "Pi as long double: \t" << pi<long double> << std::endl;
  return 0;
}