#include <iostream>
using namespace std;

void swap (int& a, int& b)
{
    int temp=a;
    a=b;
    b=temp;
}


int main () {
int x, y, temp;

cout << "Dwse ton prwto arithmo x: ";
cin >> x; 
cout << "Dwse ton deytero arithmo y: ";
cin >> y;
swap(x, y);

cout << "Meta to swapping: x=" << x << ", y=" << y;
return 0;



}
