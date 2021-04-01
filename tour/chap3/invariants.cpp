#include "Vector.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void test()
{
  try {
    Vector v(-27);
  }
  catch (length_error& err) {
    cerr << err.what() << '\n';
    throw;
  }
  catch (bad_alloc& err) {
    cerr << err.what() << '\n';
    throw;
  }
}

int main()
{
  test();
  return 0;
}
