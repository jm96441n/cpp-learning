#include <iostream>
#include <cmath>

namespace My_code {
  class complex {
    public:
      complex(double r, double s);
      double real();
      double imag();
    private:
      double r;
      double s;
  };

  complex::complex(double r, double s)
    :r{r}, s{s}
  {
  }

  double complex::real()
  {
    return r;
  }

  double complex::imag()
  {
    return s;
  }

  complex sqrt(complex c) {
    auto r = std::sqrt(c.real());
    auto s = std::sqrt(c.imag());
    complex nc {r, s};
    return nc;
  }

  int main();
}

int My_code::main()
{
  complex z {1, 2};
  auto z2 = sqrt(z);
  std::cout << '{' << z2.real() << ',' << z2.imag() << "}\n";
  return 0;
}

int main()
{
  return My_code::main();
}
