#include <iostream>
#include <vector>

int main() {
  std::vector<long> v;
  std::vector<long> *p = &v;
  //std::vector<long>* q = &v;
  v.resize(3);
  v[0] = 0;
  v[1] = 1;
  v[2] = 2;
  (*p).resize(4);
  //q->resize(4);
  (*p)[3] = 3;

  return 0;
}