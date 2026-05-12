#include <iostream>
using namespace std;
class Rectangle {
   public:
      static int objectCount;
      
      // Constructor definition
      Rectangle(double  width= 2.0, double height = 2.0) {
         cout <<"Constructor called." << endl;
         this->width = width;
         this->height = height;
         // Increase every time object is created
         objectCount++;
      }
      
      void setValues(double  width, double height) {
         this->width = width;
         this->height = height;
      }
      
      double area() const {
         return width * height;
      }
      
      void print() const{
    cout << "Rectangle's width = " << width << endl;
  cout << "Rectangle's height = " << height << endl;
  cout << "Rectangle's Area: " << area() << endl <<endl;
}
      
   private:
      double width;     
      double height;    
};
// Initialize static member of class Box
int Rectangle::objectCount = 0;
int main(void) {
   Rectangle rectA(3, 5);    
    Rectangle rectB(8, 6);    
   // Print total number of objects.
   cout << "Total objects: " << Rectangle::objectCount << endl;
   
    rectA.setValues(4.2,6.4);     // No error
    rectB.setValues(5,10);     // Compile time error
   
    rectA.print();     // No error
    rectB.print();     // No error
   return 0;
}