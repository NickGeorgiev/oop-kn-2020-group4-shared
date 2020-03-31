#include <iostream>
#include <cstring>
#include "Teacher.h"


Teacher::Teacher (const char* const firstName, const char* const lastName, const int classNum):
        firstName{new char[strlen(firstName) + 1]}, lastName{new char[strlen(lastName) + 1]}, classNum{classNum} {
    copyDynamicMemory(firstName, lastName);
}
Teacher::Teacher (): Teacher("", "", 0) {}
Teacher::Teacher (const Teacher& teacher): Teacher(teacher.firstName, teacher.lastName, teacher.classNum) {}
Teacher::~Teacher () {
    freeDynamicMemory();
}

// Operators

void Teacher::operator = (const Teacher& teacher) {
    freeDynamicMemory();

    firstName = new char[strlen(teacher.firstName) + 1];
    lastName = new char[strlen(teacher.lastName) + 1];
    classNum = teacher.classNum;
    copyDynamicMemory(teacher.firstName, teacher.lastName);
}
std::ostream& operator << (std::ostream &out, const Teacher& teacher) {
    out << teacher.firstName << " " << teacher.lastName << " " << teacher.classNum << "\n";    
    return out;
}
std::istream& operator >> (std::istream &in, Teacher& teacher) {
    in >> teacher.firstName >> teacher.lastName >> teacher.classNum;
    return in;
}

// // Friend methods

// bool compareTeachersFirstName(const Teacher& teacher1, const Teacher& teacher2) {
//     return strcmp(teacher1.firstName, teacher2.firstName) > 0 ;
// }

// Private methods

void Teacher::copyDynamicMemory(const char* const firstName, const char* const lastName) {
    strcpy(this->firstName, firstName);
    strcpy(this->lastName, lastName);
}
void Teacher::freeDynamicMemory() {
    delete[] firstName;
    delete[] lastName;
}
