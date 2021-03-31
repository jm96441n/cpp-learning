#include <iostream>
#include <variant>

using namespace std;

enum Type { ptr, num }; // a Type can hold values ptr and num;

struct Node {
  Node* next;
};

// the below wastes space as it needs to allocate space for both Node p
// and int i even though their use is mutually exclusive
/*
struct Entry {
  string name; // string is a standard lib type
  Type t;
  Node* p; // use p if t == ptr
  int i; // use i if t == num
};
*/

union Value {
  Node* p;
  int i;
};

// Now we only allocate space for the larger of Node* or int, though we
// still have to check the type of "t" prior to access
// though using the union can be error prone as we have to check the type
// each time
/*
struct Entry {
  string name;
  Type t;
  Value v;
};
*/

struct Entry {
  string name;
  variant<Node*,int> v;
};

void f(Entry* pe)
{
  if(holds_alternative<int>(pe->v)) {
    cout << get<int>(pe->v);
  };
}

int main()
{

}
