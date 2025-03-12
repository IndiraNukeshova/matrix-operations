#include <iostream>
#include <vector>
using namespace std;
class Matrix {
protected:
  int rows;
  int cols;
  vector<vector<float>> data;

public:
  Matrix(int _m, int _n) {
    rows = _m;
    cols = _n;

    data.resize(rows);
    for (int i = 0; i < rows; i++) {
      data[i].resize(cols);
    }
  }
  ~Matrix() {}
  void fillMatrix() {
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++) {
        cout << "добавить элемент в позицию [" << i << "][" << j << "]: ";
        cin >> data[i][j];
      }
  }
  virtual void print() {
    for (int i = 0; i < rows; i++) {
      cout << "["
           << " ";
      for (int j = 0; j < cols; j++) {
        cout << data[i][j] << " ";
      }
      cout << "]"
           << " ";
    }
  }
  vector<vector<int>> operator*(const Matrix &other) {
    if (cols != other.rows) {
      cout << "матрицы не могут быть перемножены" << endl;
      exit(1);
    }
    vector<vector<int>> res(rows, vector<int>(other.cols, 0));
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < other.cols; j++) {
        int sum = 0;
        for (int k = 0; k < cols; k++) {
          res[i][j] += data[i][k] * other.data[k][j];
        }
      }
    }
    return res;
  }
};

class Sqr_matrix : public Matrix {
public:
  Sqr_matrix(int _n) : Matrix(_n, _n) { int n = _n; }

  void trace() {
    for (int i = 0; i < rows; i++) {
      for (int j = i + 1; j < cols; j++) {
        swap(data[i][j], data[j][i]);
      }
    }
  }
};

class Vector : public Matrix {
public:
  Vector(int _n) : Matrix(_n, 1) { int n = _n; }

  void norm() {

    int max = data[0][0];
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (data[i][j] > max) {
          max = data[i][j];
        }
      }
    }
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        data[i][j] = data[i][j] / max;
      }
    }
  }
};
int main() {
  cout << "добавьте первую матрицу:" << endl;
  Sqr_matrix a(2);
  a.fillMatrix();

  cout << "добавьте вторую матрицу:" << endl;
  Vector b(2);
  b.fillMatrix();
  cout << endl << "first matrix:";
  a.print();
  cout << endl << "second matrix:";
  b.print();
  cout << endl << endl;
  vector<vector<int>> res = a * b;
  cout << endl << "реализация mul:    ";
  for (auto row : res) {
    cout << "[ ";
    for (auto element : row) {
      cout << element << " ";
    }
    cout << "] ";
  }
  cout << endl << "реализация print:  ";
  a.print();

  a.trace();
  cout << endl << "реализация trace:    ";
  a.print();

  b.norm();
  cout << endl << "реализация norm:    ";
  b.print();
  return 0;
}
