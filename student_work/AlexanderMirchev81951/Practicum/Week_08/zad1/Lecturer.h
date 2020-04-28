#ifndef _LECTURER_HH
#define _LECTURER_HH

#include "Person.h"

class Lecturer: virtual public Person {
private:
    int salary;
public:
    Lecturer(const char* const name, const int salary): Person(name) {
        this->salary = salary;
    }

    virtual const int getSalary() const {
        return this->salary;
    }
};
#endif