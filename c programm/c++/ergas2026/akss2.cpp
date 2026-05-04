#include <iostream>
using namespace std;

// Συνάρτηση που επιστρέφει βαθμούς ανάλογα με το αποτέλεσμα
int ypologismosBathmwn(int termataShmeiose, int termataDehtike) {
    if (termataShmeiose > termataDehtike)
        return 3;
    else if (termataShmeiose < termataDehtike)
        return 0;
    else
        return 1;
}

int main() {
    int termataShmeiose, termataDehtike, bathmoi;
    int synolkoiBathmoi = 0;
    int maxTermata = 0;

    for (int i = 1; i <= 3; i++) {
        cout << "Αγώνας " << i << " - Τέρματα ομάδας: ";
        cin >> termataShmeiose;
        cout << "Αγώνας " << i << " - Τέρματα αντιπάλου: ";
        cin >> termataDehtike;

        bathmoi = ypologismosBathmwn(termataShmeiose, termataDehtike);

        cout << "Βαθμοί αγώνα " << i << " -> " << bathmoi << " Βαθμοί" << "\n\n";

        synolkoiBathmoi += bathmoi;

        if (termataShmeiose > maxTermata)
            maxTermata = termataShmeiose;
    }

    cout << "--- Τελικά Αποτελέσματα ---\n";
    cout << "Συνολικοί βαθμοί: " << synolkoiBathmoi << "\n";
    cout << "Περισσότερα τέρματα σε έναν αγώνα: " << maxTermata << "\n";

    return 0;
}
