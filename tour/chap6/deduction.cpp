#include <list>
#include <iostream>

using namespace std;

template<typename T>
class Vector2 {
  public:
    using value_type = T;
    Vector2(initializer_list<T> lst)
      :elem{new T[lst.size()]}, sz{static_cast<int>(lst.size())}
    {
      copy(lst.begin(), lst.end(), elem); // copy lst into elem
    }

    // by adding the deduction guide we can deduce what the value of the type is
    template<typename Iter>
      Vector2(Iter, Iter) -> Vector2<typename Iter::value_type>;
    // [b:e) range constructor
    template<typename Iter> Vector2(Iter b, Iter e)
    {
      sz = e - b;
      elem = new T[sz];
      for(auto i = b; i < e; ++i)
        elem[i - b] = i;
    }

    T* begin()
    {
      return size() ? &elem[0] : nullptr; // pointer to first element or nullptr
    }

    T* end()
    {
      return size() ? &elem[0] + size() : nullptr; // pointer to one past last element or nullptr
    }

    int size() { return sz; }
  private:
    T* elem;
    int sz;
};

int main()
{
  Vector2<int> v1 {1,2,3,4,5};
  Vector2<int> v2(v1.begin(), v1.end());
  cout << v2.begin() << endl;
}
