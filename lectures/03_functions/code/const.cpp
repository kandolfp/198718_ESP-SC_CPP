void print_value(const std::vector<double> &a) {
  std::cout << a[0] << std::endl;
  a[0] = 5.0; // compile error
}

void print_value(std::vector<double> &a) { a[0] = 5.0; }

const double *p;      // p can be modified, but *p cannot.
double *const p = &a; // p can not be modified, but *p can.
