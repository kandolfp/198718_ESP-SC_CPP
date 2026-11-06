#include <iostream>

// Template metaprogramming for calculationg factorial at compile-time
template <int N> struct Factorial {
  static const int value = N * Factorial<N - 1>::value;
};

// Specialization for the base class (Factorial<0>)
template <> struct Factorial<0> {
  static const int value = 1;
};

int main() {

  // Factorial computation happens at compile-time
  std::cout << "Factorial of 5 is: " << Factorial<5>::value << std::endl;

  return 0;
}