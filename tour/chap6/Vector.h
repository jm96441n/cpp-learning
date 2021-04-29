#include <list>

template<typename T>
class Vector {
  public:
    Vector<T>(int s); // initialize list of T
    
    ~Vector();

    Vector(const Vector& a); // copy constructor
    Vector& operator=(const Vector& a); // copy assignment
    Vector(Vector&& a); // move constructor
    Vector& operator=(Vector&& a); // move assignment
    T& operator[](int i);
    int size();
    // "begin" and "end" functions permit use of (for auto x : p) where x is a Vector<T>
    T* begin() const;
    T* end() const;
};
