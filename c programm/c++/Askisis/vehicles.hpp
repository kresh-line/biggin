#include <iostream>
#pragma once
using namespace std;



class Vehicle {
    protected:
        string registration_number;
        string owner_name;
        int cc;
    public:
        Vehicle(string reg_num, string owner, int engine_cc) {
        registration_number = reg_num;
        owner_name = owner;
        cc = engine_cc;  
    }
    virtual void print() = 0; // Pure virtual function making Vehicle an abstract class
        
    
};