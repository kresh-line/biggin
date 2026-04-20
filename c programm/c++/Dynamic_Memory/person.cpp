#include <iostream>
#include <string>
#include <sstream>
using namespace std;

typedef struct
{
    int id;
    string name;
    string address;
    string telephone;
} Person;

int main()
{
    Person p1;
    Person *person_ptr;
    person_ptr = &p1;
    string mystr;

    cout << "Dwse kodiko: ";
    getline(cin, mystr);
    stringstream(mystr) >> p1.id;

    cout << "Dwse onoma: ";
    getline(cin, p1.name);
    // stringstream(mystr) >> p1.name;

    cout << "Dwse dieuthinsi: ";
    getline(cin, p1.address);
    // stringstream(mystr) >> p1.address;

    cout << "Dwse tilefwno: ";
    getline(cin, p1.telephone);
    // stringstream(mystr) >> p1.telephone;

    cout << "Stoixeia:" << endl;
    cout << person_ptr->id << " " << person_ptr->name << " ";
    cout << person_ptr->address << " " << person_ptr->telephone << " ";
}