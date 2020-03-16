#include <iostream>
#include <vector>

using vector2d = std::vector<std::vector<int>>;
using vector = std::vector<int>;

class Matrix {
private:
  vector2d data;
  int rows;
  int cols;

public:
  Matrix() {
    data = vector2d(0, vector(0, 0));
    rows = 0;
    cols = 0;
  }

  Matrix(int num_rows, int num_cols) {
    if (num_rows < 0 or num_cols < 0) {
      throw std::out_of_range("");
    }
    data = vector2d(num_rows, vector(num_cols, 0));
    rows = num_rows;
    cols = num_cols;
  }

  void Reset(int num_rows, int num_cols) {
    if (num_rows < 0 or num_cols < 0) {
      throw std::out_of_range("");
    }
    data = vector2d(num_rows, vector(num_cols, 0));
    rows = num_rows;
    cols = num_cols;
  }

  int At(int row, int col) const {
    if (row >= GetNumRows() or col >= GetNumColumns() or row < 0 or col < 0) {
      throw std::out_of_range("");
    }
    return data[row][col];
  }
  int &At(int row, int col) {
    if (row >= GetNumRows() or col >= GetNumColumns() or row < 0 or col < 0) {
      throw std::out_of_range("");
    }
    return data[row][col];
  }
  int GetNumRows() const { return rows; }
  int GetNumColumns() const { return cols; }
  bool is_empty() const {
    if (rows == 0 or cols == 0) {
      return true;
    }
    return false;
  }
};

std::istream &operator>>(std::istream &stream, Matrix &m) {
  int num_rows = 0, num_cols = 0;
  stream >> num_rows >> num_cols;
  m.Reset(num_rows, num_cols);
  for (int i = 0; i < num_rows; ++i) {
    for (int j = 0; j < num_cols; ++j) {
      stream >> m.At(i, j);
    }
  }
  return stream;
}

std::ostream &operator<<(std::ostream &stream, const Matrix &m) {
  int num_rows = m.GetNumRows(), num_cols = m.GetNumColumns();
  stream << num_rows << " " << num_cols << std::endl;
  for (int i = 0; i < num_rows; ++i) {
    for (int j = 0; j < num_cols; ++j) {
      stream << m.At(i, j) << " ";
    }
    if (i != num_rows - 1) {
      stream << std::endl;
    }
  }
  return stream;
}

bool operator==(const Matrix &lhs, const Matrix &rhs) {
  if (lhs.is_empty() and rhs.is_empty()) {
    return true;
  }
  if (lhs.GetNumRows() != rhs.GetNumRows() or
      lhs.GetNumColumns() != rhs.GetNumColumns()) {
    return false;
  }
  int n = lhs.GetNumRows(), m = lhs.GetNumColumns();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (lhs.At(i, j) != rhs.At(i, j)) {
        return false;
      }
    }
  }
  return true;
}
Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
  if (lhs.is_empty() and rhs.is_empty()) {
    return Matrix();
  }
  if (lhs.GetNumRows() != rhs.GetNumRows() or
      lhs.GetNumColumns() != rhs.GetNumColumns()) {
    throw std::invalid_argument("");
  }
  int n = lhs.GetNumRows(), m = lhs.GetNumColumns();
  Matrix result{n, m};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      result.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
    }
  }
  return result;
}

// int main() {
//   Matrix one;
//   one.At(0, 0);

//   return 0;
// }