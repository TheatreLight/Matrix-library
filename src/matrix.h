#ifndef _SRC_S21_MATRIX_OOP_H
#define _SRC_S21_MATRIX_OOP_H

#include <cmath>
#include <iostream>

namespace TL {
  class Matrix {
    public:
      Matrix();
      Matrix(int rows, int cols);
      Matrix(const Matrix& other);
      Matrix(Matrix&& other);
      ~Matrix();

      bool EqMatrix(const Matrix& other);
      void SumMatrix(const Matrix& other);
      void SubMatrix(const Matrix& other);
      void MulNumber(const double num);
      void MulMatrix(const Matrix& other);
      Matrix Transpose();
      Matrix CalcComplements();
      double Determinant();
      Matrix InverseMatrix();

      void set_rows(int rows);
      void set_columns(int columns);
      void set_value(double value, int i, int j);
      int get_rows();
      int get_columns();
      double get_value(int i, int j);

      Matrix& operator+=(const Matrix& other);
      Matrix& operator-=(const Matrix& other);
      Matrix& operator*=(const Matrix& other);
      bool operator==(const Matrix& other);
      Matrix& operator=(const Matrix& other);
      Matrix operator=(Matrix&& other) = delete;
      double operator()(int i, int j);
  
    private:
      int rows_, columns_;
      double** matrix_;

    private:
      void CopyMatrices(const Matrix& other);
      void CopyMatrices(double** matrix, int rows, int cols, int row_i,
                     int col_j);
      double SmallDeterm();
      Matrix Minor(int row_index, int col_index);
      void Destroy();
      void Allocator(int rows, int cols);
      bool IsDifferentSize(const Matrix& other);
      bool IsIndicesNotInRange(int i, int j);
  };

  Matrix operator+ (const Matrix& current, const Matrix& other);
  Matrix operator-(const Matrix& current, const Matrix& other);
  Matrix operator*(const Matrix& current, const Matrix& other);
};

#endif  // _SRC_S21_MATRIX_OOP_H