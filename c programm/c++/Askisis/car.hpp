#include "Vehicles.hpp"


class Car : public Vehicle {
    private:
        int number_of_doors;
    public:
        Car(string reg_num, string owner, int engine_cc, int doors) : Vehicle(reg_num, owner, engine_cc),number_of_doors(doors) {}
            
        
        void print() {
            Vehicle::print();
            cout << "Number of Doors: " << number_of_doors << endl;
        }
};