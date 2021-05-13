#include <iostream>

using namespace std;

struct Entry {
  string name;
  int number;
};

// define output using a {"name", number} format for Entry
ostream& operator<<(ostream& os, const Entry& e)
{
  return os << "{\"" << e.name << "\", " << e.number << "}";
}

// defining input is a bit more difficult because we have to check for formatting and deal with errors
istream& operator>>(istream& is, Entry& e)
// read { "name", number } pair. Note: formatted with { " ", and }
{
  char c, c2;
  if (is >> c && c == '{' && is >> c2 && c2 == '"') { // start with { followed by a "
    string name; // the default value of a string is the empty string ""
    while (is.get(c) && c!='"') // anything before the closing " is part of the name
      name += c;

    if (is >> c && c==',') {
      int number = 0;
      if (is >> number >> c && c == '}') { // read the number and a }
        e = {name, number}; // assign to the entry
        return is;
      }
    }
  }
  is.setstate(ios_base::failbit); // register failure due to formatting
  return is;
}

int main()
{
  Entry e = Entry { "hello", 2 };
  cout << e << endl;

  for(Entry ee; cin >> ee;) // read from cin into ee
    cout << ee << endl; // write ee to cout
}
