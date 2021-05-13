#include <iostream>

using namespace std;

// both f and g do the same thing
void f()
{
  cout << 10 << endl;
}

void g()
{
  int x { 10 };
  cout << x << endl;
}

// h shows how we can combine different types into the output byte stream
void h(int i)
{
  cout << "the value of i is ";
  cout << i;
  cout << endl;
}

// we can just keep shovelling to the same output!
void h2(int i)
{
  cout << "the value of i is " << i << endl;
}

void k()
{
  int b = 'b'; // note: char is implicitly converted to an int here
  char c = 'c';
  cout << 'a' << b << c << endl;
}

void output_w_cout()
{
  f();
  g();
  h(5);
  h2(10);
  k();
}



int main()
{
  output_w_cout();
}
