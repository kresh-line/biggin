#include <iostream>
#include <string>

using namespace std;

typedef struct
{
    int id;
    string name;
    string address;
    string telephone;
    /* data */
} Person;

int main()
{
    Person p1;
    Person *person_ptr;
    person_ptr = &p1;
    cout << "Dwse id: ";
    cin >> p1.id;

    cin.ignore();

    cout << "Dwse onoma: ";
    getline(cin, p1.name);

    cout << "Dwse dieuthnsi: ";
    getline(cin, p1.address);

    cout << "Dwse tilefono: ";
    getline(cin, p1.telephone);

    cout << "Ta stoixeia tou atomou einai: " << endl;
    cout << "Id: " << person_ptr->id << endl;
    cout << "Onoma: " << person_ptr->name << endl;
    cout << "Dieuthnsi: " << person_ptr->address << endl;
    cout << "Tilefono: " << person_ptr->telephone << endl;
    cin.get();
    return 0;
}