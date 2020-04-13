#ifndef _COMPUTER_CPP
#define _COMPUTER_CPP

#include <iostream>
# include <cstring>
# include "Computer.h"
    
void Computer::setStr(const int& x, const char* str) {
    switch (x) {
        case 0:
            brand = new char[strlen(str) + 1];
            strcpy(brand, str);
            break;
        case 1:
            cpu = new char[strlen(str) + 1];
            strcpy(cpu, str);
            break;
        case 2:
            gpu = new char[strlen(str) + 1];
            strcpy(gpu, str);
            break;
        case 3:
            drive = new char[strlen(str) + 1];
            strcpy(drive, str);
            break; 
        default:
            break;
    }
}
void Computer::copy(const Computer& other) {
    if (this != &other) {
        delete [] brand;
        delete [] cpu;
        delete [] gpu;
        delete [] drive;
        setStr(0, other.brand);
        setStr(1, other.cpu);
        setStr(2, other.gpu);
        setStr(3, other.drive);
        price = other.price;
        quantity = other.quantity;
    }
}

Computer::Computer () : brand{nullptr}, cpu{nullptr}, gpu{nullptr}, drive{nullptr}, price{0.0}, quantity{0} {
    
}

Computer::Computer (const char* _brand, const char* _cpu, const char* _gpu, const char* _drive, const double& _price, const int& _quantity) : price{_price}, quantity{_quantity} {
    setStr(0, _brand);
    setStr(1, _cpu);
    setStr(2, _gpu);
    setStr(3, _drive);
}

Computer::Computer (const Computer& other) {
    copy (other);
}

Computer& Computer::operator = (const Computer& other) {
    copy(other);
    return *this;
}

Computer::~Computer () {
        delete [] brand;
        delete [] cpu;
        delete [] gpu;
        delete [] drive;
}

bool Computer::operator == (const Computer& other) const {
    return strcmp(brand, other.brand) == 0;
}

int Computer::getQuantity() const{
    return quantity;
}
void Computer::changeQuantity(const int& n) {
    quantity += n;
}

void Computer::print() const {
    std::cout << brand << ", " << cpu << ", " << gpu << ", " << drive << ", " << price << ", " << quantity << '\n'; 
}

#endif