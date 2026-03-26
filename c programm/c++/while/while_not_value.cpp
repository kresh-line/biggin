// This program calculates the average salary of 5 employees using a for loop.


/*#include <iostream>
using namespace std;

int main () {
int n = 5;
float miss ,sum = 0.0, average;
cout << "Dwse to mistho 5 ypollilwn: " << endl;
for (int i = 1; i <=n; i++) {
    cout << "ypallilos " << i << ": ";
    cin >> miss;
    sum += miss;
}
average = sum / (float) n;
cout <<"\n Athristiko mistho: " << sum << endl;
cout << "Mesos misthos: " << average << endl;
    return 0;
}
*/

// THIS PROGRAM CALCULATES THE AVERAGE SALARY OF 5 EMPLOYEES USING A WHILE LOOP INSTEAD OF A FOR LOOP.

#include <iostream>
using namespace std;    
int main () {
int n = 5;
float miss ,sum = 0.0, average;
cout << "Dwse to mistho 5 ypollilwn: " << endl;
int i = 1;
while (i <= n){
    cout << "ypallilos " << i << ": ";
    cin >> miss;
    sum += miss;
    i++;
}
average = sum / (float) n;
cout <<"\n Athristiko mistho: " << sum << endl; 
cout << "Mesos misthos: " << average << endl;
    return 0;
}

