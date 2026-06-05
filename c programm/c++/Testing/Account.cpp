#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Account {
private:
    string katochos;
    double ypolipo;
public:
    Account(string kat, double ypol) {
        katochos = kat;
        try {
            if (ypol < 0) 
                throw ypol;
            ypolipo = ypol;
            
            
        }
        catch (double d) {
            cout <<"edhoses ypolipo: " << d << endl;
            cout << " to ypolipo tou logariasmo prepi na einai thetiko " << endl;
            ypolipo = 0.0;
        }

    }
    void print() {
        cout << "logariasmo: Katochos=  " << katochos << " Ypolipo: " << ypolipo << endl;
    }
};
void printAccounts(vector<Account> &accounts) {

   cout <<"\n stixeiologio logariasmwn: " << endl;
    for (int i = 0; i < accounts.size(); i++) {
        accounts[i].print();
    }
}
int main() {
    vector<Account> accounts;
    double ypolipo;
    string onoma;
    cout << "Enter ypolipo (-9999 gia telos):  ";
    cin >> ypolipo;

    while (ypolipo != -9999) {
        cout << "Enter onoma katochou: ";
        cin >> onoma;
        accounts.push_back(Account(onoma, ypolipo));
        cout << "\n Enter ypolipo (-9999 gia telos):  ";
        cin >> ypolipo;
    }
//    Account acc1("John ", -1000.0);
//    acc1.print();
//    accounts.push_back(acc1);
//    Account acc2("Jane ", 500.0);
//    accounts.push_back(acc2);
   printAccounts(accounts);

    return 0;
}