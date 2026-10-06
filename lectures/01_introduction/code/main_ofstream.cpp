#include <fstream> // library to read/write data
#include <iostream>

int main() {
  std::ofstream out("./code/result.txt"); // specify output file

  out << 1.0 << " ";
  out << 2.2 << std::endl; // write values

  return 0;
}