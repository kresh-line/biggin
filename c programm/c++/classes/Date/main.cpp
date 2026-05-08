#include "Date.hpp"
#include "date_functions.hpp"
int main() {
    
    Date d1;
    d1.print();        // 01/01/2000
    d1.printLong();    // January 1, 2000

    Date d2(5, 8, 2026);
    d2.print();        
    d2.printLong();

   /* d2.addDays(20);
    d2.print();

    d2.addMonths(2);
    d2.print();

    d2.addYears(1);
    d2.printLong();*/

    return 0;
}