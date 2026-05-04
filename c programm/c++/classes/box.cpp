#include <iostream>

using namespace std;

class Box {
    double length;   // Length of a box
   public:
      
      double breadth;  // Breadth of a box
      double height;   // Height of a box

       double getVolume(void) {
         return length * breadth * height;
      }
      double getArea(void) {
         return (length * breadth);
      }
      void Box::setLength( double len ) {
        
         if (len >= 0)
         length = len;
         else 
            length = len * -1.0;
      }
    double Box::getLength( void ) {
         return length;
        
         
      }
      
};

int main() {
   Box Box1;        // Declare Box1 of type Box
   Box Box2; // Declare Box2 of type Box
   Box Box3;      // Declare Box3 of type Box
    
          
   double volume = 0.0;     // Store the volume of a box here
 
   // box 1 specification
   Box1.height = 5.0; 
   Box1.setLength(6.0); 
   Box1.breadth = 7.0;

   // box 2 specification
   Box2.height = 10.0;
   Box2.setLength(-6.0);
   Box2.breadth = 13.0;


   // box 3 specification
   Box3.height = 15.0;
   Box3.setLength(16.0);
   Box3.breadth = 17.0;

   // volume of box 1
   //volume = Box1.getVolume();
   cout << "Volume of Box1 : " << Box1.getVolume() <<endl;

   // volume of box 2
  //volume = Box2.getVolume();
   cout << "Volume of Box2 : " << Box2.getVolume() <<endl;

   // volume of box 3
   //volume = Box3.getVolume();
   cout << "Volume of Box3 : " << Box3.getVolume() <<endl;

   cout << "Area of Box1 : " << Box1.getArea() <<endl;
   cout << "Area of Box2 : " << Box2.getArea() <<endl;  
   cout << "Area of Box3 : " << Box3.getArea() <<endl;

   return 0;
}