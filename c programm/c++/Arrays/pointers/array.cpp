#include <iostream>
using namespace std;
int main ()
{
    double numbers[10];
    double * p;
    p = numbers; 
    cout <<"p= "<<p<<endl;
    for (int n=0;n<10; n++){
        *(p+n) = 10*(n+1);
      
    }
    /* *p = 10.6;
    //numers[0]=10;

    p++;
    cout <<"p++ = "<<p<<endl; 
    *p = 23.9;
    //numers[1]=20;

    p = &numbers[2]; 
    *p = 30.5;
     //numers[2]=30;
    p = numbers + 3; 
    *p = 40.4;
    //numers[4]=40;
    p = numbers; 
    *(p+4) = 50.3;
     //numers[4]=50;
    */
    for (int n=0;n<10; n++)
        cout << numbers[n] << ", ";
    return 0;
}