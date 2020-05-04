#include <iostream>
#include <cstring>
#include "User.h"
#include "Student.h"


// Constructors

Student::Student(const char* const firstName, const char* const lastName, const char* const password, 
        const int facNum, const int course, const int* const grades, const size_t numberOfGrades): 
        User(firstName, lastName, password) { 
    copy(facNum, course, grades, numberOfGrades);
    delete[] grades;
}
Student::Student(): Student("", ""," ", 0, 0, nullptr, 0) {}
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
    out << (const User&)student << " " << student.facNumber << " "<< student.course << " " << student.numberOfGrades<< " ";
    for (size_t i = 0; i < student.numberOfGrades; i++) {
        out << student.grades[i] << " ";
    }
    out << "\n";    
    return out;
}

std::istream& operator >> (std::istream &in, Student& student) {
    in >>(User&) student >> student.facNumber >> student.course >> student.numberOfGrades;
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

void Student::copy(const int facNum, const int course, 
    const int* const grades, const size_t& numberOfGrades) {
    this->facNumber = facNum;
    this->course = course;
    this->grades = new int[numberOfGrades];
    this->numberOfGrades = numberOfGrades;
    for (size_t i = 0; i < numberOfGrades; i++)
    {
        this->grades[i] = grades[i];
    }    
}

void Student::copy(const Student& other) {
    User::operator=((const User&) other);
    copy(other.facNumber, other.course, other.grades, other.numberOfGrades);
}

void Student::freeMemory() {
    if(grades != nullptr) {
        delete[] grades;
    }
}
