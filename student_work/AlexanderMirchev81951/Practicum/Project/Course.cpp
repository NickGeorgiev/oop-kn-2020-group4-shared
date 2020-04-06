#include <iostream>
#include <fstream>
#include "Student.h"
#include "Teacher.h"
#include "Course.h"

// Constructors

Course::Course(const Teacher& teacher, const Student* const students, const size_t size): 
        teacher{teacher}, numberOfStudents{size}, students{new Student[size]} {
    copyDynamicMemory(students);
}
Course::Course(): Course(Teacher(), nullptr, 0) { }
Course::Course(const Course& course): Course(course.teacher, course.students, course.numberOfStudents) {}
Course:: ~Course() {
    freeMemory();
}

// Operators

std::ostream& operator << (std::ostream& out, const Course& course) {
    out << course.teacher;
    out << "\n" << course.numberOfStudents << "\n";
    for (size_t i = 0; i < course.numberOfStudents; i++) {
        out << course.students[i];
    }
    return out;
}
std::istream& operator >> (std::istream& in, Course& course) {
    in >> course.teacher >> course.numberOfStudents;
    Student* newStudents = new Student[course.numberOfStudents];
    for (size_t i = 0; i < course.numberOfStudents; i++) {
        in >> newStudents[i];
    }
    course.students = newStudents;
    return in;
}

// Public methods

void Course::addStudent(const Student& student) {
    Student* newStudents = new Student[numberOfStudents + 1];
    for (size_t i = 0; i < numberOfStudents; i++) {
        newStudents[i] = students[i];
    }
    newStudents[numberOfStudents] = student;
    numberOfStudents++;
    freeMemory();
    this->students = newStudents;
}
void Course::assignTeacher(const Teacher& teacher) {
    this->teacher = teacher;
}
void Course::serialize(const char* const destinationFile) {
    std::ofstream out;
    out.open (destinationFile);
    out << *this;
    out.close();
}
void Course::deserialize(const char* const sourceFile) {
    std::ifstream in;
    in.open(sourceFile);
    in >> *this;
    in.close();
}

// Private methods

void Course::copyDynamicMemory(const Student* const students) {
    for (size_t i = 0; i < numberOfStudents; i++)
    {
        this->students[i] = students[i];
    }    
}
void Course::freeMemory() {
    delete[] students;
}
