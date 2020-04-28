#include <iostream>
#include <fstream>
#include "Student.h"
#include "Teacher.h"
#include "Subject.h"

// Constructors

Subject::Subject(const Teacher& teacher, const Student* const students, const size_t& size) {
    copy(teacher, students, size);
}
Subject::Subject(): Subject(Teacher(), nullptr, 0) { }
Subject::Subject(const Subject& other) {
    copy(other);
}
Subject:: ~Subject() {
    freeMemory();
}

Subject& Subject::operator= (const Subject& other) {
    freeMemory();
    copy(other);
    return *this;
}
Subject::Subject(Subject&& other) {
    copy(other);
    other.freeMemory();
}
Subject& Subject::operator= (Subject&& other) {
    freeMemory();
    copy(other);
    other.freeMemory();
    return *this;
}

// Operators

std::ostream& operator << (std::ostream& out, const Subject& subject) {
    out << subject.teacher << subject.numberOfStudents;
    for (size_t i = 0; i < subject.numberOfStudents; i++) {
        out << subject.students[i];
    }
    return out;
}
std::istream& operator >> (std::istream& in, Subject& subject) {
    in >> subject.teacher >> subject.numberOfStudents;
    Student* newStudents = new Student[subject.numberOfStudents];
    for (size_t i = 0; i < subject.numberOfStudents; i++) {
        in >> newStudents[i];
    }
    subject.students = newStudents;
    return in;
}

// Public methods

void Subject::addStudent(const Student& student) {
    Student* newStudents = new Student[numberOfStudents + 1];
    for (size_t i = 0; i < numberOfStudents; i++) {
        newStudents[i] = students[i];
    }
    newStudents[numberOfStudents] = student;
    numberOfStudents++;
    freeMemory();
    this->students = newStudents;
}
void Subject::assignTeacher(const Teacher& teacher) {
    this->teacher = teacher;
}
void Subject::serialize(const char* const destinationFile) {
    std::ofstream out;
    out.open (destinationFile);
    out << *this;
    out.close();
}
void Subject::deserialize(const char* const sourceFile) {
    std::ifstream in;
    in.open(sourceFile);
    in >> *this;
    in.close();
}

// Private methods

void Subject::copy(const Teacher& teacher, const Student* const students, const size_t& numberOfStudents) {
    this->teacher = teacher;
    this->numberOfStudents = numberOfStudents;
    this->students = new Student[numberOfStudents];
    for (size_t i = 0; i < numberOfStudents; i++)
    {
        this->students[i] = students[i];
    }  
}
void Subject::copy(const Subject& other) {
    copy(other.teacher, other.students, other.numberOfStudents);
}
void Subject::freeMemory() {
    delete[] students;
}
