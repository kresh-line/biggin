#include <iostream>
#include <compare>

int main() {
    auto result = (10 <=> 20);
    if (result > 0)
        std::cout << "10 > 20" << std::endl;
    else if (result < 0)
        std::cout << "10 < 20" << std::endl;
    else
        std::cout << "10 == 20" << std::endl;
    return 0;
}

