#include <iostream>
#include <cstring>
#include "Teacher.h"


Teacher::Teacher (const char* const firstName, const char* const lastName, const char* const password, 
    const int classNum): User(firstName, lastName, password) {
    this->classNum = classNum;
}
Teacher::Teacher(): Teacher("", "","", 0) {}
Teacher::Teacher (const Teacher& other) {
    copy(other);
}
Teacher::~Teacher () {}

Teacher& Teacher::operator= (const Teacher& other) {
    if(&other != this) {
        copy(other);
    }
    return *this;
}
Teacher::Teacher(Teacher&& other) {
    copy(other);
}
Teacher& Teacher::operator= (Teacher&& other) {
    if(&other != this) {
        copy(other);
    }
    return *this;
}

std::ostream& operator << (std::ostream &out, const Teacher& teacher) {
    out << (const User&) teacher << " " << teacher.classNum << "\n";    
    return out;
}
std::istream& operator >> (std::istream &in, Teacher& teacher) {
    in >> (User&) teacher >> teacher.classNum;
    return in;
}

// Private methods

void Teacher::copy(const Teacher& other) {
    User::operator=((const User&) other);
    this->classNum = other.classNum;
}

