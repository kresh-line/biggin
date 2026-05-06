#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date(int d, int m, int y) { day = d; month = m; year = y;}
    void print() {
        cout << day << "/" << month << "/" << year << endl;

    }
    Date(){
        day = 1;
        month = 1;
        year = 2000;
    }
    ~Date() {
        cout << "Date is being destroyed" << endl;
    }
    void setDate(int d, int m, int y) {day = d; month = m; year = y;}
    
    int getDay() {
        return day;
    }
    int getMonth() {
        return month;
    }
    int getYear() {
        return year;
    }    
};

int main() {
  

    Date today(06, 05, 2026);
    Date tomorrow;
    today.print();
    tomorrow.print();

    return 0;
}