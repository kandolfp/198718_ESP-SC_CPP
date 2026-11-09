#include <iostream>
#include <vector>
#include <cblas.h>
#include <timer.hpp>

int main() {
  int N = 1e8;
  std::vector<double> x(N);
  for (int i = 0; i < N; i++)
    x[i] = i / double(N);

  Timer blas, my;
  my.reset();
  double s = 0.0;
  for (int i = 0; i < N; i++)
    s += x[i] * x[i];
  std::cout << "MY: \t" << s << " " << my.elapsed() << " s" << std::endl;

  blas.reset();
  s = cblas_ddot(N, &x[0], 1, &x[0], 1);
  std::cout << "BLAS: \t" << s << " " << blas.elapsed() << " s" << std::endl;

  return 0;
}