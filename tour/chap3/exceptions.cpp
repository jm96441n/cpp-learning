#include "Vector.h"
#include <stdexcept>
#include <iostream>

using namespace std;

void f(Vector& v)
{
  try {
    v[v.size()] = 7; // try to access beyond v
  }
  catch (out_of_range& err) {
    cerr << err.what() << '\n';
  }
}

int main()
{
  Vector v(6);
  f(v);
  return 0;
}
