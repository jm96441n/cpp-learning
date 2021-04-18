#include <iostream>

using namespace std;

// Class with only copy semantics
class VectorCopy {
  public:
    VectorCopy(int s) // initialize list of doubles
      :elem{new double[s]}, sz{s} {};
    ~VectorCopy() { delete[] elem; }
    VectorCopy(const VectorCopy& a) =default; // copy constructor
    VectorCopy& operator=(const VectorCopy& a) =default; // copy assignment

    double& operator[](int i) { return elem[i]; };
    int size() const { return sz; };
  private:
    double* elem;
    int sz;
};

// Class with only copy semantics
class VectorSafeCopy {
  public:
    VectorSafeCopy(int s) // initialize list of doubles
      :elem{new double[s]}, sz{s} {};
    ~VectorSafeCopy() { delete[] elem; }
    VectorSafeCopy(const VectorSafeCopy& a) // copy constructor
      :elem{new double[a.sz]}, sz{a.sz}
    {
      // safe copy constructor as we copy all the elements into the 
      // new elem rather than just copying the pointer
      for(int i = 0; i < sz; ++i)
        elem[i] = a.elem[i];
    }
    VectorSafeCopy& operator=(const VectorSafeCopy& a) // copy assignment
    {
      double* p = new double[a.sz];
      for (int i = 0; i < a.sz; ++i)
        p[i] = a.elem[i];
      delete[] elem; // remove old entry for elements
      elem = p;
      sz = a.sz;
      return *this;
    }

    double& operator[](int i) { return elem[i]; };
    int size() const { return sz; };
  private:
    double* elem;
    int sz;
};

void bad_copy(VectorCopy v1)
{
  cout << "Bad Copy" << endl;
  VectorCopy v2 = v1; // copy v1's representation into v2
  v1[0] = 2; // now v2[0] is also 2!
  v2[1] = 3; // v1[2] is also 3!
  // Vector has a destructor is a strong hint that copy semantics are not what we want here
  cout << "v1[0]: " << v1[0] << ", v2[0]: " << v2[0] << endl;
  cout << "v1[1]: " << v1[1] << ", v2[1]: " << v2[1] << endl;
}

void safe_copy(VectorSafeCopy v1)
{
  cout << "Safe Copy" << endl;
  VectorSafeCopy v2 = v1; // copy v1's representation into v2
  v1[0] = 2; // only v1[0] is 2!
  v2[1] = 3; // only v2[2] is 3!
  cout << "v1[0]: " << v1[0] << ", v2[0]: " << v2[0] << endl;
  cout << "v1[1]: " << v1[1] << ", v2[1]: " << v2[1] << endl;
}

int main()
{
  VectorSafeCopy v2 = VectorSafeCopy(5);
  safe_copy(v2);
  cout << endl;
  VectorCopy v1 = VectorCopy(5);
  bad_copy(v1);
}
