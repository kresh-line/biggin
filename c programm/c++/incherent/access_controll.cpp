#include <iostream>
using namespace std;
class Polygon
{
private:
    int x, y;
//protected:
    int width, height;
public:
    Polygon() : x(0), y(0), width(0), height(0) {}
    Polygon(int a, int b, int c, int d) : x(a), y(b), width(c), height(d) {}
    void set_values(int a, int b)
    {
        width = a;
        height = b;
    }
    int getWidth()
    {
        return width;
    }
    int getHeight()
    {
        return height;
    }
    int getY()
    {
        return y;
    }
    int getX()
    {
        return x;
    }
   void print()
    { 
        cout << "x: " << x << ", y: " << y << ", width: " << width << ", height: " << height << endl;
           
    }
};
class Rectangle : public Polygon
{
public:
    Rectangle(int a, int b, int c, int d) : Polygon(a, b, c, d) {}
    int area()
    {
        return getWidth() * getHeight();
    }
};
class Triangle : public Polygon
{
public:
    Triangle(int a, int b, int c, int d) : Polygon(a, b, c, d) {}
    int area()
    { // baloume to getWidth() kai getHeight() giati einai private methodoi tis klasis Polygon kai den exoun allaksei se Rectangle kai Triangle
        return getWidth() * getHeight() / 2;
    }
};

int main()
{
    Rectangle rect(0, 0, 4, 5);
    Triangle trgl(0, 0, 4, 5);
    cout << "Accessing protected members from main function:" << endl;
    cout << "Width of rectangle: " << rect.getWidth() << endl;  
    cout << "Height of rectangle: " << rect.getHeight() << endl;
    cout << "Width of triangle: " << trgl.getWidth() << endl;
    cout << "Height of triangle: " << trgl.getHeight() << endl;
    cout << "Accessing private members from main function:" << endl;
    cout << "X coordinate of rectangle: " << rect.getX() << endl;
    cout << "Y coordinate of rectangle: " << rect.getY() << endl;
    cout << "X coordinate of triangle: " << trgl.getX() << endl;
    cout << "Y coordinate of triangle: " << trgl.getY() << endl;
    
    rect.print();
    cout << "Area of rectangle: " << rect.area() << '\n';
    trgl.print();
    cout << "Area of triangle: " << trgl.area() << '\n';
    return 0;
}   

