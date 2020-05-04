#include <iostream>
#include <cstring>
#include "Student.h"

// Constructors

Student::Student(const char* firstName, const char* lastName, const int facNum, 
                const int* grades, const size_t numberOfGrades): 
        firstName{new char[strlen(firstName) + 1]}, lastName{new char[strlen(lastName) + 1]}, 
        facNumber{facNum}, grades{new int[numberOfGrades]}, numberOfGrades{numberOfGrades} { 
    copyDynamicMemory(firstName, lastName, grades);
}
Student::Student(): 
        Student("", "", 0, nullptr, 0) {}
Student::Student(const Student& student): 
        Student(student.firstName, student.lastName, student.facNumber, student.grades, student.numberOfGrades) {}
Student::~Student() {
    freeDynamicMemory();
}

// Operators

void Student::operator= (const Student& student) {
    freeDynamicMemory();

    firstName = new char[strlen(student.firstName) + 1];
    lastName = new char[strlen(student.lastName) + 1];
    facNumber = student.facNumber;
    grades = new int[student.numberOfGrades];
    numberOfGrades = student.numberOfGrades;
    copyDynamicMemory(student.firstName, student.lastName, student.grades);
}
std::ostream& operator << (std::ostream &out, const Student& student) {
    out << student.firstName << " " << student.lastName << " " << student.facNumber<< " " << student.numberOfGrades<< " ";
    for (size_t i = 0; i < student.numberOfGrades; i++) {
        out << student.grades[i] << " ";
    }
    out << "\n";    
    return out;
}
std::istream& operator >> (std::istream &in, Student& student) {
    in >> student.firstName >> student.lastName >> student.facNumber >> student.numberOfGrades;
    for (size_t i = 0; i < student.numberOfGrades; i++)
    {
        in >> student.grades[i];
    }
    return in;
}

// Methods

double Student::averageGrade() const {
    if(numberOfGrades == 0) {
        return 0;
    } 

    int sum = 0;
    for (size_t i = 0; i < this->numberOfGrades; i++) {
        sum += this->grades[i];
    }
    return sum / numberOfGrades;
}

// Private methods

void Student::copyDynamicMemory(const char* firstName, const char* lastName, const int* grades) {
    strcpy(this->firstName, firstName),
    strcpy(this->lastName, lastName);
    for (size_t i = 0; i < numberOfGrades; i++)
    {
        this->grades[i] = grades[i];
    }        
}
void Student::freeDynamicMemory() {
    delete[] firstName;
    delete[] lastName;
    delete[] grades;
}
