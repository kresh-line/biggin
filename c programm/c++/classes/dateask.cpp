
#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    // Helper: days in each month
    int daysInMonth(int m, int y) {
        if (m == 2) { // February
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
                return 29;
            return 28;
        }
        if (m == 4 || m == 6 || m == 9 || m == 11)
            return 30;
        return 31;
    }

    string getMonthName(int m) {
        string months[] = {"Ianouariou", "Febrouariou", "Martiou", "Apriliou",
                           "Maioy", "Iouniou", "Iouliou", "Augustou",
                           "Septembriou", "Octobriou", "Novembriou", "Decembriou"};
        return months[m-1];
    }

public:
    // Default constructor
    Date() {
        month = 1;
        day = 1;
        year = 2000;
    }

    // Parameterized constructor
    Date(int month, int day, int year) {
        setDate(month, day, year);
    }

    // Setter
    void setDate(int month, int day, int year) {
        this->month = month;
        this->day = day;
        this->year = year;
    }

    // Getters
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }

    // Print MM/DD/YYYY
    void print() {
        cout << (month < 10 ? "0" : "") << month << "/"
             << (day < 10 ? "0" : "") << day << "/"
             << year << endl;
    }

    // Print MonthName Day, Year
    void printLong() {
        cout <<  day << " " << getMonthName(month) << " " << year << endl;
    }

    // Add days
    void addDays(int d) {
        day += d;

        while (day > daysInMonth(month, year)) {
            day -= daysInMonth(month, year);
            month++;

            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

    // Add months
    void addMonths(int m) {
        month += m;

        while (month > 12) {
            month -= 12;
            year++;
        }

        // Adjust day if invalid for new month
        if (day > daysInMonth(month, year)) {
            day = daysInMonth(month, year);
        }
    }

    // Add years
    void addYears(int y) {
        year += y;

        // Handle Feb 29 case
        if (month == 2 && day == 29 && daysInMonth(month, year) == 28) {
            day = 28;
        }
    }
};

int main() {
    Date d1;
    d1.print();        // 01/01/2000
    d1.printLong();    // January 1, 2000

    Date d2(11, 16, 2021);
    d2.print();        
    d2.printLong();

    d2.addDays(20);
    d2.print();

    d2.addMonths(2);
    d2.print();

    d2.addYears(1);
    d2.printLong();

    return 0;
}