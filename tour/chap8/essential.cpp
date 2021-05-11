#include <iostream>
// makes string and list available
#include<string>
#include<list>

using namespace std; // makes std names without std:: prefix
                     // dumping every name from a namespace into the global namespace is generally not a great idea


string s { "C++ is a general purpose programming language" };

int main()
{
  cout << s << endl;
}
