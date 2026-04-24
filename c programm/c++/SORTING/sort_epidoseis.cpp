#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(vector<double>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main(){
    vector<double> epidoseis(10);

    for (int i = 0; i < 10; i++) {
        cout << "Athlitis " << i + 1 << " - Epidosi (m): ";
        cin >> epidoseis[i];
    }

    bubbleSort(epidoseis);

    cout << "\nEpidoseis se fthoysa diataxh:\n";
    for (const double& i : epidoseis)
        cout << i << " m  ";

    return 0;
}
