/* #include <iostream>
using namespace std;
int main() {
    double mithos;
    double foros = 0.0;
    cout << "Enter a mithos: ";
     cin >> mithos;
    if (mithos > 1200)
    { foros = (21.5/100)*mithos; 
        cout << "foros: " << foros; 
    }

else  

    cout << "foros: 0.0 " << endl;
}
 cout << "  \n ta teleyteo poy tha pariseis einai: " << (mithos - foros) << endl;
 
 
return 0;
} 
   
    */

    #include <iostream>
using namespace std;

int main() {
    double misthos, foros, telikos;

    cout << "Dwse ton mistho (0 gia eksodo): ";
    cin >> misthos;

    while (misthos != 0) {
        if (misthos > 1200) {
            foros = misthos * 21.5 / 100;
        } else {
            foros = 0;
        }

        telikos = misthos - foros;

        cout << "Foros: " << foros << " euro" << endl;
        cout << "Telikos misthos: " << telikos << " euro" << endl;
        cout << endl;

        cout << "Dwse ton mistho (0 gia eksodo): ";
        cin >> misthos;
    }

    cout << "Telos programmatos!" << endl;

    return 0;
}
    
