#ifndef _COMPUTERSHOP_H
#define _COMPUTERSHOP_H

#include <iostream>


#include "../Computer/Computer.h"

class ComputerShop {
    char* name;
    Computer* list;
    size_t amount;

    void copy(const ComputerShop& other);

    public:
    
    ComputerShop ();
    ComputerShop (const ComputerShop& other);
    ComputerShop& operator = (const ComputerShop& other);
    ~ComputerShop ();

    ComputerShop (char* _name, Computer* _list, size_t _amount);
    void addComputer (const Computer& other);
    void printComputers () const;
    void buyComputer (const Computer& other); 


};
#endif