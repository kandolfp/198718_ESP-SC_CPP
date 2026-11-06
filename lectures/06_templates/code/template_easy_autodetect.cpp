// g++ -std=c++17 -o main.out template_easy_start.cpp 
#include <iostream>

template <typename T> T myMax(T x, T y) { return (x > y) ? x : y; }

int main() {

  std::cout << "Max of 7 and 3 is: " << myMax(7, 3) << std::endl;
  std::cout << "Max of 3.5 and 7.5 is :" << myMax(3.5, 7.5)
            << std::endl;
  std::cout << "Max of 'e' and 'g' is: " << myMax('e', 'g') << std::endl;

  return 0;
}