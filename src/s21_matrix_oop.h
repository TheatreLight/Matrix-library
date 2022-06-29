#pragma once

#include <cmath>
#include <iostream>
class S21Matrix {
 private:
  int rows, columns;
  double** matrix;

  void copy_matrices(const S21Matrix& other);
  void copy_matrices(double** _matrix, int rows, int cols, int row_i,
                     int col_j);
  double small_determ();
  S21Matrix minor(int row_index, int col_index);
  void destroy();
  void allocator(int _rows, int _cols);

 public:
  S21Matrix();
  S21Matrix(int _rows, int _columns);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  bool eq_matrix(const S21Matrix& other);
  void sum_matrix(const S21Matrix& other);
  void sub_matrix(const S21Matrix& other);
  void mul_number(const double num);
  void mul_matrix(const S21Matrix& other);
  S21Matrix transpose();
  S21Matrix calc_complements();
  double determinant();
  S21Matrix inverse_matrix();

  void setRows(int _rows);
  void setColumns(int columns);
  void setValue(double value, int i, int j);
  int getRows();
  int getColumns();
  double getValue(int i, int j);

  friend S21Matrix operator+(const S21Matrix& current, const S21Matrix& other);
  friend S21Matrix operator-(const S21Matrix& current, const S21Matrix& other);
  friend S21Matrix operator*(const S21Matrix& current, const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  bool operator==(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  double operator()(int i, int j);
};
