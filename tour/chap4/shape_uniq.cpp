#include <iostream>
#include <vector>

// just like shape.cpp but let's use unique pointers for better
// resource management
using namespace std;

class Point {
  public:
    Point(int x, int y) :lat{x}, lng{y} {}
    Point operator+(Point to) {
      Point p = Point((this->lat + to.lat), (this->lng + to.lng));
      return p;
    }
  private:
    int lat;
    int lng;
};

// Abstract class, nothing is defined on this class
// Can be seen as an interface
class Shape {
  public:
    virtual Point center() const = 0; // pure virtual
    virtual void move(Point to) = 0;

    virtual void draw() const = 0; // draw on virtual canvas
    virtual void rotate(int angle) = 0;

    virtual ~Shape() {} // destructor
};

void rotate_all(vector<unique_ptr<Shape>>& v, int angle) // rotate all members of v by angle
{
  for(auto const& p : v)
    p->rotate(angle);
}

void draw_all(vector<unique_ptr<Shape>>& v)
{
  for(auto const& p : v)
    p->draw();
}

class Circle : public Shape {
  public:
    Circle(Point p, int rad) :x{p}, r{rad} {}
    Point center() const override {
      return x;
    }

    void move(Point to) override {
      x = x + to; 
    }

    void draw() const override {
      cout << "Drawing a circle with radius: " << r << "\n";
    }

    void rotate(int angle) override {
      cout << "Rotating: " << angle << "\n";
    }
  private:
    Point x; // center
    int r; // radius
};

// subclass of a subclass!
class Smiley : public Circle {
  public:
    Smiley(Point p, int rad) : Circle{p, rad}, mouth{nullptr} { }

    void move(Point to) override {
      Circle::move(to);
      for(auto p : eyes)
        p->move(to);
      mouth->move(to);
    }

    void draw() const override {
      Circle::draw();
      cout << "Drawing a smiley" << endl;
      for(auto p : eyes)
        p->draw();
      mouth->draw();
    }

    void rotate(int angle) override {
      cout << "Rotating from smiley" << endl;
    }

    void add_eye(Shape* s)
    {
      eyes.push_back(s);
    }

    void add_mouth(Shape* s)
    {
      mouth = s;
    }

    //virtual void wink(int i); // wink the eye denoted by i
  private:
    vector<Shape*> eyes; // usually two eyes
    Shape* mouth;
};

class Triangle : public Shape {
  public:
    Triangle(Point x, int h) :height{h}, c{x} {}
    Point center() const override
    {
      return c;
    }
    void move(Point to) override {
      c = c + to;
    }

    void draw() const override{
      cout << "Drawing a triangle" << endl; 
    }

    void rotate(int angle) override {
      cout << "Rotating a triangle" << endl;
    }

    ~Triangle() {}

  private:
    int height;
    Point c;
};

enum class Kind { circle, triangle, smiley };

Kind get_kind_from_string(string type)
{
  if (type == "c") {
    return Kind::circle;
  } else if (type == "t") {
    return Kind::triangle;
  } else {
    return Kind::smiley;
  }
}

unique_ptr<Circle> build_circle_from_input(istream& in)
{
  int clat;
  int clng;
  int rad;
  cout << "Input center for circle: " << endl;
  cout << "X: ";
  in >> clat;
  cout << endl;
  cout << "Y: ";
  in >> clng;
  cout << endl;
  cout << "Radius: ";
  in >> rad;
  cout << endl;
  return unique_ptr<Circle>{new Circle{Point(clat, clng), rad}};
}

unique_ptr<Triangle> build_triangle_from_input(istream& in)
{
  int clat;
  int clng;
  int height;
  cout << "Input center for triangle: " << endl;
  cout << "X: ";
  in >> clat;
  cout << endl;
  cout << "Y: ";
  in >> clng;
  cout << endl;
  cout << "Height: ";
  in >> height;
  cout << endl;
  return unique_ptr<Triangle>{new Triangle(Point(clat, clng), height)};
}

unique_ptr<Smiley> build_smiley_from_input(istream& in)
{
  int clat;
  int clng;
  int rad;
  cout << "Input center for smiley: " << endl;
  cout << "X: ";
  in >> clat;
  cout << endl;
  cout << "Y: ";
  in >> clng;
  cout << endl;
  cout << "Radius: ";
  in >> rad;
  cout << endl;
  unique_ptr<Smiley> s = unique_ptr<Smiley>{new Smiley{Point(clat, clng), rad}};
  Circle* e1 = new Circle(Point(clat + 4, clng + 4), rad / 4);
  Circle* e2 = new Circle(Point(clat - 4, clng + 4), rad / 4);
  Circle* m = new Circle(Point(clat - 4, clng), rad / 2);
  s->add_eye(e1);
  s->add_eye(e2);
  s->add_mouth(m);
  return s;
}

unique_ptr<Shape> read_shape(istream& in)
{
  cout << "Which do you want: circle (c), triangle (t), smiley (s)?" << endl;

  string input;
  in >> input;
  Kind k = get_kind_from_string(input);
  unique_ptr<Shape> s;
  switch(k) {
    case Kind::circle:
      s = build_circle_from_input(in);
      break;
    case Kind::triangle:
      s = build_triangle_from_input(in);
      break;
    default:
      s = build_smiley_from_input(in);
  }

  return s;
}

void user()
{
  vector<unique_ptr<Shape>> v;
  while(cin)
    v.push_back(read_shape(cin));
  draw_all(v);
  rotate_all(v, 45);
}

int main()
{
  user();
}
