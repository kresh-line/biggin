#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 5
// An optimized version of Bubble Sort 
void bubbleSort(vector<double>& epidoseis, vector<string>& onomata) {
    int n = onomata.size();
    bool swapped;
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (epidoseis[j] > epidoseis[j + 1]) {
                swap(onomata[j], onomata[j + 1]);
                swap(epidoseis[j], epidoseis[j+1]);
                swapped = true;
            }
            // If first vector items match, check second vector
            else if ((epidoseis[j] == epidoseis[j+1] ) 
            && (onomata[j] > onomata[j + 1])) {
                 swap(onomata[j], onomata[j + 1]);
                 swapped = true;
            }
        }
      
        // If no two elements were swapped, then break
        if (!swapped)
            break;
    }
}

int main()
{
    vector<double> epidoseis;
    vector<string> onomata;
    double epidosi;
    string onoma;
    for (int i=0; i<N; i++)
    {
       cout << "Dwse to onoma tou athliti:";
        cin >> onoma;
        onomata.push_back(onoma);
        cout << "Dwse thn epidosi tou athliti:";
        cin >> epidosi;
        epidoseis.push_back(epidosi);
    }
    

    // Sort vector (by default in ascending order)
    //sort(v.begin(), v.end());

    bubbleSort(epidoseis, onomata);
    
    for (int i=0; i<3; i++){
        cout << onomata[i] << " " << epidoseis[i]<<endl;
    }
        
    return 0;
}