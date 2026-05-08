#include <iostream>
using namespace std;
class Circle {
    double radius;
  public:
    Circle(double r) : radius(r) {}//cout << "Circle constructor called\n";}
    double area() {return radius*radius*3.14159265;}
};
class Cylinder {
    Circle base;
    double height;
  public:
    Cylinder(double r, double h) : base (r), height(h) {}//cout << "Cylinder constructor called\n";}
    double volume() {return base.area() * height;}

    bool operator > (Cylinder& other) {
        return this->volume() > other.volume();
    }
};
int main () {
  Cylinder cyl1 (10,10);
  cout << "cyl1's volume: " << cyl1.volume() << '\n';
  Cylinder cyl2 (20,5);   
  cout << "cyl2's volume: " << cyl2.volume() << '\n';

    if (cyl1 > cyl2) {
        cout << "cyl1 is larger than cyl2\n";
    } else {
        cout << "cyl2 is larger than cyl1\n";
    }
  return 0;
}