#include <iostream>

class Entry {
  double *_data;

public:
  Entry(double data) : _data(&data) {}
  ~Entry() { delete _data; }
};

int main() {
  double *data = new double;
  Entry tmp(*data);
  delete data;
  return 0;
}
