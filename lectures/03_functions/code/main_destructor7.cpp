#include <iostream>

class Entry {
  double *_data;

public:
  Entry(double data) : _data(new double) { *_data = data; }
  double *GetData() { return _data; }
  ~Entry() { delete _data; }
  friend double *GetData(Entry &e);
};

double *GetData(Entry &e) { return e._data; }

int main() {
  Entry tmp(1.0);
  std::cout << *GetData(tmp) << std::endl;
  return 0;
}