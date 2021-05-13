#include <fstream>

using namespace std;

// ifstream for reading from file
// ofsrtream for writing to file
// fstream for reading/writng to a file
int main()
{
  ofstream ofs { "target" }; // "o" for "output"
  if (!ofs)
    throw("couldn't open 'target' for writing");

  ifstream ifs { "source"}; // "i" for "input"
  if (!ifs)
    throw("couldn't open 'source' for reading");
}
