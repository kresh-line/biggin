#include <iostream>
#include <string>
using namespace std;

int main() {
    string onoma;
    double misthos, poso, totalPwliseis = 0.0, bonus;

    // α. Διαβάζει όνομα και μηνιαίο βασικό μισθό
    cout << "Onoma dianomea: ";
    getline(cin, onoma);
    cout << "Mhniaiow basikos misthos (EUR): ";
    cin >> misthos;

    // β. Διαβάζει επαναληπτικά τα ποσά πωλήσεων - σταματάει με 0 ή αρνητικό
    cout << "Dose ta posa pwlhsewn (0 h arnhtiko gia telos):\n";
    while (true) {
        cout << "Poso: ";
        cin >> poso;
        if (poso <= 0) break;
        totalPwliseis += poso;
    }

    // γ. Υπολογίζει και εκτυπώνει το μπόνους
    if (totalPwliseis <= 200)
        bonus = 0.0;
    else if (totalPwliseis <= 1000)
        bonus = totalPwliseis * 0.015;
    else
        bonus = totalPwliseis * 0.04;

    cout << "\n--- Apotelesmata ---\n";
    cout << "Dianomeas: " << onoma << "\n";
    cout << "Synolikes mhniaiews pwlhseis: " << totalPwliseis << " EUR\n";
    cout << "Bonus: " << bonus << " EUR\n";
    cout << "Synolikes apodoxes: " << misthos + bonus << " EUR\n";

    return 0;
}
