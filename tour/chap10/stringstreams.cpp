#include <sstream>
#include <iostream>

using namespace std;

void test()
{
  ostringstream oss;
  oss << "{temperature," << scientific << 123.4567890 << "}";
  cout << oss.str() << endl;
}

template<typename Target =string, typename Source =string>
Target to(Source arg)
{
  stringstream interpreter;
  Target result;

  if (!(interpreter << arg)           // write are into stream
    || !(interpreter >> result)        // read result from stream
    || !(interpreter >> std::ws).eof()) // stuff left in stream?
    throw runtime_error("to<>() failed");

  return result;
}

int main()
{
  test();
  auto x1 = to<string, double>(1.2); // very explicit and verbose
  cout << "x1: " << x1 << endl;

  auto x2 = to<string>(1.2);        // source is defaulted to double
  cout << "x2: " << x2 << endl;

  auto x3 = to<>(1.2);              // target is default to string; source defaulted to double 
  cout << "x3: " << x3 << endl;

  auto x4 = to(1.2);               // the <> is redundant; target defaults to string; source defaults to double
  cout << "x4: " << x4 << endl;
}
