#include <iostream>

using namespace std;

void print(int);
void print(double);
void print(string);


void print(int x)
{
  cout << "Printing int: " << x << "\n";
}

void print(double d)
{
  cout << "Printing double: " << d << "\n";
}

void print(string s)
{
  cout << "Printing string: " << s << "\n";
}

void user()
{
  print(42);
  print(9.65);
  print("Barcelona");
}

int main()
{
  user();
}
