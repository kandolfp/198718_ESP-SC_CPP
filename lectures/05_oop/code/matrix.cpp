#include "matrix.hpp" // Include the definition of our class
#include <iostream>
#include <stdexcept> // For exceptions

// Constructor
Matrix::Matrix(int rows, int cols)
    : rows(rows), cols(cols), data(rows, std::vector<double>(cols, 0.0)) {}

// Destructor
Matrix::~Matrix() {}

// Set a value in the matrix
void Matrix::setValue(int row, int col, double value) {
  if (row < 0 || row >= rows || col < 0 || col >= cols) {
    throw std::out_of_range("Index out of bounds");
  }

  data[row][col] = value;
}

// Get a value from the matrix
double Matrix::getValue(int row, int col) const {
  if (row < 0 || row >= rows || col < 0 || col >= cols) {
    throw std::out_of_range("Index out of bounds");
  }

  return data[row][col];
}

// print the matrix
void Matrix::print(std::ostream &stream) const {
  for (const auto &row : data) {
    for (const auto &value : row) {
      stream << value << " ";
    }
    stream << std::endl;
  }
}