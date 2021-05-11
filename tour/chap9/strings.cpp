#include <iostream>
#include <string>

using namespace std;

string compose(const string& name, const string& domain)
{
  return name + '@' + domain;
}

void m2(string& s1, string& s2)
{
  s1 = s1 + '\n'; // append newline
  s2 += '\n'; // append newline
}

void m3(string& name, string& replacement)
{
  string s = name.substr(6, 10); // get substring by index
  cout << s << endl;
  name.replace(0,5,replacement); // replace base on index
  cout << name << endl;
  name[0] = toupper(name[0]); // capitalize the first character of the string
  cout << name << endl;
}

void respond(const string& incantation, const string& answer)
{
  if (answer == incantation) {
    cout << "You can do maaaaagic" << endl;
  } else if (answer == "yes") {
    cout << "You can do anything" << endl;
  }
}

void print(const string&s)
{
  printf("For people who like printf: %s\n", s.c_str()); //s.ctr() returns a pointer to s' characters
  cout << "For people who like streams: " << s << endl;
}

int main()
{
  auto addr = compose("dmr", "bell-labs.com");
  cout << addr << endl;
  cout << endl;

  string s1  = "hello there";
  string s2 = "general kenobi";
  cout << s1 << s2 << endl;

  cout << endl;
  m2(s1, s2);
  cout << "After newline append" << endl;
  cout << s1 << s2 << endl;

  auto name = "Niels Stroustrup"s;
  auto replacer = "nicholas"s;

  m3(name, replacer);

  cout << endl;

  auto incant = "pizza time"s;
  auto answer = "pizza time"s;

  print("This is where the fun starts");
}
