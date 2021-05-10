#include <iostream>
#include <vector>

using namespace std;

void print()
{
  // what we do for no arguments: nothing
}

// traditionally we implement the first arg and then recursively call for the rest
template<typename T, typename ... Tail>
void print(T head, Tail... tail)
{
  // what we do for each argument
  cout << head << " ";
  print(tail...);
}

// the previous forces us to define an empty arg case, we can do better!
template<typename T, typename ... Tail>
void better_print(T head, Tail... tail)
{
  cout << head << " ";
  // use compile time print here rather than a plain runtime if to prevent empty if statements from being generated
  if constexpr(sizeof...(tail) > 0)
    better_print(tail...);
}

// let's look at some folds!
template <typename... Number>
int sum_right_fold(Number... v)
{
  return (v + ... + 0); // add all elements of v from highet value, starting with 0
  // this works by doing (v[0] + (v[1] + (v[2] + (v[3] + (v[4] + 0)))))
}

template <typename... Number>
int sum_left_fold(Number... v)
{
  return (0 + ... + v); // add all elements of v from lowest value, starting with 0
  // this works by doing (v[4] + (v[3] + (v[2] + (v[1] + (v[0] + 0)))))
}

template<typename ...T>
void fold_print(T&&... args)
{
  (cout << ... << args) << endl; // print all the args
}

template<typename Res, typename... Ts>
vector<Res> to_vector(Ts&&... ts)
{
  vector<Res> res;
  (res.push_back(ts), ...); // no initial val needed
  return res;
}

int main()
{
  print("hello", 1, 2.2, "hello\n"s);
  print("General", "Kenobi", "Order", 66, "\n");
  cout << "Using better print now" << endl << endl;

  better_print("hello", 1, 2.2, "hello\n"s);
  better_print("General", "Kenobi", "Order", 66, "\n");

  cout << endl << endl << endl;

  auto d = sum_right_fold(1, 2, 3, 4, 5);
  cout << d << endl;
  auto s = sum_right_fold('a', 'b', 'c');
  cout << s << endl;

  auto q = sum_left_fold(1, 2, 3, 4, 5);
  cout << q << endl;
  auto p = sum_left_fold('a', 'b', 'c');
  cout << p << endl;

  fold_print("Hello!"s, ' ', "World ", 2021);

  cout << endl;

  auto x = to_vector<double>(1, 2, 4.5, 'a');
}
