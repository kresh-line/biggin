#include <iostream>
using namespace std;

int main() {
int a ,b;
cout << "Enter a: ";
cin >> a;
cout << "Enter b: ";
cin >> b;
try {
    
  if (b != 0) {
    cout << "phliko = " << a/b << endl;
  } else {
    throw 505;
  }
  cout << "Another statement \n";
}
catch (int myNum) {
  cout << "can not divide by zero.\n";
  cout << "Error number: " << myNum;
}
return 0;
}