#include <iostream>
#include <vector>

using namespace std;

class Matrix {
  public:
    Matrix(const int x, const int y) 
    {
      data = vector<vector<int>>(x, vector<int>(y, 0));
    };
    void print() {
      for (auto row : data) {
        for (auto col : row) {
          cout << col << " ";
        }
        cout << endl;
      }
    }
  private:
     vector<vector<int>> data;
};

int main()
{
  auto m = Matrix(5, 6);
  m.print();
}
