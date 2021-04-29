#include <list>
#include <iostream>

using namespace std;
template<typename T>
class Vector {
  public:
    Vector<T>(int s) // initialize list of T
    {
      if (s < 0)
        throw length_error{"Vector param must be greater than 0"};
      elem =  new T[s];
      sz = s;
    };

    ~Vector<T>() { delete[] elem; }

    Vector(const Vector& a) // copy constructor
      :elem{new T[a.sz]}, sz{a.sz}
    {
      // safe copy constructor as we copy all the elements into the 
      // new elem rather than just copying the pointer
      for(int i = 0; i < sz; ++i)
        elem[i] = a.elem[i];
    }
    Vector& operator=(const Vector& a) // copy assignment
    {
      T* p = new T[a.sz];
      for (int i = 0; i < a.sz; ++i)
        p[i] = a.elem[i];
      delete[] elem; // remove old entry for elements
      elem = p;
      sz = a.sz;
      return *this;
    }

    Vector(Vector&& a) // move constructor
      :elem{a.elem}, sz{a.sz}
    {
      a.elem = nullptr;
      a.sz = 0;
    }

    Vector& operator=(Vector&& a) // move assignment
    {
      elem = a.elem;
      sz = a.sz;
      a.elem = nullptr;
      a.sz = 0;
      return *this;
    }

    T& operator[](int i)
    {
      if (i < 0 || size() <= i)
        throw out_of_range{"Vector::operator[]"};
      return elem[i]; 
    };

    int size() const { return sz; };

    // "begin" and "end" functions permit use of (for auto x : p) where x is a Vector<T>
    T* begin() const
    {
      return size() ? &elem[0] : nullptr; // pointer to first element or nullptr
    }

    T* end() const
    {
      return size() ? &elem[0] + size() : nullptr; // pointer to one past last element or nullptr
    }
  private:
    T* elem;
    int sz;
};
