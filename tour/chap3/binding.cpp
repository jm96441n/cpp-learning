#include <iostream>
#include <map>
#include <complex>

using namespace std;

struct Entry {
  string name;
  int value;
};

Entry read_entry(istream& is) // naive read function
// takes input from STDIN and packs it into an Entry struct
{
  string s;
  int i;
  is >> s >> i;
  return {s, i};
}

void incr(map<string, int>& m) // increment the value of each element m
{
  for (auto& [key, value] : m) {
    ++value;
  }
}

int main()
{
  auto e = read_entry(cin);

  cout << "{ " << e.name << " , " << e.value << " }\n";

  // unpack from struct
  auto [n, v] = read_entry(cin);
  cout << "{ " << n << " , " << v << " }\n";

  // another examplem using maps
  map<string, int> m;
  m["hello"] = 5;
  m["there"] = 6;
  m["general"] = 7;
  m["kenobi"] = 8;
  for (const auto [key, value] : m) {
    cout << "{ " << key << " , " << value << " }\n";
  }

  incr(m);
  cout << "\nIncremented values in map\n\n";

  for (const auto [key, value] : m) {
    cout << "{ " << key << " , " << value << " }\n";
  }


  complex<double> z = {1.0, 2.0};
  auto [real, imag] = z + 2.0;

  cout << "{ " << real << " , " << imag << " }\n";
}
