#include <iostream>
#include <string>
using namespace std;
#define M 5

int main()
{

    string onoma[M];
    double vathmos[M];

    for (int i = 0; i < M; i++)
    {

        cout << "Dwse to onoma tou " << i + 1 << "ou mathiti :";
        cin >> onoma[i];
        do
        {
            cout << "Dwse to vathmo tou " << i + 1 << "ou mathiti [0-100]:";
            cin >> vathmos[i];
        } while (vathmos[i] < 0 || vathmos[i] > 100);
    }

    for (int i = M - 1; i >= 0; i--)
    {
        cout << onoma[i] << "  " << vathmos[i] << endl;
    }

    double average, sum = 0.0;

    for (int i = 0; i < M; i++)
    {
        sum += vathmos[i];
    }

    average = sum / M;

    cout << "Mesos oros vathmologias " << average << endl;

    for (int i = 0; i < M; i++)
    {
        if (vathmos[i] > average)
            cout << onoma[i] << " " << vathmos[i] << endl;
    }

    double maxVathmos = vathmos[0];
    int thesiMax = 0;

    for (int i = 1; i < M; i++)
    {
        if (vathmos[i] > maxVathmos)
        {
            maxVathmos = vathmos[i];
            thesiMax = i;
        }
    }

    cout << "Max vathmos = " << maxVathmos << " Mathitis " << onoma[thesiMax] << endl;

    int count = 0;

    for (int i = 0; i < M; i++)
    {
        if (vathmos[i] > 60)
            count++;
    }

    if (count > 0)
        cout << "Brethikan " << count << " mathites me vathmologia > 60" << endl;
    else
        cout << "De brethikan mathites me vathmologia > 60" << endl;
}