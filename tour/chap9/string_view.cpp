#include <string>
#include <iostream>
#include <string_view>

using namespace std::literals::string_view_literals;

std::string cat(std::string_view sv1, std::string_view sv2)
{
  std::string res {sv1}; // initialize from sv1
  res += sv2; // append from sv2 and return
  std::cout << res << std::endl;
  return res;
}

void print_lower(std::string_view sv1)
{
  for(char ch : sv1)
    std::cout << tolower(ch);
}

int main()
{
  std::string king = "Harold";
  auto s1 = cat(king, "Willian"); // string and const char*
  auto s2 = cat(king, king); // string and string
  auto s3 = cat("Edward", "Stephen"sv); // const char * and string_view
  auto s4 = cat("Canute"sv, king); // string_view and string
  auto s5 = cat({&king[0],2}, "Henry"sv); // HaHenry
  auto s6 = cat({&king[0], 2}, {&king[2], 4}); // Harold

  std::cout << std::endl;

  print_lower(king);
}
