#include <iostream>
#include <string>

using namespace std;

void f()
{
  int i;
  cin >> i; // read an integer into i
  double d;
  cin >> d; // read a double into d
}

// you can also chain cins!
void f2()
{
  int i;
  double d;
  cin >> i >> d; // read i into d
}

void hello()
{
  cout << "Please enter your name \n";
  string str;
  cin >> str; // this will stop reading on the first non character input (such as a whitespace character)
  cout << "Hello, " << str << "!\n";
}

// to get around cin stopping reading on a whitespace character we can use getline
void hello_line()
{
  cout << "Please enter your name \n";
  string str;
  std::getline(cin, str);
  cout << "Hello, " << str << "!\n";
}

int main()
{
  f();
  f2();
  hello_line(); // this needs to be called first because of the call to "cin >>" previously, which ignores
                // whitespace so that whitespace will be picked up by the following call to "getline" and immediately
                // exit: https://stackoverflow.com/a/7787253
  hello();
}
