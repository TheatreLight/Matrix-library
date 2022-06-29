#include "../src/s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(constructMatrix, test1) {
  const int row = 5;
  const int col = 3;
  double first[row][col] = {
      {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  S21Matrix firstMatrix = S21Matrix();
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_EQ(first[i][j], firstMatrix.getValue(i, j));
    }
  }
}

TEST(constructMatrix, test2) {
  const int row = 10;
  const int col = 10;
  double first[row][col] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  S21Matrix firstMatrix = S21Matrix(10, 10);
  EXPECT_EQ(row, firstMatrix.getRows());
  EXPECT_EQ(col, firstMatrix.getColumns());
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_EQ(first[i][j], firstMatrix.getValue(i, j));
    }
  }
}

TEST(constructMatrix, test3) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55}};
  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix result = S21Matrix(firstMatrix);
  EXPECT_EQ(row, result.getRows());
  EXPECT_EQ(col, result.getColumns());
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_EQ(first[i][j], result.getValue(i, j));
    }
  }
}

TEST(constructMatrix, test4) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55}};
  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix result = std::move(firstMatrix);
  EXPECT_EQ(row, result.getRows());
  EXPECT_EQ(col, result.getColumns());
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_EQ(first[i][j], result.getValue(i, j));
    }
  }
  EXPECT_EQ(0, firstMatrix.getRows());
  EXPECT_EQ(0, firstMatrix.getColumns());
}

TEST(sumMatrices, test1) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55}};
  double second[row][col] = {{3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01}};
  double third[row][col] = {{5.56, 5.56, 5.56, 5.56, 5.56},
                            {5.56, 5.56, 5.56, 5.56, 5.56},
                            {5.56, 5.56, 5.56, 5.56, 5.56},
                            {5.56, 5.56, 5.56, 5.56, 5.56},
                            {5.56, 5.56, 5.56, 5.56, 5.56}};
  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix secondMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.setValue(second[i][j], i, j);
    }
  }
  firstMatrix.sum_matrix(secondMatrix);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(third[i][j], firstMatrix.getValue(i, j), 0.0000000001);
    }
  }
}

TEST(sumMatrices, test2) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432}};
  double second[row][col] = {
      {-0.321456987, -1.098765432, -2.0010023, -0.321456987, -1.098765432},
      {-0.321456987, -1.098765432, -2.0010023, -0.321456987, -1.098765432},
      {-0.321456987, -1.098765432, -2.0010023, -0.321456987, -1.098765432},
      {-0.321456987, -1.098765432, -2.0010023, -0.321456987, -1.098765432},
      {-0.321456987, -1.098765432, -2.0010023, -0.321456987, -1.098765432}};
  double third[row][col] = {{0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix secondMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.setValue(second[i][j], i, j);
    }
  }
  firstMatrix.sum_matrix(secondMatrix);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(third[i][j], firstMatrix.getValue(i, j), 0.0000000001);
    }
  }
}

TEST(subMatrices, test1) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432}};
  double second[row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};
  double third[col][col] = {
      {-0.789643013, -1.123434568, -1.3322977, -1.900743013, -0.012334568},
      {-0.789643013, -1.123434568, -1.3322977, -1.900743013, -0.012334568},
      {-0.789643013, -1.123434568, -1.3322977, -1.900743013, -0.012334568},
      {-0.789643013, -1.123434568, -1.3322977, -1.900743013, -0.012334568},
      {-0.789643013, -1.123434568, -1.3322977, -1.900743013, -0.012334568}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix secondMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.setValue(second[i][j], i, j);
    }
  }
  firstMatrix.sub_matrix(secondMatrix);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(firstMatrix.getValue(i, j), third[i][j], 0.0000000001);
    }
  }
}

TEST(eqMatrices, test1) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432}};
  double second[row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix secondMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.setValue(second[i][j], i, j);
    }
  }
  EXPECT_FALSE(firstMatrix.eq_matrix(secondMatrix));
}

TEST(eqMatrices, test2) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};
  double second[row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix secondMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.setValue(second[i][j], i, j);
    }
  }
  EXPECT_TRUE(firstMatrix.eq_matrix(secondMatrix));
}

TEST(multNumber, test1) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};

  double number = 0.001;

  double third[row][col] = {
      {0.0011111, 0.0022222, 0.0033333, 0.0022222, 0.0011111},
      {0.0011111, 0.0022222, 0.0033333, 0.0022222, 0.0011111},
      {0.0011111, 0.0022222, 0.0033333, 0.0022222, 0.0011111},
      {0.0011111, 0.0022222, 0.0033333, 0.0022222, 0.0011111},
      {0.0011111, 0.0022222, 0.0033333, 0.0022222, 0.0011111}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }

  firstMatrix.mul_number(number);

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(third[i][j], firstMatrix.getValue(i, j), 0.0000000001);
    }
  }
}

TEST(mulMatrices, test1) {
  const int row = 5;
  const int col = 3;
  const int _row = 3;
  const int _col = 4;
  double first[row][col] = {
      {1, 2, 3}, {1, 2, 3}, {1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
  double second[_row][_col] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
  double third[row][_col] = {{6, 12, 18, 24},
                             {6, 12, 18, 24},
                             {6, 12, 18, 24},
                             {6, 12, 18, 24},
                             {6, 12, 18, 24}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix secondMatrix = S21Matrix(_row, _col);
  for (int i = 0; i < _row; i++) {
    for (int j = 0; j < _col; j++) {
      secondMatrix.setValue(second[i][j], i, j);
    }
  }
  firstMatrix.mul_matrix(secondMatrix);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < _col; j++) {
      EXPECT_EQ(third[i][j], firstMatrix.getValue(i, j));
    }
  }
}

TEST(transMatrices, test1) {
  const int row = 3;
  const int col = 3;
  double first[row][col] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
  double third[row][col] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }

  S21Matrix result = S21Matrix(firstMatrix.transpose());
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_EQ(third[i][j], result.getValue(i, j));
    }
  }
}

TEST(calcCompl, test1) {
  const int row = 3;
  const int col = 3;
  double first[row][col] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
  double third[row][col] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix result = S21Matrix(firstMatrix.calc_complements());
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_EQ(third[i][j], result.getValue(i, j));
    }
  }
}

TEST(calcCompl, test2) {
  const int row = 2;
  const int col = 2;
  double first[row][col] = {{1, 2}, {0, 4}};
  double third[row][col] = {{4, 0}, {-2, 1}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix result = S21Matrix(firstMatrix.calc_complements());
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_EQ(third[i][j], result.getValue(i, j));
    }
  }
}

TEST(determinant, test1) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{1, 2, 1, 4, 2},
                            {2, 1, 3, 2, 1},
                            {1, 2, 2, 2, 1},
                            {2, 1, 1, 1, 2},
                            {1, 2, 1, 2, 3}};

  double det = 21;

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  EXPECT_EQ(21, firstMatrix.determinant());
}

TEST(determinant, test2) {
  const int row = 2;
  const int col = 2;
  double first[row][col] = {{1, 2}, {0, 4}};

  double det = 4;

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  EXPECT_EQ(4, firstMatrix.determinant());
}

TEST(invertMatrix, test1) {
  const int row = 3;
  const int col = 3;
  double first[row][col] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  double third[row][col] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix result = S21Matrix(firstMatrix.inverse_matrix());
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_EQ(third[i][j], result.getValue(i, j));
    }
  }
}

TEST(invertMatrix, test2) {
  const int row = 1;
  const int col = 1;
  double first[row][col] = {{2}};
  double third[row][col] = {{0.5}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix result = S21Matrix(firstMatrix.inverse_matrix());
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_EQ(third[i][j], result.getValue(i, j));
    }
  }
}

TEST(invertMatrix, test3) {
  const int row = 2;
  const int col = 2;
  double first[row][col] = {{2, -3}, {1, 1}};
  double third[row][col] = {{0.2, 0.6}, {-0.2, 0.4}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix result = S21Matrix(firstMatrix.inverse_matrix());
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(third[i][j], result.getValue(i, j), 0.0000000001);
    }
  }
}

TEST(plus, test1) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55}};
  double second[row][col] = {{3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01}};
  double third[row][col] = {{5.56, 5.56, 5.56, 5.56, 5.56},
                            {5.56, 5.56, 5.56, 5.56, 5.56},
                            {5.56, 5.56, 5.56, 5.56, 5.56},
                            {5.56, 5.56, 5.56, 5.56, 5.56},
                            {5.56, 5.56, 5.56, 5.56, 5.56}};
  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix secondMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.setValue(second[i][j], i, j);
    }
  }
  S21Matrix result = firstMatrix + secondMatrix;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(third[i][j], result.getValue(i, j), 0.0000000001);
    }
  }
}

TEST(minus, test1) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432}};
  double second[row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};
  double third[col][col] = {
      {-0.789643013, -1.123434568, -1.3322977, -1.900743013, -0.012334568},
      {-0.789643013, -1.123434568, -1.3322977, -1.900743013, -0.012334568},
      {-0.789643013, -1.123434568, -1.3322977, -1.900743013, -0.012334568},
      {-0.789643013, -1.123434568, -1.3322977, -1.900743013, -0.012334568},
      {-0.789643013, -1.123434568, -1.3322977, -1.900743013, -0.012334568}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix secondMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.setValue(second[i][j], i, j);
    }
  }
  S21Matrix result = firstMatrix - secondMatrix;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(result.getValue(i, j), third[i][j], 0.0000000001);
    }
  }
}

TEST(multiplication, test1) {
  const int row = 5;
  const int col = 3;
  const int _row = 3;
  const int _col = 4;
  double first[row][col] = {
      {1, 2, 3}, {1, 2, 3}, {1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
  double second[_row][_col] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
  double third[row][_col] = {{6, 12, 18, 24},
                             {6, 12, 18, 24},
                             {6, 12, 18, 24},
                             {6, 12, 18, 24},
                             {6, 12, 18, 24}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix secondMatrix = S21Matrix(_row, _col);
  for (int i = 0; i < _row; i++) {
    for (int j = 0; j < _col; j++) {
      secondMatrix.setValue(second[i][j], i, j);
    }
  }
  S21Matrix result = firstMatrix * secondMatrix;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < _col; j++) {
      EXPECT_EQ(third[i][j], result.getValue(i, j));
    }
  }
}

TEST(Increase, test1) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55}};
  double second[row][col] = {{3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01}};
  double third[row][col] = {{5.56, 5.56, 5.56, 5.56, 5.56},
                            {5.56, 5.56, 5.56, 5.56, 5.56},
                            {5.56, 5.56, 5.56, 5.56, 5.56},
                            {5.56, 5.56, 5.56, 5.56, 5.56},
                            {5.56, 5.56, 5.56, 5.56, 5.56}};
  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix secondMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.setValue(second[i][j], i, j);
    }
  }
  firstMatrix += secondMatrix;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(third[i][j], firstMatrix.getValue(i, j), 0.0000000001);
    }
  }
}

TEST(Decrease, test1) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432}};
  double second[row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};
  double third[col][col] = {
      {-0.789643013, -1.123434568, -1.3322977, -1.900743013, -0.012334568},
      {-0.789643013, -1.123434568, -1.3322977, -1.900743013, -0.012334568},
      {-0.789643013, -1.123434568, -1.3322977, -1.900743013, -0.012334568},
      {-0.789643013, -1.123434568, -1.3322977, -1.900743013, -0.012334568},
      {-0.789643013, -1.123434568, -1.3322977, -1.900743013, -0.012334568}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix secondMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.setValue(second[i][j], i, j);
    }
  }
  firstMatrix -= secondMatrix;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(firstMatrix.getValue(i, j), third[i][j], 0.0000000001);
    }
  }
}

TEST(multIncrease, test1) {
  const int row = 5;
  const int col = 3;
  const int _row = 3;
  const int _col = 4;
  double first[row][col] = {
      {1, 2, 3}, {1, 2, 3}, {1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
  double second[_row][_col] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
  double third[row][_col] = {{6, 12, 18, 24},
                             {6, 12, 18, 24},
                             {6, 12, 18, 24},
                             {6, 12, 18, 24},
                             {6, 12, 18, 24}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix secondMatrix = S21Matrix(_row, _col);
  for (int i = 0; i < _row; i++) {
    for (int j = 0; j < _col; j++) {
      secondMatrix.setValue(second[i][j], i, j);
    }
  }
  firstMatrix *= secondMatrix;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < _col; j++) {
      EXPECT_EQ(third[i][j], firstMatrix.getValue(i, j));
    }
  }
}

TEST(Equal, test1) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432},
      {0.321456987, 1.098765432, 2.0010023, 0.321456987, 1.098765432}};
  double second[row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix secondMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.setValue(second[i][j], i, j);
    }
  }
  EXPECT_FALSE(firstMatrix == secondMatrix);
}

TEST(Equal, test2) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};
  double second[row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                             {1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix secondMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.setValue(second[i][j], i, j);
    }
  }
  EXPECT_TRUE(firstMatrix == secondMatrix);
}

TEST(Copying, test1) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix result = firstMatrix;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(first[i][j], result.getValue(i, j), 0.0000000001);
    }
  }
}

TEST(Iterator, test1) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(first[i][j], firstMatrix(i, j), 0.0000000001);
    }
  }
}

TEST(SetRows, test1) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  const int new_row = 10;
  double result[new_row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                                 {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                                 {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                                 {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                                 {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0}};
  firstMatrix.setRows(new_row);
  for (int i = 0; i < new_row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(result[i][j], firstMatrix(i, j), 0.0000000001);
    }
  }
}

TEST(SetRows, test2) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  const int new_row = 1;
  double result[new_row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};
  firstMatrix.setRows(new_row);
  for (int i = 0; i < new_row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(result[i][j], firstMatrix(i, j), 0.0000000001);
    }
  }
}

TEST(SetColumns, test1) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  const int new_col = 10;
  double result[row][new_col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111, 0, 0, 0, 0, 0},
                                 {1.1111, 2.2222, 3.3333, 2.2222, 1.1111, 0, 0, 0, 0, 0},
                                 {1.1111, 2.2222, 3.3333, 2.2222, 1.1111, 0, 0, 0, 0, 0},
                                 {1.1111, 2.2222, 3.3333, 2.2222, 1.1111, 0, 0, 0, 0, 0},
                                 {1.1111, 2.2222, 3.3333, 2.2222, 1.1111, 0, 0, 0, 0, 0}};
  firstMatrix.setColumns(new_col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < new_col; j++) {
      EXPECT_NEAR(result[i][j], firstMatrix(i, j), 0.0000000001);
    }
  }
}

TEST(SetColumns, test2) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};

  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  const int new_col = 1;
  double result[row][new_col] = {{1.1111},
                                {1.1111},
                                {1.1111},
                                {1.1111},
                                {1.1111}};
  firstMatrix.setColumns(new_col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < new_col; j++) {
      EXPECT_NEAR(result[i][j], firstMatrix(i, j), 0.0000000001);
    }
  }
}

TEST(Except, test1) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55}};
  double second[row-1][col] = {{3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01}};
  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix secondMatrix = S21Matrix(row-1, col);
  for (int i = 0; i < row-1; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.setValue(second[i][j], i, j);
    }
  }
  EXPECT_THROW(firstMatrix.sum_matrix(secondMatrix), std::out_of_range);
}

TEST(Except, test2) {
  EXPECT_THROW(S21Matrix(-10, 10), std::out_of_range);
}

TEST(Except, test3) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55}};
  double second[row-1][col] = {{3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01}};
  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix secondMatrix = S21Matrix(row-1, col);
  for (int i = 0; i < row-1; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.setValue(second[i][j], i, j);
    }
  }
  EXPECT_THROW(firstMatrix.eq_matrix(secondMatrix), std::out_of_range);
}

TEST(Except, test4) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55}};
  double second[row-1][col] = {{3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01}};
  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix secondMatrix = S21Matrix(row-1, col);
  for (int i = 0; i < row-1; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.setValue(second[i][j], i, j);
    }
  }
  EXPECT_THROW(firstMatrix.sub_matrix(secondMatrix), std::out_of_range);
}

TEST(Except, test5) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55},
                            {2.55, 3.55, 2.55, 3.55, 2.55}};
  double second[row-1][col] = {{3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01}};
  S21Matrix firstMatrix = S21Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.setValue(first[i][j], i, j);
    }
  }
  S21Matrix secondMatrix = S21Matrix(row-1, col);
  for (int i = 0; i < row-1; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.setValue(second[i][j], i, j);
    }
  }
  EXPECT_THROW(firstMatrix.mul_matrix(secondMatrix), std::out_of_range);
}

TEST(Except, test6) {
  const int row = 5;
  const int col = 5;
  double second[row-1][col] = {{3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01}};
  S21Matrix secondMatrix = S21Matrix(row-1, col);
  for (int i = 0; i < row-1; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.setValue(second[i][j], i, j);
    }
  }
  EXPECT_THROW(secondMatrix.calc_complements(), std::out_of_range);
}

TEST(Except, test7) {
  const int row = 5;
  const int col = 5;
  double second[row-1][col] = {{3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01}};
  S21Matrix secondMatrix = S21Matrix(row-1, col);
  for (int i = 0; i < row-1; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.setValue(second[i][j], i, j);
    }
  }
  EXPECT_THROW(secondMatrix.determinant(), std::out_of_range);
}

TEST(Except, test8) {
  const int row = 5;
  const int col = 5;
  double second[row-1][col] = {{3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01}};
  S21Matrix secondMatrix = S21Matrix(row-1, col);
  for (int i = 0; i < row-1; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.setValue(second[i][j], i, j);
    }
  }
  EXPECT_THROW(secondMatrix.inverse_matrix(), std::out_of_range);
}
