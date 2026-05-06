// classes example
#include <iostream>
using namespace std;
class Rectangle {
    int width, height;
public:
    Rectangle (int w, int h) {
        cout << "Constructor called" << endl;
        width= w;
        height= h;
    }
    Rectangle (void){
        cout << "Default constructor called" << endl;
        width = 1;
        height = 1;
    }
    ~Rectangle() {
        cout << "Rectangle is being destroyed" << endl;
    }
    int getWidth() { return width; }
    int getHeight() { return height; }
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }

    void set_values (int,int);
    int area() {return width * height;}
void print() {
    cout << "Rectangle: " << width << " x " << height << endl;
    cout << "Area = " << area() << endl;
}

};
void Rectangle::set_values (int x, int y) {
    width = x;
    height = y;
}
int main () {

    Rectangle rect(3, 4);
    //rect.setWidth(5);
    rect.print();
    Rectangle rect2(5, 6);
    rect2.print();
    //cout << "area: " << rect.area() << endl;
    Rectangle rect3;
    rect3.print();
    
   // cout << "area: " << rect.area() << endl;

    return 0;
}