#include <iostream>
using namespace std;

int main ()
{
int i;
string mystr;
cout << "Please enter an integer value: ";
getline (cin, mystr);
i = stoi(mystr);
cout << "The value you entered is " << i;
cout << " and its double is " << i*2 << ".\n";
return 0;

}