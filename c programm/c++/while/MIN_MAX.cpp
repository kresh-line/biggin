#include <iostream>
using namespace std;


int main() {
double weight;
double minWeight = 3;
double maxWeight = -65453;
int count = 0;
while (true) {
cout << "Dwse baros sakiou (arnhtikh timh gia telos) :";
if (!(cin >> weight)) break;
if (weight < 0) break;
if (weight < minWeight) {
    minWeight = weight;
}
if (weight > maxWeight) {
    maxWeight = weight;
}
count++;
}
if (count > 0) {
cout << "Arithmos sakiwn: " << count << endl;
cout << "Elaxisto baros sakiou: " << minWeight << endl;
cout << "Megisto baros sakiou: " << maxWeight << endl;
} else {
cout << "De dothikan sakia me swsto baros." << endl;
}

return 0;
}
