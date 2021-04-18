#include <iostream>
#include <complex>

using namespace std;

struct SomeType {};

// constructors/destructors
class X {
  X(SomeType); // ordinary constructor: create an object
  X(); // default constructor
  X(const X&); // copy constructor
  X(const X&&); // move constructor
  X& operator=(const X&); // copy assignment: clean up target and copy
  X& operator=(X&&); // move assignment: clean up target and move
  ~X(); // destructor: clean up
};

// we can use =delete to indicate an operation is not to be generated
class Shape {
  public:
      Shape(const Shape&) =delete; // non copy operations
      Shape& operator=(const Shape&) =delete;
};

// make a constructor explicit to disable conversion
class Vector {
  public:
    explicit Vector(int s) :elem{new double[s]}, sz{s} {};
    Vector() :elem{new double[0]}, sz{0} {};
  private:
      double* elem;
      int sz;
};

// rule of thumb: define all essential operators or none
struct Z {
  Vector v;
  string s;
};

int main()
{
  Z z1; // default initialize z1.v and z1.s
  Z z2 = z1; // default copy z1.v and z1.s

  // constructor taking a single argument defines a conversion from it's argument type
  complex<double> c1 = 3.14; // z1 becomes {3.14, 0.0}
  complex<double> c2 = c1*2.0; // z2 becomes c1 * {2.0, 0.0} == {6.28, 0}

 // Vector v1 = 7; // NOT OK: v1 has 7 elements
  Vector v1 = Vector(7); // NOT OK: v1 has 7 elements
}
