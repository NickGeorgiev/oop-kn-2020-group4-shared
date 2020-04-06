#include <iostream>
#include <cstring>
#include "Student.h"

// Constructors

Student::Student(const char* const firstName, const char* const lastName, const int facNum, 
                const int* const grades, const size_t numberOfGrades): 
        firstName{new char[strlen(firstName) + 1]}, lastName{new char[strlen(lastName) + 1]}, 
        facNumber{facNum}, grades{new int[numberOfGrades]}, numberOfGrades{numberOfGrades} { 
    copyDynamicMemory(firstName, lastName, grades);
}
Student::Student(): 
        Student("", "", 0, nullptr, 0) {}
Student::Student(const Student& student): 
        Student(student.firstName, student.lastName, student.facNumber, student.grades, student.numberOfGrades) {}
Student::~Student() {
    free();
}

// Operators

void Student::operator= (const Student& student) {
    free();
    copy(student.firstName, student.lastName, student.facNumber, student.grades, student.numberOfGrades);    
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
    return (double) sum / numberOfGrades;
}

// Private methods

void Student::copy(const char* const firstName, const char* const lastName, const int facNum, const int* const grades, 
        const size_t& numberOfGrades) {
    this->firstName = new char[strlen(firstName) + 1];
    this->lastName = new char[strlen(lastName) + 1];
    this->facNumber = facNum;
    this->grades = new int[numberOfGrades];
    this->numberOfGrades = numberOfGrades;
    copyDynamicMemory(firstName, lastName, grades);
}
void Student::free() {
    delete[] firstName;
    delete[] lastName;
    delete[] grades;
}

void Student::copyDynamicMemory(const char* const firstName, const char* const lastName, const int* const grades) {
    strcpy(this->firstName, firstName),
    strcpy(this->lastName, lastName);
    for (size_t i = 0; i < numberOfGrades; i++)
    {
        this->grades[i] = grades[i];
    }        
}
