
#include <iostream>
using namespace std;
double getAverage(int arr[], int size);
int main () {
int balance[8] = {1000, 2, 3, 17, 50, 23, 42, 69};
double avg;
avg = getAverage(balance, 8);
cout << "Average value is: " << avg << endl; 
return 0;
}
double getAverage(int arr[], int size) {
int i, sum = 0;       
double avg;          
for (i = 0; i < size; ++i) {
sum += arr[i];
}
avg = double(sum) / size;
return avg;
}
//ok