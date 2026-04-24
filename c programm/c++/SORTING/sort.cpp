#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
      
        // If no two elements were swapped, then break
        if (!swapped)
            break;
    }

int main(){
    vector<int> v;
    int newInt;
    cout << "Dwse ena arithmoy: ";
    cin >> newInt;
    while(newInt != -1){

        v.push_back(newInt);
        cout << "Dwse ena arithmoy: ";
        cin >> newInt;
    }
    // Sort vector (by default in ascending order)
    //sort(v.begin(), v.end());
   bubbleSort(v);

    for (int i : v)
        cout << i << " ";
    return 0;
}