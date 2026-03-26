#include <iostream>
#include <cmath>
#include <iomanip>
#define _USE_MATH_DEFINES
using namespace std;
#define NewLine '\n';
#define PI 3.14159;

//const double pi = 3.14159;
//const char newline = '\n'; 
const char* askisi = "Askisi2";

int main ()

{
double r;
double circle;
cout << "Dwse to mhkos tou aktinou: ";
cin >> r;
circle = 2 * M_PI * r;
    cout <<"Aktina: " << setw(5) << r << endl;

cout << setprecision(5) << circle;
cout << NewLine;
//cout << setprecision(9) << 1.41421356;
}