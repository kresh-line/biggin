#include <iostream>
using namespace std;
int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    
    string result = (number >= 0 ? "Positive" : "Negative");
    cout << result << endl;
    return 0;
}