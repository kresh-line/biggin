#include "vehicles.hpp"

class Truck : public Vehicle {
    private:
        double max_weight;

    public:
        Truck(string reg, string name, int cc_, double max_)
            : Vehicle(reg, name, cc_), max_weight(max_) {}

        void print() {
            cout << "Registration: " << registration_number << endl;
            cout << "Owner: " << owner_name << endl;
            cout << "CC: " << cc << endl;
            cout << "Max Weight: " << max_weight << " kg" << endl;
            cout << "kteli kykloforias: " << traffic_tax() << endl;

        }
    double traffic_tax(){
        double tax;
        if (max_weight <= 3000)
            tax = 400;
        else if (max_weight <= 6000)
            tax = 400;
        else 
            tax = 600;      
        return tax;
    }    
};
