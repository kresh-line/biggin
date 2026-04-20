#include <iostream>
#include <string>
#include <sstream>
using namespace std;

typedef struct
{
    int id;
    string name;
    double deposit;
} Account;

void readAccounts(Account *accounts, int n){

    string mystr;
    for (int i = 0; i < n; i++)
    {
       
        cout << "Logariasmos " << i + 1 << endl;
        cout << "Dwse kodiko: ";
        getline(cin, mystr);
        stringstream(mystr) >> accounts[i].id;

        cout << "Dwse onoma: ";
        getline(cin, accounts[i].name);

        cout << "Dwse poso katathesis: ";
        getline(cin, mystr);
        stringstream(mystr) >> accounts[i].deposit;
    }
}



void printAccounts(Account *accounts, int n)
{
     cout << "\nStoixeia Logariasmwn" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Logarasmios : ";
        cout << accounts[i].id << " " << accounts[i].name << " ";
        cout << accounts[i].deposit << endl;
    }
}

void applyInterest(Account *accounts, int n, double rate){
    for (int i = 0; i < n; i++)
    {
       accounts[i].deposit += accounts[i].deposit * rate / 100; 
    }
}

int main()
{
    string mystr;

    int n;
    cout << "Dwse arithmo logarismwn: ";
    getline(cin, mystr);
    stringstream(mystr) >> n;

    Account *accounts = new Account[n];
    
    readAccounts(accounts, n);
    printAccounts(accounts, n);

    double rate;
    cout << "Dwse epitokio: ";
    getline(cin, mystr);
    stringstream(mystr) >> rate;
    applyInterest(accounts, n, rate);
    printAccounts(accounts, n);
    
}