#include<iostream>
using namespace std;
double factorial(double n)
{
if(n > 1)
return n * factorial(n - 1);
else
return 1.0;
}
int main()
{
double n;
cout << "Enter a positive integer: ";
cin >> n;
cout << "Factorial of " << n << " = " << factorial(n);
return 0;
}