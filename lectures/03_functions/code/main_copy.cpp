#include <iostream>

class A {
public:
  double *_d;
  A(double d) : _d(new double) { *_d = d; }
  ~A() { delete _d; }
};

void foo(A aFoo) {}

int main() {
  A a(1.234);
  foo(a);
  std::cout << *a._d << std::endl;
}