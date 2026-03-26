// cin with strings
#include <iostream>
#include <string>
using namespace std;

int main ()
{
  string mystr;
  cout << "What's your name? ";
  // getline (cin, mystr);
cin >> mystr;
  cout << "Hello " << mystr << ".\n";
  cout << "What is your favorite team? ";
  // getline (cin, mystr);
  cin >> mystr;  // This will only read the first word of the input
  cout << "I like " << mystr << " too!\n";
  return 0;
}

//output is What's your name? John Doe
//Hello John. What is your favorite team?  I like Doe too! 