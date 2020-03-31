#include <iostream>
#include <cstring>
#include "../zad1/Computer.h"
#include "ComputerShop.h"

ComputerShop::ComputerShop(const char* const name, const Computer* const computers, 
        const size_t& numberOfComputers) {
            copy(name, computers, numberOfComputers);
}
ComputerShop::ComputerShop(const ComputerShop& computer): 
    ComputerShop(computer.name, computer.computers, computer.numberOfComputers) {}
ComputerShop::~ComputerShop() {
    free();
}

void ComputerShop::addComputer(const Computer& computer) {
    const int index = getComputerPositionByBrand(computer.getBrand());
    if(index >= 0) {
        computers[index].setQuantity
            (computers[index].getQuantity() + computer.getQuantity());
    }
    else {
        Computer* newComputers = new Computer[numberOfComputers + 1];
        for (size_t i = 0; i < numberOfComputers; i++) {
            newComputers[i] = computers[i];
        }
        newComputers[numberOfComputers++] = computer;
        delete[] computers;
        computers = newComputers;
    }
 }
void ComputerShop::printAllComputers(std::ostream& out) const {
    for (size_t i = 0; i < numberOfComputers; i++)
    {
        out << computers[i] << '\n';
    }
}
void ComputerShop::purchase(const char* const brand, const int desiredQuantity, std::ostream& out) {
    const int index = getComputerPositionByBrand(brand);
    if(index >= 0) {
        if(desiredQuantity > computers[index].getQuantity()) {
            out << "Cannot purchase: Not enough quantity." << '\n';
            out << "You want " << desiredQuantity << " but there is only " << 
                computers[index].getQuantity() << " " << computers[index].getBrand() << ".\n"; 
            return;
        }
        else {
            computers[index].setQuantity(computers[index].getQuantity() - desiredQuantity);
            out << "Purchase successful.\n";
            return;
        }
    } else {
        out << "Cannot purchase: Invalid brand name." << '\n';
        return;
    }
}

// Returns -1 if the brand is not found. Otherwise returns the first occurrence.
const int ComputerShop::getComputerPositionByBrand(const char* const brandName) const {
    for (size_t i = 0; i < numberOfComputers; i++) {
        if(strcmp(computers[i].getBrand(), brandName) == 0) {
            return i;
        }
    }
    return -1; 
}

void ComputerShop::copy(const char* const name, const Computer* const computers, const size_t& size) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->computers = new Computer[size];
    for (size_t i = 0; i < size; i++)
    {
        this->computers[i] = computers[i];
    }
    this->numberOfComputers = size;
}
void ComputerShop::free() {
    delete[] name;
    delete[] computers;
}
