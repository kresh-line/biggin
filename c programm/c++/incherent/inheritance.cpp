#include <iostream>
 
using namespace std;
// Base class
class Shape {
   public:
      void setWidth(int w) {
         width = w;
      }
      void setHeight(int h) {
         height = h;
      }
      void print(){
    cout << "Shape's width = " << width << " and height = " << height << endl;
      }
   protected:
      int width;
      int height;
};
// Derived class
class Rectangle: public Shape {
   public:
      Rectangle() {
         width = 1;
         height = 1;
      }
      Rectangle(int width, int height) {
          this->width = width;
         this->height = height;
      }
      int getArea() {
         return (width * height);
      }
         int getPerimeter() {
            return 2 * (width + height);
        }
};

class square: public Rectangle {
   public:
        square(int width): Rectangle(width, width) { }
};

int main(void) {
   
   Rectangle rect1(4,5);
   rect1.print();
   cout << "Total area of rect1: " << rect1.getArea() << endl;
    cout << "Total perimeter of rect1: " << rect1.getPerimeter() << endl;

    square sq1(5);
    sq1.print();
    cout << "Total area of sq1: " << sq1.getArea() << endl;
    cout << "Total perimeter of sq1: " << sq1.getPerimeter() << endl;
   return 0;
}
