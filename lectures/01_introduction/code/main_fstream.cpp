#include <fstream> // library to read/write data
#include <iostream>

int main() {
  double tmp1, tmp2;
  std::fstream in("./code/main_fstream_input.txt"); // specify input file

  in >> tmp1; // read first value
  in >> tmp2; // read second value
  std::cout << tmp1 << " ";
  std::cout << tmp2 << std::endl;

  return 0;
}