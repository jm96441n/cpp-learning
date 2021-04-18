#include <iostream>

using namespace std;

// Class with move semantics
class VectorMove {
  public:
    VectorMove(int s) // initialize list of doubles
      :elem{new double[s]}, sz{s} {};

    ~VectorMove() { delete[] elem; }

    VectorMove(const VectorMove& a) // copy constructor
      :elem{new double[a.sz]}, sz{a.sz}
    {
      // safe copy constructor as we copy all the elements into the 
      // new elem rather than just copying the pointer
      for(int i = 0; i < sz; ++i)
        elem[i] = a.elem[i];
    }
    VectorMove& operator=(const VectorMove& a) // copy assignment
    {
      double* p = new double[a.sz];
      for (int i = 0; i < a.sz; ++i)
        p[i] = a.elem[i];
      delete[] elem; // remove old entry for elements
      elem = p;
      sz = a.sz;
      return *this;
    }

    VectorMove(VectorMove&& a) // move constructor
      :elem{a.elem}, sz{a.sz}
    {
      a.elem = nullptr;
      a.sz = 0;
    }

    VectorMove& operator=(VectorMove&& a) // move assignment
    {
      elem = a.elem;
      sz = a.sz;
      a.elem = nullptr;
      a.sz = 0;
      return *this;
    }

    double& operator[](int i) { return elem[i]; };
    int size() const { return sz; };
  private:
    double* elem;
    int sz;
};

VectorMove f()
{
  VectorMove x = VectorMove(1000); 
  VectorMove y = VectorMove(2000); 
  VectorMove z = VectorMove(3000); 
  z = x; // we get a copy, x might be used later in f()
  y = move(x); // here we get a move using move assignment
  // do not use x now!
  return z; // here we get a move
}

int main()
{
  f();
}
