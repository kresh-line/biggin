// function example
#include <iostream>
using namespace std;

float megistos (const float a, const float b)
{
if (a>b){
return a;
}
return b;
}

int main ()
{
float a, b, max;

cout << "Dwse prwto arithmo :";
cin >> a;
cout << "Dwse deytero arithmo :";
cin >> b;
cout << "O megalyteros arithmos einai o " << megistos(a,b);
return 0;
}