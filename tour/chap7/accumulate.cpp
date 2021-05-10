#include <iostream>
#include <vector>

using namespace std;

// Why do it have to return a double?
// Why does it have to take a vector of ints?
// Why start at 0?
double sum(const vector<int>& v)
{
  double res = 0;
  for (auto x : v)
    res += x;
  return res;
}

// the answer to the above questions leads us to the std lib accumulate algo
template<typename Iter, typename Val>
Val accumulate(Iter first, Iter last, Val res)
{
  for(auto p = first; p != last; ++p)
    res += *p;
  return res;
}

// simplify so that we don't need to repeatedly call the begin/end functions when calling
// Range is something with begin() and end()
template <typename Range, typename Val>
Val simple_acc(const Range& r, Val res = 0)
{
  for(auto p = begin(r); p != end(r); ++p)
    res += *p;
  return res;
}

int main()
{
  vector<int> vec = vector<int>{1,2,3,4,5};
  auto s = sum(vec);
  cout << "Sum from 'sum': " << s << endl;
  auto a = accumulate(vec.begin(), vec.end(), 0);
  cout << "Sum from 'accumulate': " << a << endl;
  auto d = accumulate(vec.begin(), vec.end(), 10);
  cout << "Sum from 'accumulate' with start val of '10': " << d << endl;

  auto b = simple_acc(vec, 10);
  cout << "Sum from 'simple_acc' with start val of '10': " << b << endl;

  auto c = simple_acc<vector<int>, int>(vec);
  cout << "Sum from 'simple_acc' with no start val: " << c << endl;
}
