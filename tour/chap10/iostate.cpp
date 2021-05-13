#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> read_ints(istream& is)
{
  vector<int> res;
  for (int i; is >> i;)
    res.push_back(i);
  return res;
}

// we can check certain state of the iostream to see if an error has occurred or
// if we just want to keep reading until we hit a certain end string
vector<int> read_ints2(istream& is, const string& terminator)
{
  vector<int> res;
  for (int i; is >> i;)
    res.push_back(i);

  if (is.eof()) // hit: end of file
    return res;

  if (is.fail()) { // we failed to read an int, check if it was the terminator
    is.clear(); // reset the state to "good()"
    is.unget(); // put the non-digit back into the stream
    string s;
    if (cin >> s && s == terminator) // re-read out of the stream and compare to base value
      return res;
    cin.setstate(ios_base::failbit); // add fail() to cin's state
  }
  return res;
}

int main()
{
  auto v = read_ints2(cin, "stop");
  for(auto p : v)
    cout << p << ", ";

}
