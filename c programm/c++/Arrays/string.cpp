#include <iostream>
#include <cstring>
using namespace std;

int main () {

   char greeting[20];
   cout << "enter massage: ";
   cin >> greeting;

   int len = strlen(greeting);
    cout <<"strlen(greeting) : "<< len << endl;
    for (int i = 0; i<len; i++)
    {
        cout <<"greeting["<<i<<"] = " <<greeting[i]<< endl;
    }
   cout << "Greeting message: ";
   cout << greeting << endl;

   return 0;
}
// ok kjo punë u bë