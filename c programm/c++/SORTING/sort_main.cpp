#include "sort_header.hpp"
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