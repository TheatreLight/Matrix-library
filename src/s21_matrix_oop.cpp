#include "s21_matrix_oop.h"

#include <cstdio>

S21Matrix::S21Matrix():S21Matrix(5, 3) {}
S21Matrix::S21Matrix(int _rows, int _columns) {
  if (_rows <= 0 || _columns <= 0)
    throw std::out_of_range("Wrong number of rows or columns");
  allocator(_rows, _columns);
}
S21Matrix::S21Matrix(const S21Matrix& other) {
  if (!&other) throw std::out_of_range("Object doesn't exist");
  copy_matrices(other);
}
S21Matrix::S21Matrix(S21Matrix&& other) {
  rows = other.rows;
  columns = other.columns;
  matrix = other.matrix;
  other.matrix = nullptr;
  other.rows = 0;
  other.columns = 0;
}
S21Matrix::~S21Matrix() { destroy(); }

bool S21Matrix::eq_matrix(const S21Matrix& other) {
  bool res = true;
  if (rows != other.rows || columns != other.columns)
    throw std::out_of_range("Different size of matrices");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (fabs(matrix[i][j] - other.matrix[i][j]) > 0.000001) {
        res = false;
        i = rows;
        break;
      }
    }
  }
  return res;
}
void S21Matrix::sum_matrix(const S21Matrix& other) {
  if (rows != other.rows || columns != other.columns)
    throw std::out_of_range("Wrong size of matrices");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix[i][j] += other.matrix[i][j];
    }
  }
}
void S21Matrix::sub_matrix(const S21Matrix& other) {
  if (rows != other.rows || columns != other.columns)
    throw std::out_of_range("Wrong size of matrices");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix[i][j] -= other.matrix[i][j];
    }
  }
}
void S21Matrix::mul_number(const double num) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix[i][j] *= num;
    }
  }
}
void S21Matrix::mul_matrix(const S21Matrix& other) {
  S21Matrix output = S21Matrix(rows, other.columns);
  if (columns != other.rows) throw std::out_of_range("Wrong size of matrices");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      for (int k = 0; k < other.columns; k++) {
        output.matrix[i][k] += matrix[i][j] * other.matrix[j][k];
      }
    }
  }
  *this = output;
}
S21Matrix S21Matrix::transpose() {
  S21Matrix output = S21Matrix(columns, rows);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      output.matrix[j][i] = matrix[i][j];
    }
  }
  return output;
}
S21Matrix S21Matrix::calc_complements() {
  S21Matrix output = S21Matrix(rows, columns);
  if (rows <= 1 || rows != columns)
    throw std::out_of_range("Wrong size of matrices");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      S21Matrix min_arr = minor(i, j);
      double M = min_arr.determinant();
      output.matrix[i][j] = pow((-1), (i + j)) * M;
    }
  }
  return output;
}
double S21Matrix::determinant() {
  double res = 0;
  if (rows != columns) throw std::out_of_range("Wrong size of matrices");
  if (rows > 2) {
    for (int j = 0; j < columns; j++) {
      double temp = matrix[0][j];
      S21Matrix temp_arr = S21Matrix(minor(0, j));
      if (j % 2 != 0) temp *= (-1);
      res += temp * temp_arr.determinant();
    }
  } else {
    res = small_determ();
  }
  return res;
}
S21Matrix S21Matrix::inverse_matrix() {
  if (rows != columns) throw std::out_of_range("Wrong size");
  double det = determinant();
  if (det == 0) throw std::out_of_range("Wrong matrix");
  S21Matrix output = S21Matrix(rows, rows);
  if (rows == 1) {
    output.matrix[0][0] = pow(matrix[0][0], -1);
  } else {
    S21Matrix alg_compl = S21Matrix(calc_complements());
    S21Matrix trans = S21Matrix(alg_compl.transpose());
    det = 1 / det;
    trans.mul_number(det);
    output = trans;
  }
  return output;
}

void S21Matrix::setRows(int _rows) {
  if (_rows != rows) {
    if (_rows <= 0) _rows = 1;
    S21Matrix temp = S21Matrix(*this);
    destroy();
    if (_rows < temp.rows) {
      copy_matrices(temp.matrix, _rows, temp.columns, _rows, temp.columns);
    } else {
      copy_matrices(temp.matrix, _rows, temp.columns, temp.rows, temp.columns);
    }
  }
}
void S21Matrix::setColumns(int _columns) {
  if (_columns != columns) {
    if (_columns <= 0) _columns = 1;
    S21Matrix temp = S21Matrix(*this);
    destroy();
    if (_columns < columns) {
      copy_matrices(temp.matrix, temp.rows, _columns, temp.rows, _columns);
    } else {
      copy_matrices(temp.matrix, temp.rows, _columns, temp.rows, temp.columns);
    }
  }
}
void S21Matrix::setValue(double value, int i, int j) {
  if (i >= rows || j >= columns) throw std::out_of_range("Wrong index");
  matrix[i][j] = value;
}
int S21Matrix::getRows() { return this->rows; }
int S21Matrix::getColumns() { return this->columns; }
double S21Matrix::getValue(int i, int j) {
  if (i >= rows || j >= columns || i < 0 || j < 0) throw std::out_of_range("Wrong index");
  return matrix[i][j];
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  destroy();
  copy_matrices(other);
  return *this;
}
double S21Matrix::operator()(int i, int j) { return getValue(i, j); }

void S21Matrix::allocator(int _rows, int _cols) {
  rows = _rows;
  columns = _cols;
  matrix = new double*[rows];
  for (int i = 0; i < rows; i++) {
    matrix[i] = new double[columns]();
  }
}
void S21Matrix::destroy() {
  if (matrix) {
    for (int i = 0; i < rows; i++) {
      delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
  }
}
S21Matrix S21Matrix::minor(int row_index, int col_index) {
  S21Matrix output = S21Matrix(rows - 1, columns - 1);
  for (int i = 0, p = 0; i < output.rows; i++, p++) {
    if (p != row_index) {
      for (int j = 0, q = 0; j < output.columns; j++, q++) {
        if (q != col_index)
          output.matrix[i][j] = matrix[p][q];
        else
          j--;
      }
    } else {
      i--;
    }
  }
  return output;
}
double S21Matrix::small_determ() {
  double res;
  if (rows == 1)
    res = matrix[0][0];
  else
    res = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  return res;
}
void S21Matrix::copy_matrices(const S21Matrix& other) {
  allocator(other.rows, other.columns);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix[i][j] = other.matrix[i][j];
    }
  }
}
void S21Matrix::copy_matrices(double** _matrix, int _rows, int _cols, int row_i,
                              int col_j) {
  allocator(_rows, _cols);
  for (int i = 0; i < row_i; i++) {
    for (int j = 0; j < col_j; j++) {
      matrix[i][j] = _matrix[i][j];
    }
  }
}

S21Matrix operator+(const S21Matrix& current, const S21Matrix& other) {
  S21Matrix res = S21Matrix(current);
  res.sum_matrix(other);
  return res;
}
S21Matrix operator-(const S21Matrix& current, const S21Matrix& other) {
  S21Matrix res = S21Matrix(current);
  res.sub_matrix(other);
  return res;
}
S21Matrix operator*(const S21Matrix& current, const S21Matrix& other) {
  S21Matrix res = S21Matrix(current);
  res.mul_matrix(other);
  return res;
}
S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  sum_matrix(other);
  return *this;
}
S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  sub_matrix(other);
  return *this;
}
S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  mul_matrix(other);
  return *this;
}
bool S21Matrix::operator==(const S21Matrix& other) { return eq_matrix(other); }
