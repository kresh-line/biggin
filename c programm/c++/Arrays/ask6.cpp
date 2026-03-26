/*#include <iostream>
using namespace std;

#define M 10

int main() {

    double temp[M];

    for (int i = 0; i < M; i++) {
        cout << "Dwse ti thermokrasia gia tin " << i + 1 << " os  mera: ";
        cin >> temp[i];
    
    }

    double sum = 0.0;
    double max = temp[0];

    for (int i = 0; i < M; i++) {
        sum+=temp[i];
        if (temp[i] > max){
            max = temp[i];}
    }

    double mesos_oros = sum / M;
 
    for (int i=0; i<M; i++){
        if (temp[i]> mesos_oros)
        cout << temp[i];
    }
    cout << "Mesos oros thermokrasias: " << mesos_oros << endl;
    cout << "Megisti thermokrasia: " << max << endl;

    return 0;
}
*/

#include <iostream>
using namespace std;
#define N 10

int main()
{
    double temp[N];
    double sum = 0.0, average;

    cout << "Enter temperatures for " << N << " days:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "Temperature for day " << i + 1 << ": ";
        cin >> temp[i];
        sum += temp[i];
    }
    average = sum / N;

    for (int i = 0; i < N; i++)
    {
        if (temp[i] > average)
            cout << temp[i];
    }

    double maxTemp = temp[0];

    for (int i = 1; i < N; i++)
    {
        if (temp[i] > maxTemp)
        {
            maxTemp = temp[i];
        }
    }

    cout << "Average temperature: " << average << endl;
    cout << "Maximum temperature: " << maxTemp << endl;

    return 0;
}