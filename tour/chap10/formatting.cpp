#include <iostream>

using namespace std;

int main()
{
  constexpr double d = 123.456;
  cout << d <<"; " // use default format for d
    << scientific << d << "; " // use 1.23r2 style for d
    << hexfloat << d << "; " // use hexdecimal style for d
    << defaultfloat << d << "\n"; // use the default format for d
}
