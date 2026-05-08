#include "Date.hpp"

string Date::getMonthName(int m) {
        string months[] = {"Ianouariou", "Febrouariou", "Martiou", "Apriliou",
                           "Maioy", "Iouniou", "Iouliou", "Augustou",
                           "Septembriou", "Octobriou", "Novembriou", "Decembriou"};
        return months[m-1];
    }