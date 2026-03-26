// passing parameters by reference
#include <iostream>
using namespace std;
void duplicate (int& a, int& b, int& c)
{
a*=2;
b*=2;
c*=2;
cout << "Duplicate: a=" << a << ", b=" << b << ", c=" << c << endl;
}
 /*
 void swap (int& a, int& b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}

*/
int main ()
{
int x=1, y=3, z=7;
duplicate (x, y, z);
swap (x, y, z);
cout << "x=" << x << ", y=" << y << ", z=" << z<< endl;
return 0;
}