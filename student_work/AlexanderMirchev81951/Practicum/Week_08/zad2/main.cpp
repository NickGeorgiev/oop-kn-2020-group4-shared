#include <iostream>
#include "Pair.h"
#include "CommonPair.h"

int main() {
    CommonPair cp(2,2);
    std::cout << cp.first() << " "<< cp.second() << std::endl;

    Pair<int, const char*> pair(2, "pear");
    std::cout << pair.first() << " "<< pair.second() << std::endl;


    return 0;
}