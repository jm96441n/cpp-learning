#include <iostream> // include ("import") the declaration for the I/O stream lib

using namespace std; // makes names from std visible without std::

double square(double x)
{
  return x * x;
}

void print_square(double x)
{
  cout << "the square of " << x << " is " << square(x) << "\n";
}

int main()
{
  print_square(1.234); // print: the square of 1.234 is 1.52276
}
