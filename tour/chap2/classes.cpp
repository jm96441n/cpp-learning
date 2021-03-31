#include <iostream>

using namespace std;

class Vector {
  public:
    Vector(int s) :elem{new double[s]}, sz{s} { };// constructor for vector
    double& operator[](int i) { return elem[i]; } // element access subscripting
    int size() { return sz; }
  private:
    double *elem;
    int sz;
};

double read_and_sum(int s)
{
  Vector v(s);

  for (int i = 0; i < s; i++) {
    cin >> v[i];
  };

  double sum = 0;
  for (int i = 0; i < s; i++) {
    sum += v[i];
  };

  return sum;
}

int main()
{
  auto s = read_and_sum(3);
  cout << s << "\n";
}
