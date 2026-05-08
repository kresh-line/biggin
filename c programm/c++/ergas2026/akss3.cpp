#include <iostream>
#include <string>
using namespace std;

int main() {
    const int N = 5;
    string onomata[N];
    double bathmoi[N];

    // i. Διαβάζει ονόματα και βαθμούς με έλεγχο 0-10
    for (int i = 0; i < N; i++) {
        cout << "Ονομα σπουδαστή " << i + 1 << ": ";
        cin >> onomata[i];
        do {
            cout << "Βαθμός (0-10): ";
            cin >> bathmoi[i];
            if (bathmoi[i] < 0 || bathmoi[i] > 10)
                cout << "Λάθος βαθμός! Δώσε τιμή μεταξύ 0 και 10.\n";
        } while (bathmoi[i] < 0 || bathmoi[i] > 10);
    }

    // ii. Υπολογισμός και εμφάνιση μέσου όρου
    double athroisma = 0;
    for (int i = 0; i < N; i++)
        athroisma += bathmoi[i];
    double mesosOros = athroisma / N;
    cout << "\nΜέσος όρος τμήματος: " << mesosOros << "\n";

    // iii. Εμφάνιση ονομάτων με την καλύτερη βαθμολογία
    double maxBathmos = bathmoi[0];
    for (int i = 1; i < N; i++)
        if (bathmoi[i] > maxBathmos)
            maxBathmos = bathmoi[i];

    cout << "Καλύτερη βαθμολογία (" << maxBathmos << "):\n";
    for (int i = 0; i < N; i++)
        if (bathmoi[i] == maxBathmos)
            cout << "  " << onomata[i] << "\n";

    // iv. Αναζήτηση σπουδαστή με βάση το όνομα
    string anazitisi;
    cout << "\nΔώσε όνομα για αναζήτηση: ";
    cin >> anazitisi;

    bool vrethike = false;
    for (int i = 0; i < N; i++) {
        if (onomata[i] == anazitisi) {
            cout << "Βαθμός του " << anazitisi << ": " << bathmoi[i] << "\n";
            vrethike = true;
            break;
        }
    }
    if (!vrethike)
        cout << "Ο σπουδαστής δεν βρέθηκε.\n";

    return 0;
}
