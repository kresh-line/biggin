#include <iostream>
using namespace std;
int main() {
    int test;
    cout << "Enter a vathmo: ";
    cin >> test;

    if (test  < 0) {
        cout << "arhhtikh vathmologia.";
    } 
    else if (test < 10) {
        cout << "kato apo tin vasi." ;
    } 
    else if (test < 15) {
        cout << "ta piges metria." ;
    }
else if (test < 18 ) {
        cout << "ta piges kala." ;
    }
else if (test <=20) {
        cout << "ta piges polu kala." ;
    }
    else
    {
        cout << "lathos vathmologia." ;
    }
    return 0;
}