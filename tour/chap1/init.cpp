#include <iostream>
#include <complex>
#include <vector>

using namespace std;

int main()
{
  double d1 = 2.3;
  double d2 {2.3}; // the same as using the assignment operator "="
  double d3 = {2.3};
  complex<double> z = 1;
  complex<double> z2 {d1, d2};
  complex<double> z3 = {d1, d2};

  vector<int> v {1, 2, 3, 4, 5, 6};
}
