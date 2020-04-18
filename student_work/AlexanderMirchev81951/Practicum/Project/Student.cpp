#include <iostream>
#include <cstring>
#include "Student.h"

// Constructors

Student::Student(const char* const firstName, const char* const lastName, const int facNum, 
                const int* const grades, const size_t numberOfGrades) { 
    copy(firstName, lastName, facNum, grades, numberOfGrades);
}
Student::Student(): Student("", "", 0, nullptr, 0) {}
Student::Student(const Student& other) {
    copy(other);
}
Student::~Student() {
    freeMemory();
}
Student& Student::operator= (const Student& other) {
    if(&other != this) {
        freeMemory();
        copy(other);
    }
    return *this;
}
Student::Student(Student&& other) {
    copy(other);
    other.freeMemory();
}
Student& Student::operator = (Student&& other) {
    if(&other != this) {
        freeMemory();
        copy(other);
    }
    other.freeMemory();
    return *this;
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

bool Student::operator== (const Student& other) const {
    return facNumber == other.facNumber;
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
    strcpy(this->firstName, firstName),
    this->lastName = new char[strlen(lastName) + 1];
    strcpy(this->lastName, lastName);
    this->facNumber = facNum;
    this->grades = new int[numberOfGrades];
    this->numberOfGrades = numberOfGrades;
    for (size_t i = 0; i < numberOfGrades; i++)
    {
        this->grades[i] = grades[i];
    }    
}

void Student::copy(const Student& other) {
    copy(other.firstName, other.lastName, other.facNumber, other.grades, other.numberOfGrades);
}

void Student::freeMemory() {
    if(firstName != nullptr) {
        delete[] firstName;
    }
    if(lastName != nullptr) {
        delete[] lastName;
    }
    if(grades != nullptr) {
        delete[] grades;
    }
}
