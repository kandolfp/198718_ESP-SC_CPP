#include <iostream>

class Entry {
  double *_data;

public:
  Entry(double data) : _data(new double) { *_data = data; }
  double *GetData() { return _data; }
  ~Entry() { delete _data; }
};

//How can I do something like this?
double *GetData(Entry &e) { return e._data; }

int main() {
  double *d;
  if (true) {
    Entry tmp(1.0);
    d = GetData(tmp);
  }
  std::cout << *d << std::endl;
  return 0;
}