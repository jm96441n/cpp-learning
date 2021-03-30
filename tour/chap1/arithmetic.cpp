#include <iostream>

using namespace std;

void print(int d)
{
  cout << d << "\n";
}

int main()
{
  int x = 1;
  int y = 5;

  print(x + y);
  print(+x);
  print(-x);
  print(x - y);
  print(x * y);
  print(x / y);
  print(x % y);
}
