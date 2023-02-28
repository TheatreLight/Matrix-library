#include "../src/matrix.h"
#include "gtest/gtest.h"

TEST(constructMatrix, test1) {
  const int row = 5;
  const int col = 3;
  double first[row][col] = {
      {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  TL::Matrix firstMatrix = TL::Matrix();
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_EQ(first[i][j], firstMatrix.get_value(i, j));
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
  TL::Matrix firstMatrix = TL::Matrix(10, 10);
  EXPECT_EQ(row, firstMatrix.get_rows());
  EXPECT_EQ(col, firstMatrix.get_columns());
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_EQ(first[i][j], firstMatrix.get_value(i, j));
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
  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix result = TL::Matrix(firstMatrix);
  EXPECT_EQ(row, result.get_rows());
  EXPECT_EQ(col, result.get_columns());
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_EQ(first[i][j], result.get_value(i, j));
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
  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix result = std::move(firstMatrix);
  EXPECT_EQ(row, result.get_rows());
  EXPECT_EQ(col, result.get_columns());
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_EQ(first[i][j], result.get_value(i, j));
    }
  }
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
  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix secondMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.set_value(second[i][j], i, j);
    }
  }
  firstMatrix.SumMatrix(secondMatrix);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(third[i][j], firstMatrix.get_value(i, j), 0.0000000001);
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

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix secondMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.set_value(second[i][j], i, j);
    }
  }
  firstMatrix.SumMatrix(secondMatrix);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(third[i][j], firstMatrix.get_value(i, j), 0.0000000001);
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

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix secondMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.set_value(second[i][j], i, j);
    }
  }
  firstMatrix.SubMatrix(secondMatrix);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(firstMatrix.get_value(i, j), third[i][j], 0.0000000001);
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

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix secondMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.set_value(second[i][j], i, j);
    }
  }
  EXPECT_FALSE(firstMatrix.EqMatrix(secondMatrix));
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

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix secondMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.set_value(second[i][j], i, j);
    }
  }
  EXPECT_TRUE(firstMatrix.EqMatrix(secondMatrix));
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

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }

  firstMatrix.MulNumber(number);

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(third[i][j], firstMatrix.get_value(i, j), 0.0000000001);
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

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix secondMatrix = TL::Matrix(_row, _col);
  for (int i = 0; i < _row; i++) {
    for (int j = 0; j < _col; j++) {
      secondMatrix.set_value(second[i][j], i, j);
    }
  }
  firstMatrix.MulMatrix(secondMatrix);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < _col; j++) {
      EXPECT_EQ(third[i][j], firstMatrix.get_value(i, j));
    }
  }
}

TEST(transMatrices, test1) {
  const int row = 3;
  const int col = 3;
  double first[row][col] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
  double third[row][col] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }

  TL::Matrix result = TL::Matrix(firstMatrix.Transpose());
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_EQ(third[i][j], result.get_value(i, j));
    }
  }
}

TEST(calcCompl, test1) {
  const int row = 3;
  const int col = 3;
  double first[row][col] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
  double third[row][col] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix result = TL::Matrix(firstMatrix.CalcComplements());
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_EQ(third[i][j], result.get_value(i, j));
    }
  }
}

TEST(calcCompl, test2) {
  const int row = 2;
  const int col = 2;
  double first[row][col] = {{1, 2}, {0, 4}};
  double third[row][col] = {{4, 0}, {-2, 1}};

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix result = TL::Matrix(firstMatrix.CalcComplements());
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_EQ(third[i][j], result.get_value(i, j));
    }
  }
}

TEST(Determinant, test1) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{1, 2, 1, 4, 2},
                            {2, 1, 3, 2, 1},
                            {1, 2, 2, 2, 1},
                            {2, 1, 1, 1, 2},
                            {1, 2, 1, 2, 3}};

  double det = 21;

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  EXPECT_EQ(21, firstMatrix.Determinant());
}

TEST(Determinant, test2) {
  const int row = 2;
  const int col = 2;
  double first[row][col] = {{1, 2}, {0, 4}};

  double det = 4;

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  EXPECT_EQ(4, firstMatrix.Determinant());
}

TEST(invertMatrix, test1) {
  const int row = 3;
  const int col = 3;
  double first[row][col] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  double third[row][col] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix result = TL::Matrix(firstMatrix.InverseMatrix());
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_EQ(third[i][j], result.get_value(i, j));
    }
  }
}

TEST(invertMatrix, test2) {
  const int row = 1;
  const int col = 1;
  double first[row][col] = {{2}};
  double third[row][col] = {{0.5}};

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix result = TL::Matrix(firstMatrix.InverseMatrix());
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_EQ(third[i][j], result.get_value(i, j));
    }
  }
}

TEST(invertMatrix, test3) {
  const int row = 2;
  const int col = 2;
  double first[row][col] = {{2, -3}, {1, 1}};
  double third[row][col] = {{0.2, 0.6}, {-0.2, 0.4}};

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix result = TL::Matrix(firstMatrix.InverseMatrix());
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(third[i][j], result.get_value(i, j), 0.0000000001);
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
  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix secondMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.set_value(second[i][j], i, j);
    }
  }
  TL::Matrix result = firstMatrix + secondMatrix;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(third[i][j], result.get_value(i, j), 0.0000000001);
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

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix secondMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.set_value(second[i][j], i, j);
    }
  }
  TL::Matrix result = firstMatrix - secondMatrix;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(result.get_value(i, j), third[i][j], 0.0000000001);
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

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix secondMatrix = TL::Matrix(_row, _col);
  for (int i = 0; i < _row; i++) {
    for (int j = 0; j < _col; j++) {
      secondMatrix.set_value(second[i][j], i, j);
    }
  }
  TL::Matrix result = firstMatrix * secondMatrix;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < _col; j++) {
      EXPECT_EQ(third[i][j], result.get_value(i, j));
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
  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix secondMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.set_value(second[i][j], i, j);
    }
  }
  firstMatrix += secondMatrix;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(third[i][j], firstMatrix.get_value(i, j), 0.0000000001);
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

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix secondMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.set_value(second[i][j], i, j);
    }
  }
  firstMatrix -= secondMatrix;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(firstMatrix.get_value(i, j), third[i][j], 0.0000000001);
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

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix secondMatrix = TL::Matrix(_row, _col);
  for (int i = 0; i < _row; i++) {
    for (int j = 0; j < _col; j++) {
      secondMatrix.set_value(second[i][j], i, j);
    }
  }
  firstMatrix *= secondMatrix;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < _col; j++) {
      EXPECT_EQ(third[i][j], firstMatrix.get_value(i, j));
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

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix secondMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.set_value(second[i][j], i, j);
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

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix secondMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.set_value(second[i][j], i, j);
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

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix result = firstMatrix;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(first[i][j], result.get_value(i, j), 0.0000000001);
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

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(first[i][j], firstMatrix(i, j), 0.0000000001);
    }
  }
}

TEST(set_rows, test1) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
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
  firstMatrix.set_rows(new_row);
  for (int i = 0; i < new_row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(result[i][j], firstMatrix(i, j), 0.0000000001);
    }
  }
}

TEST(set_rows, test2) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  const int new_row = 1;
  double result[new_row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};
  firstMatrix.set_rows(new_row);
  for (int i = 0; i < new_row; i++) {
    for (int j = 0; j < col; j++) {
      EXPECT_NEAR(result[i][j], firstMatrix(i, j), 0.0000000001);
    }
  }
}

TEST(Set_columns, test1) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  const int new_col = 10;
  double result[row][new_col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111, 0, 0, 0, 0, 0},
                                 {1.1111, 2.2222, 3.3333, 2.2222, 1.1111, 0, 0, 0, 0, 0},
                                 {1.1111, 2.2222, 3.3333, 2.2222, 1.1111, 0, 0, 0, 0, 0},
                                 {1.1111, 2.2222, 3.3333, 2.2222, 1.1111, 0, 0, 0, 0, 0},
                                 {1.1111, 2.2222, 3.3333, 2.2222, 1.1111, 0, 0, 0, 0, 0}};
  firstMatrix.set_columns(new_col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < new_col; j++) {
      EXPECT_NEAR(result[i][j], firstMatrix(i, j), 0.0000000001);
    }
  }
}

TEST(Set_columns, test2) {
  const int row = 5;
  const int col = 5;
  double first[row][col] = {{1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111},
                            {1.1111, 2.2222, 3.3333, 2.2222, 1.1111}};

  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  const int new_col = 1;
  double result[row][new_col] = {{1.1111},
                                {1.1111},
                                {1.1111},
                                {1.1111},
                                {1.1111}};
  firstMatrix.set_columns(new_col);
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
  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix secondMatrix = TL::Matrix(row-1, col);
  for (int i = 0; i < row-1; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.set_value(second[i][j], i, j);
    }
  }
  EXPECT_THROW(firstMatrix.SumMatrix(secondMatrix), std::out_of_range);
}

TEST(Except, test2) {
  EXPECT_THROW(TL::Matrix(-10, 10), std::out_of_range);
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
  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix secondMatrix = TL::Matrix(row-1, col);
  for (int i = 0; i < row-1; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.set_value(second[i][j], i, j);
    }
  }
  EXPECT_THROW(firstMatrix.EqMatrix(secondMatrix), std::out_of_range);
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
  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix secondMatrix = TL::Matrix(row-1, col);
  for (int i = 0; i < row-1; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.set_value(second[i][j], i, j);
    }
  }
  EXPECT_THROW(firstMatrix.SubMatrix(secondMatrix), std::out_of_range);
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
  TL::Matrix firstMatrix = TL::Matrix(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstMatrix.set_value(first[i][j], i, j);
    }
  }
  TL::Matrix secondMatrix = TL::Matrix(row-1, col);
  for (int i = 0; i < row-1; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.set_value(second[i][j], i, j);
    }
  }
  EXPECT_THROW(firstMatrix.MulMatrix(secondMatrix), std::out_of_range);
}

TEST(Except, test6) {
  const int row = 5;
  const int col = 5;
  double second[row-1][col] = {{3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01}};
  TL::Matrix secondMatrix = TL::Matrix(row-1, col);
  for (int i = 0; i < row-1; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.set_value(second[i][j], i, j);
    }
  }
  EXPECT_THROW(secondMatrix.CalcComplements(), std::out_of_range);
}

TEST(Except, test7) {
  const int row = 5;
  const int col = 5;
  double second[row-1][col] = {{3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01}};
  TL::Matrix secondMatrix = TL::Matrix(row-1, col);
  for (int i = 0; i < row-1; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.set_value(second[i][j], i, j);
    }
  }
  EXPECT_THROW(secondMatrix.Determinant(), std::out_of_range);
}

TEST(Except, test8) {
  const int row = 5;
  const int col = 5;
  double second[row-1][col] = {{3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01},
                             {3.01, 2.01, 3.01, 2.01, 3.01}};
  TL::Matrix secondMatrix = TL::Matrix(row-1, col);
  for (int i = 0; i < row-1; i++) {
    for (int j = 0; j < col; j++) {
      secondMatrix.set_value(second[i][j], i, j);
    }
  }
  EXPECT_THROW(secondMatrix.InverseMatrix(), std::out_of_range);
}
