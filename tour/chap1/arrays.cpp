#include <iostream>

using namespace std;

char v[6]; // array of length 6 of chars
char *p; // pointer to a character

void copy_fct(const int src[], int dest[])
{
  for(auto i = 0; i < 10; i++) {
    dest[i] = src[i];
  }
}

void print(const int a[])
{
  for (auto i = 0; i < 10; i++) {
    cout << a[i] << "\n";
  }
}

void better_print(const int (&a)[10]) // can use templates here instead of the statically defined "10" but more on that later
{
  for(auto x : a) {
    cout << x << '\n';
  }
}

void inc_by_ref(int (&a)[10])
{
  for(auto& x : a) {
    ++x;
  }
}

int main()
{
  int src[10] = {0,1,2,3,4,5,6,7,8,9};
  int dest[10];
  copy_fct(src, dest);
  print(dest);
  cout << '\n';
  better_print(dest);
  cout << '\n';
  inc_by_ref(dest);
  better_print(dest);
}
