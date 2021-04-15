#include <initializer_list>
#include <list>
#include <iostream>

using namespace std;

// Class showing destructor methods
class Vector {
  public:
    Vector(int s) :elem{new double[s]}, sz{s}
    {
      for(int i = 0; i != s; ++i) // initialize elements
        elem[i] = 0;
    }
    ~Vector() { delete[] elem; }

    double& operator[](int i) { return elem[i]; };
    int size() const { return sz; };
  private:
    double* elem;
    int sz;
};

// Class showing initializing containers, more on this in chapter 5 on how to use
// move constructors to keep reads cheap
class VectorInit {
  public:
    VectorInit(initializer_list<double> lst) // initialize list of doubles
      :elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())}
    {
      copy(lst.begin(), lst.end(), elem); // copy lst into elem
    };
    void push_back(double) // add element at end increasing the size by one
    {
        // do nothing for now
    }

    ~VectorInit() { delete[] elem; }

    double& operator[](int i) { return elem[i]; };
    int size() const { return sz; };
  private:
    double* elem;
    int sz;
};


VectorInit read(istream& is)
{
  VectorInit v {};
  for (double d; is >> d;) {
    v.push_back(d);
  };
  return v;
};

// Abstract type for a Container
class Container {
  public:
    virtual double& operator[](int) = 0; // pure virtual function, the "= 0" denotes the function is pure virtual,
    // in that all classes derived from container must implement this
    virtual int size() const = 0; // const member function
    virtual ~Container () {} // destructor
};


class Vector_container : public Container { // Vector_container implements Container
  public:
    Vector_container(int s) : v(s) {} // Vector of s elements
    ~Vector_container() {} // member "v" destructor is implicitly invoked by the class destructor

    double& operator[](int i) override { return v[i]; }; // override is optional here, but it's used here to be explicit
    int size() const override { return v.size(); };
  private:
    Vector v;
};

class List_container : public Container { // List_container also implements Container
  public:
    List_container() { } // empty list
    List_container(initializer_list<double> il) : ld{il} {}
    ~List_container() {}
    double& operator[](int i) override;
    int size() const override { return ld.size(); }
  private:
    std::list<double> ld;
};

double& List_container::operator[] (int i)
{
  for (auto& x : ld)
  {
    if (i == 0) {
      return x;
    }
    --i;
  }
  throw out_of_range{"List container"};
};

void use(Container& c) {
  const int sz = c.size();

  for (int i = 0; i != sz; ++i) {
    cout << c[i] << "\n";
  }
}

void g() {
  Vector_container vc(10);

  for (int i = 0; i < 10; ++i) {
    vc[i] = i;
  }

  use(vc);
}

void h() {
  List_container lc = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  use(lc);
}

int main()
{
  g();
  cout << "\n";
  h();
}
