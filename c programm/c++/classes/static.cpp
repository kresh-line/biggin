#include <iostream>
 
using namespace std;
class Box {
   public:
      static int objectCount;
       
      
      // Constructor definition with default values
      Box(double length = 2.0, double breadth = 2.0, double height = 2.0) {
         cout <<"Constructor called." << endl;
         this->length = length;
         this->breadth = breadth;
         this->height = height;
         
         // Increase every time object is created
         objectCount++;
      }
      double Volume() {
         return length * breadth * height;
      }
      void print(){
        cout << "box's length: "<< length << endl;
        cout << "box's breadth: "<< breadth << endl;
        cout << "box's height: "<< height << endl << endl;
        
      }
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};
// Initialize static member of class Box
int Box::objectCount = 0;
int main(void) {
   Box box1(3.3, 1.2, 1.5);    // Declare box1
   Box box2(8.5, 6.0, 2.0);    // Declare box2
   box1.print();
   box2.print();
   Box box3(4,5,5); // Declare box3 with default constructor
   box3.print();
   // Print total number of objects.
   cout << "Total objects: " << Box::objectCount << endl;
   return 0;
}