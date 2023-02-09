#include "matrix.h"

TL::Matrix::Matrix():Matrix(5, 3) {}

TL::Matrix::Matrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0)
    throw std::out_of_range("Wrong number of rows or columns");
  Allocator(rows, cols);
}

TL::Matrix::Matrix(const Matrix& other) {
  if (!&other) throw std::out_of_range("Object doesn't exist");
  CopyMatrices(other);
}

TL::Matrix::Matrix(Matrix&& other) {
  rows_ = other.rows_;
  columns_ = other.columns_;
  matrix_ = other.matrix_;
  other.matrix_ = nullptr;
}

TL::Matrix::~Matrix() { Destroy(); }

bool TL::Matrix::EqMatrix(const Matrix& other) {
  if (IsDifferentSize(other)) throw std::out_of_range("Different size of matrices");
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 0.000001) return false;
    }
  }
  return true;
}

void TL::Matrix::SumMatrix(const Matrix& other) {
  if (IsDifferentSize(other)) throw std::out_of_range("Wrong size of matrices");
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void TL::Matrix::SubMatrix(const Matrix& other) {
  if (IsDifferentSize(other)) throw std::out_of_range("Wrong size of matrices");
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void TL::Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      matrix_[i][j] *= num;
    }
  }
}

void TL::Matrix::MulMatrix(const Matrix& other) {
  Matrix output = Matrix(rows_, other.columns_);
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

TL::Matrix TL::Matrix::Transpose() {
  Matrix output = Matrix(columns_, rows_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      output.matrix_[j][i] = matrix_[i][j];
    }
  }
  return output;
}

TL::Matrix TL::Matrix::CalcComplements() {
  Matrix output = Matrix(rows_, columns_);
  if (rows_ <= 1 || rows_ != columns_) throw std::out_of_range("Wrong size of matrices");
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      Matrix min_arr = Minor(i, j);
      double M = min_arr.Determinant();
      output.matrix_[i][j] = pow((-1), (i + j)) * M;
    }
  }
  return output;
}

double TL::Matrix::Determinant() {
  if (rows_ != columns_) throw std::out_of_range("Wrong size of matrices");
  double res = 0;
  if (rows_ > 2) {
    for (int j = 0; j < columns_; ++j) {
      double temp = matrix_[0][j];
      Matrix temp_arr = Matrix(Minor(0, j));
      if (j % 2 != 0) temp *= (-1);
      res += temp * temp_arr.Determinant();
    }
  } else {
    res = SmallDeterm();
  }
  return res;
}

TL::Matrix TL::Matrix::InverseMatrix() {
  if (rows_ != columns_) throw std::out_of_range("Wrong size");
  double determinant = Determinant();
  if (determinant == 0) throw std::out_of_range("Wrong matrix");
  Matrix output = Matrix(rows_, rows_);
  if (rows_ == 1) {
    output.matrix_[0][0] = pow(matrix_[0][0], -1);
  } else {
    Matrix transposed_matrix = Matrix(CalcComplements().Transpose());
    transposed_matrix.MulNumber(1 / determinant);
    output = transposed_matrix;
  }
  return output;
}

void TL::Matrix::set_rows(int rows) {
  if (rows != rows_) {
    if (rows <= 0) rows = 1;
    Matrix temp = Matrix(*this);
    Destroy();
    if (rows < temp.rows_) {
      CopyMatrices(temp.matrix_, rows, temp.columns_, rows, temp.columns_);
    } else {
      CopyMatrices(temp.matrix_, rows, temp.columns_, temp.rows_, temp.columns_);
    }
  }
}

void TL::Matrix::set_columns(int columns) {
  if (columns != columns_) {
    if (columns <= 0) columns = 1;
    Matrix temp = Matrix(*this);
    Destroy();
    if (columns < columns_) {
      CopyMatrices(temp.matrix_, temp.rows_, columns, temp.rows_, columns);
    } else {
      CopyMatrices(temp.matrix_, temp.rows_, columns, temp.rows_, temp.columns_);
    }
  }
}

void TL::Matrix::set_value(double value, int i, int j) {
  if (IsIndicesNotInRange(i, j)) throw std::out_of_range("Wrong index");
  matrix_[i][j] = value;
}

int TL::Matrix::get_rows() { return rows_; }

int TL::Matrix::get_columns() { return columns_; }

double TL::Matrix::get_value(int i, int j) {
  if (IsIndicesNotInRange(i, j)) throw std::out_of_range("Wrong index");
  return matrix_[i][j];
}

TL::Matrix& TL::Matrix::operator=(const Matrix& other) {
  Destroy();
  CopyMatrices(other);
  return *this;
}

double TL::Matrix::operator()(int i, int j) { return get_value(i, j); }

void TL::Matrix::Allocator(int rows, int cols) {
  rows_ = rows;
  columns_ = cols;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[columns_]();
  }
}

void TL::Matrix::Destroy() {
  if (matrix_) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    matrix_ = nullptr;
  }
}

TL::Matrix TL::Matrix::Minor(int row_index, int col_index) {
  Matrix output = Matrix(rows_ - 1, columns_ - 1);
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

double TL::Matrix::SmallDeterm() {
  if (rows_ == 1)
    return matrix_[0][0];
  else
    return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
}

void TL::Matrix::CopyMatrices(const Matrix& other) {
  Allocator(other.rows_, other.columns_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void TL::Matrix::CopyMatrices(double** matrix, int rows, int cols, int row_i,
                              int col_j) {
  Allocator(rows, cols);
  for (int i = 0; i < row_i; ++i) {
    for (int j = 0; j < col_j; ++j) {
      matrix_[i][j] = matrix[i][j];
    }
  }
}

TL::Matrix TL::operator+(const Matrix& current, const Matrix& other) {
  Matrix res = Matrix(current);
  res.SumMatrix(other);
  return res;
}

TL::Matrix TL::operator-(const Matrix& current, const Matrix& other) {
  Matrix res = Matrix(current);
  res.SubMatrix(other);
  return res;
}

TL::Matrix TL::operator*(const Matrix& current, const Matrix& other) {
  Matrix res = Matrix(current);
  res.MulMatrix(other);
  return res;
}

TL::Matrix& TL::Matrix::operator+=(const Matrix& other) {
  SumMatrix(other);
  return *this;
}
TL::Matrix& TL::Matrix::operator-=(const Matrix& other) {
  SubMatrix(other);
  return *this;
}

TL::Matrix& TL::Matrix::operator*=(const Matrix& other) {
  MulMatrix(other);
  return *this;
}

bool TL::Matrix::operator==(const Matrix& other) { return EqMatrix(other); }

bool TL::Matrix::IsDifferentSize(const Matrix& other) {
  return rows_ != other.rows_ || columns_ != other.columns_;
}

bool TL::Matrix::IsIndicesNotInRange(int i, int j) {
  return i >= rows_ || j >= columns_ || i < 0 || j < 0;
}