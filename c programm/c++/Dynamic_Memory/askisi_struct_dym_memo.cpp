#include <iostream>
#include <string>
using namespace std;

// Δομή πελάτη
struct Account {
    string name;
    double deposit;
};

// Συνάρτηση για εφαρμογή επιτοκίου
void applyInterest(Account *Accounts, int n, double rate) {
    for (int i = 0; i < n; i++) {
        Accounts[i].deposit += Accounts[i].deposit * rate / 100;
    }
}

int main() {
    int n;
    double rate;

    cout << "Dwse arithmo logariasmwn: ";
    cin >> n;

    // Δυναμική δέσμευση μνήμης
    Account *Accounts = new Account[n];

    // Εισαγωγή δεδομένων
    for (int i = 0; i < n; i++) {
        cout << "\nLogariasmos " << i + 1 << endl;

        cout << "Onoma Pelati: ";
        cin >> Accounts[i].name;

        cout << "Poso Katathesis: ";
        cin >> Accounts[i].deposit;
    }

    cout << "\nDwse epitokio (%): ";
    cin >> rate;

    // Κλήση συνάρτησης
    applyInterest(Accounts, n, rate);

    // Εκτύπωση αποτελεσμάτων
    cout << "\n--- Nea posa katatheseon ---\n";
    for (int i = 0; i < n; i++) {
        cout << Accounts[i].name << " - "
             << Accounts[i].deposit << " Euro" << endl;
    }

    // Αποδέσμευση μνήμης
    delete[] Accounts;

    return 0;
}