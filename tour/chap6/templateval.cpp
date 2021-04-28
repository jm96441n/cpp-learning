#include <iostream>
#include <list>

using namespace std;

// using the value argument in the template allows us to create buffers of arbitrary
// sizes without using the free store
template<typename T, int N>
struct Buffer {
  using value_type = T;
  constexpr int size() { return N; } 
};

Buffer<char, 1024> glob; // global buffer of chars statically allocated

void fct()
{
  Buffer<int, 10> buf; // local buffer of ints, on the stack  
};

int main()
{
  fct();
}
