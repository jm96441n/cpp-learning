#include <iostream>
#include <vector>

using namespace std;

int sum(const vector<int>& v)
{
  int s = 0;
  for (const int i : v) {
    s += i;
  }
  return s;
}

// arg passing
void test(vector<int> v, vector<int>& rv)
{
  v[1] = 99; // modify the local variable v
  rv[2] = 66; // modify what rv refers to
}

// using a default value
void print(int value, int base =10) {
  cout << "Value: " << value << ' ' << "base: " << base << "\n";
}

int main()
{
  vector fib = {1,1,2,3,5,8,13,21};
  int x = sum(fib);
  cout << "fib sum: " << x << "\n\n";

  test(fib, fib);
  cout << fib[1] << ' ' << fib[2] << "\n\n"; // prints 1 66

  x = 5;
  print(x, 16);
  print(x, 60);
  print(x);
}
