#include <iostream>
#include <vector>
#include <list>
#include <complex>
#include "Vector.h"

using namespace std;

// function template
template<typename Sequence, typename Value>
Value sum(const Sequence& s, Value v)
{
  for (auto x : s)
    v += x;
  return v;
}

void user(Vector<int>& vi, list<double>& ld, vector<complex<double>>& vc)
{
  int x = sum(vi, 0);
  double d = sum(vi, 0.0);
  double dd = sum(ld, 0.0);
  auto z = sum(vc, complex{0.0, 0.0});
  cout << x << endl;
  cout << d << endl;
  cout << dd << endl;
  cout << z << endl;
}

// function objects (aka functors) can be used to define objects that can be called like functions
template <typename T>
class Less_than {
  const T val; // value to compare against
  public:
    Less_than(const T& v) :val{v} { }
    bool operator()(const T& x) const { return x < val; } // call operator
};

void fct(int n, const string &s)
{

  Less_than lti {42}; // lti(i) will compare i to 42 using < (i < 42);
  Less_than lts {"Backus"s}; // lts(s) will compare s to "Backus" using < (s < "Backus"s)
  Less_than<string> lts2 {"Naur"}; // "Naur" is a C style string to so we need to explicitly declare the template type
  cout << lti(n) << endl;
  cout << lts(s) << endl;
  cout << lts2(s) << endl;
}

// functors are useful for predicates (something we invoke that returns a boolean
template<typename C, typename P>
  // requires Sequence<C> && Callable<P, Value_type<P>>
int count(const C& c, P pred)
{
  int cnt = 0;
  for (const auto& x : c)
    if (pred(x))
      ++cnt;
  return cnt;
}

void cmp(const Vector<int>& vec, const list<string>& lst, int x, const string& s)
{
  cout << "number of values less than " << x << ": " << count(vec, Less_than{x}) << endl;
  cout << "number of values less than " << s << ": " << count(lst, Less_than{s}) << endl;
}

void lambda_cmp(const Vector<int>& vec, const list<string>& lst, int x, const string& s)
{
  cout << "number of values less than " << x << ": " << count(vec, [&](int a){ return a < x; }) << endl;
  cout << "number of values less than " << s << ": " << count(lst, [&](const string& a){ return a < s;}) << endl;
}

int main()
{
  auto vi = Vector<int>(5);
  auto ld = list<double>(6);
  auto vc = vector<complex<double>>(7);
  user(vi, ld, vc);

  // fun with functors
  fct(42, "General Kenobi");

  Vector<int> v = Vector<int>(50);
  for(int i = 0; i < v.size(); ++i)
    v[i] = i + 30;
  list<string> l {"hello", "there", "general", "kenobi", "I", "have", "the", "high", "ground" };

  cmp(v, l, 42, "General Kenobi");
  lambda_cmp(v, l, 42, "General Kenobi");
}
