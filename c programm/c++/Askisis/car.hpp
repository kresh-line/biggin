#include "Vehicles.hpp"


class Car : public Vehicle {
    private:
        int number_of_doors;
    public:
        Car(string reg_num, string owner, int engine_cc, int doors) : Vehicle(reg_num, owner, engine_cc),number_of_doors(doors) {}
            
        
        void print() {
            cout << "Registration: " << registration_number << endl;
            cout << "Owner: " << owner_name << endl;
            cout << "CC: " << cc << endl;
            cout << "Number of Doors: " << number_of_doors << endl;
        }

        double traffic_tax(){

            double tax = 140.0;
            if (cc <= 1000){
                 tax += (cc-1000)/100*10;
            }
                return tax;
               
            
        }
};

