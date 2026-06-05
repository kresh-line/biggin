#include <iostream>
using namespace std;

int main()
{

    double diaireteos, diairetis, piliko;
    cout << "DOSE DIAIRETEO: ";
    cin >> diaireteos;
    cout << "DOSE DIAIRETH: ";
    cin >> diairetis;
    try
    {
        if (diairetis == 0)
            throw diairetis;
        piliko = diaireteos / diairetis;
        cout << "TO PHLIKO EINAI: " << piliko << endl;
    }

    catch (double d)
    {
        cout << "LATHOS: Epixeireite diairesi me to : " << d << endl;
    }
    catch (...)
    {
        cout << "AGNOSTH EKSAIRESH!" << endl;
    }
    return 0;
}
