#include <iostream>

class A {
public:
  double *_d;
  A(double d) : _d(new double) { *_d = d; }
  A(const A &a) {
    _d = new double;
    *_d = *a._d;
  }
  ~A() { delete _d; }
};
void foo(A a) {} // calls copy constructor

int main() {
  A a(1.234);
  if (true)
    A b(a); // calls copy constructor
  foo(a);
  std::cout << *a._d << std::endl;
}