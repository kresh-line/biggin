/*
#include <iostream>
using namespace std;

    int x; 
    int y;
    // Local variable in main
    int function1() {
       
       y=1;
        x=5;
        
    }
      
   int main() {
    int z;
     // Local variable in main
    x=10; // Assigning value to x
    z=30; 
    y=20; // Assigning value to y
    return 0;
}
    */

// inner block scopes
/*
#include <iostream>
using namespace std;

int main () {
  int x = 10;
  int y = 20;
  {
    int x ;   // ok, inner scope.
    x = 50;  // sets value to inner x
    y = 50;  // sets value to (outer) y
    cout << "inner block:\n";
    cout << "x: " << x << '\n';
    cout << "y: " << y << '\n';
  }
  cout << "outer block:\n";
  cout << "x: " << x << '\n';
  cout << "y: " << y << '\n';
  return 0;
}*/


#include <iostream>
using namespace std;
int main () {
    int sum = 0;
    int nuerber;
    int i; // Declare i in the outer scope
    for (int i = 0; i < 5; i++) {
        cout << "Dwse ton " << i+1 << "o arithmo: ";
        cin >> nuerber;
        sum += nuerber; // sum = sum + number
    }
    cout <<"i=" <<i; 
    cout <<"To athroisma einai: " << sum << '\n';
    return 0;
}