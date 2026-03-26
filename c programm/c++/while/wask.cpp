#include <iostream>
using namespace std;
 #define WEIGHT_LIMIT 1400.0

int main () {
   
double weight;
double totalWeight = 0;
int over70=0;
 
int count = 0;
double averageWeight;
double maxWeight = 1e-9;
double minWeight = 1e9;
bool continueAdding = true;

while (continueAdding) {
  cout << "Dwse baros tou dematos: ";
  cin >> weight;

  if (weight + totalWeight > WEIGHT_LIMIT) {
    cout << "Den mporei na prostethei to demata sto fortigo giati ypervainei to ogko tou fortigou." << endl;
    break;
  }

  totalWeight += weight;
  count++;
  if (weight > maxWeight) maxWeight = weight;
  if (weight < minWeight) minWeight = weight;
  if (weight > 70) over70++;

  if (count % 2 == 0) {
    char answer;
    cout << "Thelete na prosthesete perissotera demata? (y/n): ";
    cin >> answer;
    if (answer == 'n' || answer == 'N') {
      continueAdding = false;
    }
  }
}
if (count > 0) {
cout << "\nTo fortigo fortothike me " << count << " demata." << endl;
averageWeight = totalWeight / count;

cout << "Synoliko baros: " << totalWeight << endl;
cout << "Mesos oros barous: " << averageWeight << endl;
cout << "Elaxisto baros dematos: " << minWeight << endl;
cout << "Megisto baros dematos: " << maxWeight << endl;
cout << "Arithmos dematwn me baros > 70kg: " << over70 << endl;
} else {
cout << "De fortothikan demata sto fortigo." << endl;
}
return 0; 
}

