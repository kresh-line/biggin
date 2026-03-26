#include <iostream>
using namespace std;

int afairesi(int a, int b) {
    return a - b;
}

float phliko(int a, int b) {
    return (float)a / b;
}

float mesos(int a, int b, int c) {
    return (float)(a + b + c) / 3.0;
}

int embad(int a, int b, int y) {
    return (a + b) * y / 2;
}

double embad(double a, double b, double y) {
    return (a + b) * y / 2.0;
}

int main() {
    int x = 10, y = 3;

    cout << "The result of subtraction is " << afairesi(x, y) << endl;
    cout << "The result of division is " << phliko(x, y) << endl;
    cout << "The result of the average is " << mesos(17, 16, 20) << endl;
    cout << "The result of the area (int) is " << embad(5, 6, 3) << endl;
    cout << "The result of the area (double) is " << embad(6.43, 8.92, 3.1) << endl;

    return 0;
}
