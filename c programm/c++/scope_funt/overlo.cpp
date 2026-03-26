// overloading functions
/*#include <iostream>
using namespace std;
int operate (int a, int b)
{
return (a*b);
}
double operate (double a, double b)
{
return (a/b);
}
int main ()
{
int x=5,y=2;
double n=5.0,m=2.0;
cout << operate (x,y) << '\n';
cout << operate (n,m) << '\n';
return 0;
}*/

#include <iostream>
using namespace std;
int sqr(int x)
{return x*x;
}
double sqr(double y)
{return y*y;
}
int main()
{   int x=5;
    double y=6.0;       
    cout << sqr(x) << '\n';
    cout << sqr(y) << '\n';
    return 0;
}