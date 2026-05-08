#include <iostream>
#include <string>
using namespace std;

struct Car {
    string model;
    string year;
    double price;
};

int main() {
    const int N = 5;
    Car myCars[N];

    for (int i = 0; i < N; i++) {
        cout << "\nΑυτοκίνητο " << i + 1 << ":\n";
        cout << "  Μοντέλο: ";
        cin >> myCars[i].model;
        cout << "  Έτος: ";
        cin >> myCars[i].year;
        cout << "  Τιμή: ";
        cin >> myCars[i].price;
    }

    int maxIndex = 0;
    for (int i = 1; i < N; i++)
        if (myCars[i].price > myCars[maxIndex].price)
            maxIndex = i;

    cout << "\nΤο πιο ακριβό αυτοκίνητο:\n";
    cout << "  Μοντέλο: " << myCars[maxIndex].model << "\n";
    cout << "  Έτος:    " << myCars[maxIndex].year << "\n";
    cout << "  Τιμή:    " << myCars[maxIndex].price << " EUR\n";

    return 0;
}
