#include <iostream>

#include "FacultyMember.h"

int main() {
    FacultyMember facMem("stoqn", 3, 50000);
    std::cout << facMem.getName() << " " <<  facMem.getNumber() << " " << facMem.getSalary() << std::endl;
    return 0;
}