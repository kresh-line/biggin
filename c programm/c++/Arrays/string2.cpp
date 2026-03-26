#include <iostream>
#include <string>
using namespace std;

int main () {

   string greeting;
   cout << "enter massage: ";
    getline(cin, greeting);

   int len = greeting.length();
    int size = greeting.size();

 greeting[]='#';

    for (int i = 0; i<len; i++)
    {
        cout <<"greeting["<<i<<"] = " <<greeting[i]<< endl;
    }
   
   return 0;
}