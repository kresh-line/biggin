#include "Vehicles.hpp"
#include "Car.hpp"
#include "Truck.hpp"
int main()
{       
    Car *cars[5];
    string name, arithmos;
    int cc, doors;
    for (int i=0;  i<5; i++){
        cout << "kteli kykloforias: ";
        cin >> arithmos;
        cout <<"onoma idiokhth: ";
        cin >> name;
        cout << "kybika: ";
        cin >> cc;
        cout << "portes: ";
        cin >> doors;
        cars [i] = new Car(arithmos, name, cc, doors);

    }
    /*cars[0] = new Car("ABC1643", "Jojhgf Doeas", 2600, 5);
    cars[1] = new Car("ABC123", "Johff Doeu", 980, 3);
    cars[2] = new Car("ABC123", "Johngg Doek", 1145, 5);
    cars[3] = new Car("ABC123", "Johnuu Doef", 2065, 5);
    cars[4] = new Car("ABC123", "Johnii Doet", 2504, 5);*/
    for (int i = 0; i<5; i++)
    cars[i]->print();
    //Car car1("ABC123", "John Doe", 2000, 5);
    // Vehicle car2("XYZ789", "Jane Smith", 1500);

    //car1.print();
    // cout << endl;
    // car2.print();
    /*Truck tract1("HPKGEE23", "MANOLAKIS jdds", 34563, 34533);
    tract1.print();
*/
    return 0;
}