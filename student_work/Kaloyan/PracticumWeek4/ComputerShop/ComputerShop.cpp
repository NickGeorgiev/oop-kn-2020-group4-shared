#ifndef _COMPUTERSHOP_CPP
#define _COMPUTERSHOP_CPP

# include <iostream>
# include <cstring>

#include "../Computer/Computer.h"
#include "ComputerShop.h"

void ComputerShop::copy(const ComputerShop& other) {
    if(this != &other) {
        delete [] name;
        delete [] list;

        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        amount = other.amount;
        list = new Computer[amount];
        for (int i = 0; i < amount; i++) {
            list[i] = other.list[i];
        }
    }
}

ComputerShop::ComputerShop() {
    name = nullptr;
    list = nullptr;
}
ComputerShop::ComputerShop (const ComputerShop& other) {
    copy(other);
}
ComputerShop& ComputerShop::operator= (const ComputerShop& other) {
    copy(other);
    return *this;
}
ComputerShop::~ComputerShop () {
    delete [] name;
    name = nullptr;
    delete [] list;
    list = nullptr;
}

ComputerShop::ComputerShop (char* _name, Computer* _list, size_t _amount): amount{_amount} {
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);

    list = new Computer[amount];
    for (int i = 0; i < amount; i++) {
        list[i] = _list[i];
    }
}

void ComputerShop::addComputer (const Computer& other) {
    bool flag = false;
    for (int i = 0; i < amount; i++) {
        if(list[i] == other) {
            list[i].changeQuantity(1);
            flag = true;
            break;
        }
    }
    if(!flag) {
        Computer* _list = new Computer[amount + 1];
        for (int i = 0; i < amount; i++) {
            _list[i] = list[i];
        }
        _list[amount++] = other;
        delete [] list;
        list = _list;
    }
}

void ComputerShop::printComputers() const{
    for (int i = 0; i < amount; i++) {
        list[i].print();
    }
}

void ComputerShop::buyComputer (const Computer& other) {
    for (int i = 0; i < amount; i++) {
        if(list[i] == other && list[i].getQuantity() > 0) {
            list[i].changeQuantity(-1);
            return;
        }
    }
}

#endif