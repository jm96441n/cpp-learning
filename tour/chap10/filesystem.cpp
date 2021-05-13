#include <filesystem>
#include <iostream>
#include <cassert>

using namespace std;

void fileinfo(filesystem::path f)
{
  assert(exists(f)); // file must exist

  if (is_regular_file(f)) // is f an ordinary file
    cout << f << " is a file; its size is " << file_size(f) << endl;
}

void use(path p)
{
  ostream f {p};
  if (!f) error("bad file name: ", p);
  f << "Hello, file!";
}

int main(int argc, char* argv[])
{
  filesystem::path f = "./filestreams.cpp";

  fileinfo(f);

  if (argc < 2) {
    cerr << "arguments expected\n";
    return 1;
  }

  filesystem::path p {argv[1]}; // create path from command line

  cout << p << " " << exists(p) << endl; // note: a path can printed like a string
}
