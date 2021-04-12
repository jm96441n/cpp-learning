#include <iostream>

using namespace std;

class complex {
  double re, im; // representation: two doubles

  public:
    complex(double r, double i) :re{r}, im{i} {}; //construct complex from two scalars
    complex(double r) :re{r}, im{0} {}; // construct complex from one scalar
    complex() :re{0}, im{0} {}; // default complex {0, 0}

    double real() const { return re; };
    void real(double d) { re = d; }
    double imag() const { return im; };
    void imag(double i) { im = i; };

    complex& operator+=(complex z)
    {
      re += z.re; // add to re and im
      im += z.im;
      return *this; // return the result
    };

    complex& operator-=(complex z)
    {
      re -= z.re; // subtract to re and im
      im -= z.im;
      return *this; // return the result
    }

  complex& operator*=(const complex z)
  {
    re *= z.re; // subtract to re and im
    im *= z.im;
    return *this; // return the result
  };

  complex& operator/=(const complex z)
  {
    re /= z.re; // subtract to re and im
    im /= z.im;
    return *this; // return the result
  };

  void print()
  {
    cout << "{ " << re << " , " << im << " }\n";
  }
};


// these do not require direct access to the representation of complex
// utilize the fact that arg is pass by copy so the arg can be modified without affecting the callers
// copy
complex operator+(complex a, complex b) { return a += b; }
complex operator-(complex a, complex b) { return a -= b; }
complex operator-(complex a) { return {-a.real(), -a.imag()}; } // unary minus
complex operator*(complex a, complex b) { return a *= b; }
complex operator/(complex a, complex b) { return a /= b; }

bool operator==(complex a, complex b) // equality
{
  return a.real() == b.real() && a.imag() == b.imag();
}

bool operator!=(complex a, complex b) // inequality
{
  return !(a == b);
}

void f(complex z)
{
  complex a {2.3}; // construct {2.3, 0.0} from 2.3
  complex b {1/a};
  complex c {a + z* complex{1, 2.3}};

  if (c != b)
    c = -(b/a) + 2 * b;

  a.print();
  b.print();
  c.print();
  z.print();
}

int main()
{
  f(complex{});
}
