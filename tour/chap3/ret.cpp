#include <iostream>
#include <vector>

using namespace std;

class Matrix {
  private:
     vector<vector<int>> data;
  public:
    Matrix(const int x, const int y) 
      :data {vector<vector<int>>(x, vector<int>(y, 0))} { };

    vector<int>& operator[](int i) {
      return data[i];
    }


    void print() {
      for (auto row : data) {
        for (auto col : row) {
          cout << col << " ";
        }
        cout << endl;
      }
    }
};

Matrix operator+(Matrix& x, Matrix& y) {
  auto res = Matrix(5, 6);
  for (int i = 0; i < 5; ++i) {
    auto r1 = x[i];
    auto r2 = y[i];
    for(int j = 0; j < 6; j++) {
      res[i][j] = x[i][j] + y[i][j];
    }
  }
  return res;
}

int main()
{
  auto m1 = Matrix(5, 6);
  for (int i = 0; i < 5; ++i) {
    for(int j = 0; j < 6; ++j) {
      m1[i][j] = i + j;
    }
  }
  m1.print();
  cout << endl;
  auto m2 = Matrix(5, 6);

  for (int i = 0; i < 5; ++i) {
    for(int j = 0; j < 6; ++j) {
      m2[i][j] = i * j;
    }
  }
  m2.print();
  cout << endl;
  auto m3 = m1+m2;
  m3.print();
}
