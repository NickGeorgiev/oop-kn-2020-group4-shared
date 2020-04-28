#ifndef _STUDENT_HH
#define _STUDENT_HH

#include "Person.h"

class Student: virtual public Person {
private:
    int number;
public:
    Student(const char* const name, const int number): Person(name) {
        this->number = number;
    }
    const int getNumber() const {
        return this->number;
    }
};
#endif