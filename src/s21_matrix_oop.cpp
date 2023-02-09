#include "s21_matrix_oop.h"

S21Matrix::S21Matrix():S21Matrix(5, 3) {}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0)
    throw std::out_of_range("Wrong number of rows or columns");
  Allocator(rows, cols);
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  if (!&other) throw std::out_of_range("Object doesn't exist");
  CopyMatrices(other);
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  rows_ = other.rows_;
  columns_ = other.columns_;
  matrix_ = other.matrix_;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() { Destroy(); }

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  if (IsDifferentSize(other)) throw std::out_of_range("Different size of matrices");
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 0.000001) return false;
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (IsDifferentSize(other)) throw std::out_of_range("Wrong size of matrices");
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (IsDifferentSize(other)) throw std::out_of_range("Wrong size of matrices");
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  S21Matrix output = S21Matrix(rows_, other.columns_);
  if (columns_ != other.rows_) throw std::out_of_range("Wrong size of matrices");
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      for (int k = 0; k < other.columns_; ++k) {
        output.matrix_[i][k] += matrix_[i][j] * other.matrix_[j][k];
      }
    }
  }
  *this = output;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix output = S21Matrix(columns_, rows_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      output.matrix_[j][i] = matrix_[i][j];
    }
  }
  return output;
}

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix output = S21Matrix(rows_, columns_);
  if (rows_ <= 1 || rows_ != columns_) throw std::out_of_range("Wrong size of matrices");
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      S21Matrix min_arr = Minor(i, j);
      double M = min_arr.Determinant();
      output.matrix_[i][j] = pow((-1), (i + j)) * M;
    }
  }
  return output;
}

double S21Matrix::Determinant() {
  if (rows_ != columns_) throw std::out_of_range("Wrong size of matrices");
  double res = 0;
  if (rows_ > 2) {
    for (int j = 0; j < columns_; ++j) {
      double temp = matrix_[0][j];
      S21Matrix temp_arr = S21Matrix(Minor(0, j));
      if (j % 2 != 0) temp *= (-1);
      res += temp * temp_arr.Determinant();
    }
  } else {
    res = SmallDeterm();
  }
  return res;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != columns_) throw std::out_of_range("Wrong size");
  double determinant = Determinant();
  if (determinant == 0) throw std::out_of_range("Wrong matrix");
  S21Matrix output = S21Matrix(rows_, rows_);
  if (rows_ == 1) {
    output.matrix_[0][0] = pow(matrix_[0][0], -1);
  } else {
    S21Matrix transposed_matrix = S21Matrix(CalcComplements().Transpose());
    transposed_matrix.MulNumber(1 / determinant);
    output = transposed_matrix;
  }
  return output;
}

void S21Matrix::set_rows(int rows) {
  if (rows != rows_) {
    if (rows <= 0) rows = 1;
    S21Matrix temp = S21Matrix(*this);
    Destroy();
    if (rows < temp.rows_) {
      CopyMatrices(temp.matrix_, rows, temp.columns_, rows, temp.columns_);
    } else {
      CopyMatrices(temp.matrix_, rows, temp.columns_, temp.rows_, temp.columns_);
    }
  }
}

void S21Matrix::set_columns(int columns) {
  if (columns != columns_) {
    if (columns <= 0) columns = 1;
    S21Matrix temp = S21Matrix(*this);
    Destroy();
    if (columns < columns_) {
      CopyMatrices(temp.matrix_, temp.rows_, columns, temp.rows_, columns);
    } else {
      CopyMatrices(temp.matrix_, temp.rows_, columns, temp.rows_, temp.columns_);
    }
  }
}

void S21Matrix::set_value(double value, int i, int j) {
  if (IsIndicesNotInRange(i, j)) throw std::out_of_range("Wrong index");
  matrix_[i][j] = value;
}

int S21Matrix::get_rows() { return rows_; }

int S21Matrix::get_columns() { return columns_; }

double S21Matrix::get_value(int i, int j) {
  if (IsIndicesNotInRange(i, j)) throw std::out_of_range("Wrong index");
  return matrix_[i][j];
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  Destroy();
  CopyMatrices(other);
  return *this;
}

double S21Matrix::operator()(int i, int j) { return get_value(i, j); }

void S21Matrix::Allocator(int rows, int cols) {
  rows_ = rows;
  columns_ = cols;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[columns_]();
  }
}

void S21Matrix::Destroy() {
  if (matrix_) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    matrix_ = nullptr;
  }
}

S21Matrix S21Matrix::Minor(int row_index, int col_index) {
  S21Matrix output = S21Matrix(rows_ - 1, columns_ - 1);
  for (int i = 0, p = 0; i < output.rows_; ++i, ++p) {
    if (p != row_index) {
      for (int j = 0, q = 0; j < output.columns_; ++j, ++q) {
        if (q != col_index)
          output.matrix_[i][j] = matrix_[p][q];
        else
          j--;
      }
    } else {
      i--;
    }
  }
  return output;
}

double S21Matrix::SmallDeterm() {
  if (rows_ == 1)
    return matrix_[0][0];
  else
    return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
}

void S21Matrix::CopyMatrices(const S21Matrix& other) {
  Allocator(other.rows_, other.columns_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::CopyMatrices(double** matrix, int rows, int cols, int row_i,
                              int col_j) {
  Allocator(rows, cols);
  for (int i = 0; i < row_i; ++i) {
    for (int j = 0; j < col_j; ++j) {
      matrix_[i][j] = matrix[i][j];
    }
  }
}

S21Matrix operator+(const S21Matrix& current, const S21Matrix& other) {
  S21Matrix res = S21Matrix(current);
  res.SumMatrix(other);
  return res;
}

S21Matrix operator-(const S21Matrix& current, const S21Matrix& other) {
  S21Matrix res = S21Matrix(current);
  res.SubMatrix(other);
  return res;
}

S21Matrix operator*(const S21Matrix& current, const S21Matrix& other) {
  S21Matrix res = S21Matrix(current);
  res.MulMatrix(other);
  return res;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}
S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

bool S21Matrix::IsDifferentSize(const S21Matrix& other) {
  return rows_ != other.rows_ || columns_ != other.columns_;
}

bool S21Matrix::IsIndicesNotInRange(int i, int j) {
  return i >= rows_ || j >= columns_ || i < 0 || j < 0;
}