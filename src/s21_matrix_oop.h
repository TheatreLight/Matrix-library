#ifndef _SRC_S21_MATRIX_OOP_H
#define _SRC_S21_MATRIX_OOP_H

#include <cmath>
#include <iostream>

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  void set_rows(int rows);
  void set_columns(int columns);
  void set_value(double value, int i, int j);
  int get_rows();
  int get_columns();
  double get_value(int i, int j);

  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  bool operator==(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix operator=(S21Matrix&& other) = delete;
  double operator()(int i, int j);
  
 private:
  int rows_, columns_;
  double** matrix_;

 private:
  void CopyMatrices(const S21Matrix& other);
  void CopyMatrices(double** matrix, int rows, int cols, int row_i,
                     int col_j);
  double SmallDeterm();
  S21Matrix Minor(int row_index, int col_index);
  void Destroy();
  void Allocator(int rows, int cols);
  bool IsDifferentSize(const S21Matrix& other);
  bool IsIndicesNotInRange(int i, int j);
};

S21Matrix operator+ (const S21Matrix& current, const S21Matrix& other);
S21Matrix operator-(const S21Matrix& current, const S21Matrix& other);
S21Matrix operator*(const S21Matrix& current, const S21Matrix& other);

#endif  // _SRC_S21_MATRIX_OOP_H