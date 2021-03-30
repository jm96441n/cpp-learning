#include <iostream>
#include <vector>

using namespace std;

vector<int> vec; // vec is global

struct Record {
  string name; // name is a member of Record (a string member)
};

void fct(int arg) // fct is global, a global function
                  // arg is local, an integer argument
{
  string motto {"Who dares wins"}; // motto is local
  auto p = new Record{"Hume"}; // p points to an unnamed Record created by new
  cout << motto << "\n";
  cout << p << "\n";
}

int main()
{
  fct(5);
}


