#include <iostream>
using namespace std;
class Shape {
    protected:
        int width, height;
    public:
    Shape( int a = 0, int b = 0){
        width = a;
        height = b;
    }
   virtual void print() {
        cout << "Shape object" << endl;
        cout << "Area = " << area() << endl;
    }
    virtual int area() {
        return 0;
    };
};
class Rectangle: public Shape {
    public:
    Rectangle( int a = 0, int b = 0):Shape(a, b) { }
    int area() {
        return width*height;
    };
    
    void print() {
        cout << " Rectangle object" << endl;
        cout << "Area = " << area() << endl;
    }
     
    friend ostream& operator<<(ostream &ostr, Rectangle &p);
  
    
 };

    ostream& operator<<(ostream &ostr, Rectangle &p){ 
      return ostr <<"rectangle: " << p.width <<"x" << p.height << endl;
    } 


class Triangle: public Shape {
    public:
    Triangle( int a = 0, int b = 0):Shape(a, b) { }
     int area() {
        return (width*height)/2;
    };
    
    void print() {
        cout << "Trangle object " << endl;
        cout << "Area = " << area() << endl;
    }
  
};

int main () {
    Shape *s;

    
    Rectangle rect(10,7);
    cout << rect;
    s = &rect;
    s->print();
    Triangle tria(10,5);
    s = &tria;
    s->print();

    Shape myshape(3,5);
   
    myshape.print();
    
    return 0;
}
