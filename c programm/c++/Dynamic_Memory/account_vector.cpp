#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

typedef struct
{
    int id;
    string name;
    double deposit;
} Account;

void readAccounts(vector<Account> &accounts){

    string mystr;
    Account account;
    for (int i = 0; i < accounts.size(); i++)
    {
       
        cout << "Logariasmos " << i + 1 << endl;
        cout << "Dwse kodiko: ";
        getline(cin, mystr);
        stringstream(mystr) >> account.id;

        cout << "Dwse onoma: ";
        getline(cin, account.name);

        cout << "Dwse poso katathesis: ";
        getline(cin, mystr);
        stringstream(mystr) >> account.deposit;

        accounts.push_back(account);
    }
}



void printAccounts(vector<Account> &accounts)
{
     cout << "\nStoixeia Logariasmwn" << endl;
    for (int i = 0; i < accounts.size(); i++)
    {
        cout << "Logarasmios : ";
        cout << accounts[i].id << " " << accounts[i].name << " ";
        cout << accounts[i].deposit << endl;
    }
}

void applyInterest(vector<Account> &accounts, double rate){
    for (int i = 0; i < accounts.size(); i++)
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

    vector<Account> accounts(n);
    
    readAccounts(accounts);
    printAccounts(accounts);
    double rate;
    cout << "Dwse epitokio: ";
    getline(cin, mystr);
    stringstream(mystr) >> rate;
    cout << "Katabolh Tokwn"<<endl<<endl;
    applyInterest(accounts, rate);
    printAccounts(accounts);
    
}