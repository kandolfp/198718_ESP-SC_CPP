#include <iostream>

class Entry {
  double *_data;

public:
  Entry(double data) : _data(new double) { *_data = data; }
  double *GetData() { return _data; }
  ~Entry() { std::cout << "Removing data..." << std::endl; }
};

int main() {
  double *d;
  if (true) {
    Entry tmp(1.0);
    d = tmp.GetData();
  }
  std::cout << *d << std::endl;
  return 0;
}