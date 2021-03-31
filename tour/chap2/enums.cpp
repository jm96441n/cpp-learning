#include <iostream>

using namespace std;

enum class Color { red, blue, green };
enum class TrafficLight { green, yellow, red };

TrafficLight& operator++(TrafficLight& t) // prefix increment: ++
{
  switch(t) {
    case TrafficLight::green:
      return t=TrafficLight::yellow;
    case TrafficLight::yellow:
      return t=TrafficLight::red;
    case TrafficLight::red:
      return t=TrafficLight::green;
  }
}

int main()
{
  Color col = Color::red;
  TrafficLight traf = TrafficLight::red;

  // Color x = red; // won't compile because which red?
  // Color x = TraffLight::red; // won't compile because wrong red?
  Color x = Color::red; // will compile, colors match
}
