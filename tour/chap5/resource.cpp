#include <iostream>
#include <thread>
#include <vector>

using namespace std;

class Vector {
  public:
    Vector(int s) // initialize list of doubles
      :elem{new double[s]}, sz{s} {};

    ~Vector() { delete[] elem; }

    Vector(const Vector& a) // copy constructor
      :elem{new double[a.sz]}, sz{a.sz}
    {
      // safe copy constructor as we copy all the elements into the 
      // new elem rather than just copying the pointer
      for(int i = 0; i < sz; ++i)
        elem[i] = a.elem[i];
    }
    Vector& operator=(const Vector& a) // copy assignment
    {
      double* p = new double[a.sz];
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

    double& operator[](int i) { return elem[i]; };
    int size() const { return sz; };
  private:
    double* elem;
    int sz;
};

void heartbeat() {
  cout << "heartbeat" << endl;
};

vector<thread> my_threads;

Vector init(int n)
{
  thread t {heartbeat};
  my_threads.push_back(move(t));
  Vector vec(n);
  for (int i = 0; i < n; ++i)
    vec[i] = 777;
  return vec; // move
}

int main()
{
  auto v = init(1'000'000);
}
