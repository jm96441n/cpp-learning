#include <iostream>

using namespace std;

bool accept()
{
  cout << "Do you want to proceed (y or n)\n";
  char answer = 0;
  cin >> answer;
  switch (answer) {
    case 'y':
      return true;
    case 'n':
      return false;
    default:
      cout << "I'll take that for a no.\n";
      return false;
  }
}

int main()
{
  auto uin = accept();
  if (uin) {
    cout << "Good! You've accepted\n";
    return 0;
  }

  cout << "Why not!? You should've accepted\n";
}
