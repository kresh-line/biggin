// overloaded functions
#include <iostream>
using namespace std;
template <typename T> T sum (T a, T b) 
{
return a+b;
}

int main ()
{
cout << sum<int> (10,20) << '\n';
cout << sum<double> (1.0,1.5) << '\n';
return 0;
}