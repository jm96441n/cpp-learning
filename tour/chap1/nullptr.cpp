#include <iostream>

using namespace std;

int count_x(const char* p, char x)
// count the number of occurences of x in p[]
// p is assumed to be a zero-terminated arrray of char (or to nothing)
{
  if (p == nullptr) {
    return 0;
  };

  int count = 0;
  for (; *p != 0; ++p) {
    if (*p == x) {
      ++count;
    };
  };
  return count;
}

int count_with_while(const char* p, char x)
  // same as above but using while
{
  if (p == nullptr) {
    return 0;
  };

  int count = 0;
  while (*p) {
    if (*p == x) {
      ++count;
    };
    ++p;
  };
  
  return count;
}

int main()
{
  char arr[5] = "abcd";
  char find = 'c';

  auto count = count_x(arr, find);
  cout << count << endl;

  char* np = nullptr;

  auto npcount = count_x(np, find);
  cout << npcount << endl;

  count = count_with_while(arr, find);
  cout << count << endl;

  npcount = count_with_while(np, find);
  cout << npcount << endl;
}
