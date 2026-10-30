#include "matrix2.hpp" // Include the definition of our class
#include <iostream>
#include <stdexcept> // For exceptions

// Constructor
Matrix::Matrix(int rows, int cols)
    : rows(rows), cols(cols), data(rows, std::vector<double>(cols, 0.0)) {}

// Destructor
Matrix::~Matrix() {}

bool Matrix::isValidIndex(int row, int col) const {
  return row >= 0 && row < rows && col >= 0 && col < cols;
}

// Set a value in the matrix
void Matrix::setValue(int row, int col, double value) {
  if (!isValidIndex(row, col)) {
    throw std::out_of_range("Index out of bounds");
  }

  data[row][col] = value;
}

// Get a value from the matrix
double Matrix::getValue(int row, int col) const {
  if (!isValidIndex(row, col)) {
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

int Matrix::getRows() const { return rows; }

int Matrix::getColumns() const { return cols; }

bool Matrix::isSquare() const { return (rows == cols); }

double Matrix::trace() {
  if (!isSquare()) {
    throw std::invalid_argument("Matrix needs to be square");
  }

  double value = 0;
  for (int i = 0; i < rows; i++) {
    value += getValue(i, i);
  }

  return value;
}

// Operator overloading: Matrix addition
Matrix Matrix::operator+(const Matrix &other) const {
  if (rows != other.rows || cols != other.cols) {
    throw std::invalid_argument("Matrix dimensions do not match");
  }

  Matrix result(rows, cols);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      result.setValue(i, j, data[i][j] + other.data[i][j]);
    }
  }

  return result;
}

// Operator overloading: Matrix multiplication
Matrix Matrix::operator*(const Matrix &other) const {
  if (cols != other.rows) {
    throw std::invalid_argument("Matrix dimensions do not match");
  }

  Matrix result(rows, other.cols);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < other.cols; ++j) {
      double sum = 0.0;
      for (int k = 0; k < cols; ++k) {
        sum += data[i][k] * other.data[k][j];
      }
      result.setValue(i, j, sum);
    }
  }

  return result;
}

// Overload the stream insertion operator
std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
  matrix.print(os);

  return os;
}

// Scalar multiplication (Matrix * Scalar)
Matrix Matrix::operator*(double scalar) const {
  Matrix result(rows, cols);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      result.setValue(i, j, data[i][j] * scalar);
    }
  }

  return result;
}

// Scalar multiplication (Scalar * Matrix)
Matrix operator*(double scalar, const Matrix &matrix) {
  Matrix result(matrix.rows, matrix.cols);

  for (int i = 0; i < matrix.rows; ++i) {
    for (int j = 0; j < matrix.cols; ++j) {
      result.setValue(i, j, scalar * matrix.data[i][j]);
    }
  }

  return result;
}
