#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>

class Matrix {
private:
  int rows;                              // Number of rows
  int cols;                              // Number of columns
  std::vector<std::vector<double>> data; // 2D vector to store elements

public:
  Matrix(int rows, int cols); // Constructor

  ~Matrix(); // Destructor

  void setValue(int row, int col, double value); // Set a value

  double getValue(int row, int col) const; // Get a value

  void print(std::ostream &stream) const; // Display the matrix
};

#endif // MATRIX_HPP