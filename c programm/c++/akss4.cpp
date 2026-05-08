#include <iostream>
#include <string>
using namespace std;

int main() {
    const int N = 5;
    string model[N];
    string etos[N];
    double timi[N];

    for (int i = 0; i < N; i++) {
        cout << "Αυτοκίνητο " << i + 1 << ":\n";
        cout << "  Μοντέλο: ";
        cin >> model[i];
        cout << "  Έτος: ";
        cin >> etos[i];
        cout << "  Τιμή: ";
        cin >> timi[i];
    }

    int maxIndex = 0;
    for (int i = 1; i < N; i++)
        if (timi[i] > timi[maxIndex])
            maxIndex = i;

    cout << "\nΤο πιο ακριβό αυτοκίνητο:\n";
    cout << "  Μοντέλο: " << model[maxIndex] << "\n";
    cout << "  Έτος:    " << etos[maxIndex] << "\n";
    cout << "  Τιμή:    " << timi[maxIndex] << " EUR\n";

    return 0;
}
