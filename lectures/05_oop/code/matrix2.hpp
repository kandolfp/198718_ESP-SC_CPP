#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>

class Matrix {
private:
  int rows;                              // Number of rows
  int cols;                              // Number of columns
  std::vector<std::vector<double>> data; // 2D vector to store elements
  bool isValidIndex(int row, int col) const;

public:
  Matrix(int rows, int cols); // Constructor

  ~Matrix(); // Destructor

  void setValue(int row, int col, double value); // Set a value

  double getValue(int row, int col) const; // Get a value

  void print(std::ostream &stream) const; // Display the matrix

  int getRows() const;

  int getColumns() const;

  bool isSquare() const;

  double trace();

  // Operator overloading
  Matrix operator+(const Matrix &other) const; // Addition
  Matrix operator*(const Matrix &other) const; // Multiplication

  // Overload the stream insertion operator (friend function)
  friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

  // Scalar multiplication (Matrix * Scalar)
  Matrix operator*(double scalar) const;

  // Friend function for Scalar * Matrix
  friend Matrix operator*(double scalar, const Matrix &matrix);
};

#endif // MATRIX_HPP