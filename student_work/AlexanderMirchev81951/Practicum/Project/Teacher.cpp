#include <iostream>
#include <cstring>
#include "Teacher.h"


Teacher::Teacher (const char* const firstName, const char* const lastName, const int classNum) {
    copy(firstName, lastName, classNum);
}
Teacher::Teacher(): Teacher("", "", 0) {}
Teacher::Teacher (const Teacher& other) {
    copy(other);
}
Teacher::~Teacher () {
    freeMemory();
}
Teacher& Teacher::operator= (const Teacher& other) {
    if(&other != this) {
        freeMemory();
        copy(other);
    }
    return *this;
}
Teacher::Teacher(Teacher&& other) {
    copy(other);
    other.freeMemory();
}
Teacher& Teacher::operator= (Teacher&& other) {
    if(&other != this) {
        freeMemory();
        copy(other);
    }
    other.freeMemory();
    return *this;
}

std::ostream& operator << (std::ostream &out, const Teacher& teacher) {
    out << teacher.firstName << " " << teacher.lastName << " " << teacher.classNum << "\n";    
    return out;
}
std::istream& operator >> (std::istream &in, Teacher& teacher) {
    in >> teacher.firstName >> teacher.lastName >> teacher.classNum;
    return in;
}

// Private methods

void Teacher::copy(const char* const firstName, const char* const lastName, const int classNum) {
    this->firstName = new char[strlen(firstName) + 1];
    strcpy(this->firstName, firstName);
    this->lastName = new char[strlen(lastName) + 1];
    strcpy(this->lastName, lastName);
    this->classNum = classNum;
}
void Teacher::copy(const Teacher& other) {
    copy(other.firstName, other.lastName, other.classNum);
}
void Teacher::freeMemory() {
    if(firstName != nullptr) {
        delete[] firstName;
    }
    if(lastName != nullptr) {
        delete[] lastName;
    }
}
