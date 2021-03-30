#include <iostream>
#include <vector>

using namespace std;

constexpr int dmv = 17; // dmv is a named constant evaluated at compile time

int var = 17; // var is not a constant
const double sqv = sqrt(var); // sqv is a named constant, possible computed at run time

double sum(const vector<double>& vec)  // sum will not modify it's argument
{
  double s = 0;
  for (int i = 0; i < vec.size(); i++) {
    s += vec[i]; 
  }
  return s;
};

vector<double> v = {1.2, 3.4, 4.5}; // v is not a constant

const double s1 = sum(v); //  OK: sum(v) is evaluated at runtime

// constexpr double s2 = sum(v); // error: sum(v) is not a constant expression

// For a function to be usable ina  constant expression it must be defined constexpr

constexpr double square(double x) { return x * x; }

constexpr double max1 = 1.4 * square(17); // OK: 1.4*square(17) is a constant expression
// constexpr double max2 = 1.4 * square(var); // error: var is not a constant expression
const double max3 = 1.4 * square(var); // OK, may be evaluated at runtime

constexpr double nth(double x, int n)
{
  double res = 1;
  int i = 0;
  while (i < n) {
    res *= x;
    cout << res << "\n";
     ++i; 
  }
  return res;
}

int main()
{
  auto res = nth(10, 5);
  cout << res << "\n";
}
