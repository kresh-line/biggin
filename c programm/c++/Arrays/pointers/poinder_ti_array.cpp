#include <iostream>
using namespace std;
double getMax(double *vathmoi)
int main()
{
    double vathmoi[5];
double sum = 0.0;
for (int i = 0; i < 5; i++){
    cout << "Dwse vathmo gia to " << i+1 << " mathima [0,10]:";
    cin >> vathmoi[i];
    if (vathmoi[i] < 0 | | vathmoi[i] > 10)
    cout << "Edwses lathos vathmologia" << endl;
}
while (vathmoi[i] < 0 | | vathmoi[i] > 10);
sum += vathmoi[i];
}
cout << "O mesos oros ths vathmologias einai:" << sum/5 << endl;
double maxVath = vathmoi[0];

for (int i=1; i<5; i++){
if (vathmoi[i] > maxVath){
maxVath = vathmoi[i];
}
}
cout << "H megisth vathmologia einai:" << maxVath <<endl;
return 0;
// bëje mirë