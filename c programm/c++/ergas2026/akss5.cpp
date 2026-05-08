#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct {
    string name;
    double deposit;
} Account;

void applyInterest(vector<Account> &accounts, double rate) {
    for (int i = 0; i < accounts.size(); i++)
        accounts[i].deposit += accounts[i].deposit * rate / 100;
}

void printAccounts(vector<Account> &accounts) {
    cout << "\n--- Λίστα Λογαριασμών ---\n";
    for (int i = 0; i < accounts.size(); i++)
        cout << accounts[i].name << " - " << accounts[i].deposit << " EUR\n";
}

int main() {
    int n;
    double rate;

    cout << "Επιτόκιο καταθέσεων (%): ";
    cin >> rate;
    cout << "Πλήθος λογαριασμών: ";
    cin >> n;

    vector<Account> accounts;

    for (int i = 0; i < n; i++) {
        Account acc;
        cout << "\nΛογαριασμός " << i + 1 << ":\n";
        cout << "  Όνομα καταθέτη: ";
        cin >> acc.name;
        cout << "  Ποσό κατάθεσης: ";
        cin >> acc.deposit;
        accounts.push_back(acc);
    }

    applyInterest(accounts, rate);
    printAccounts(accounts);

    return 0;
}
