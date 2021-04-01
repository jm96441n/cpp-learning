#include "Vector.h"
#include <iostream>
#include <cmath>

double sqrt_sum(const Vector& v)
{
  double sum = 0;
  for (int i = 0; i != v.size(); ++i) {
    sum += std::sqrt(v[i]);
  };
  return sum;
}

int main()
{
  Vector v(3);
  v[0] = 1;
  v[1] = 2;
  v[2] = 4;
  auto val = sqrt_sum(v);
  std::cout << val << '\n';
}
