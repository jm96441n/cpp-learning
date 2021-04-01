#include <iostream>

using namespace std;

double sqrt(double);

class Vector {
  public:
    Vector (int s);
    double& operator[](int i);
    int size();
  private:
    double* elem;
    int sz;
};


double sqrt(double d) // defintiion of sqrt
{
  // do something to find the sqrt
  return 2;
}

// define all the vector functions
Vector::Vector(int s)
  :elem{new double[s]}, sz{s}
{

}

double& Vector::operator[](int i)
{
  return elem[i];
}

int Vector::size()
{
  return sz;
}
  
