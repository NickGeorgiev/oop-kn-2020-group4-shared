#include <cassert>
#include "Student.h"
#include "Teacher.h"
#include "Subject.h"
#include "University.h"
University::University(const Student* const students, const size_t& numberOfStudents,
               const Teacher* const teachers, const size_t& numberOfTeachers,
               const Subject* const subjects, const size_t& numberOfSubjects) {
                   copy(students, numberOfStudents, teachers, numberOfTeachers, subjects, numberOfSubjects);
               }
University::University(const University& other) { }
University::~University() {
    freeMemory();
}
University& University::operator=(const University& other) {
    freeMemory();
    copy(other);
    return *this;
}
University::University(University&& other) {
    copy(other);
    other.freeMemory();
}
University& University::operator=(University&& other) {
    freeMemory();
    copy(other);
    other.freeMemory();
    return *this;
}

const Student* const University::getStudents() const {
    return this->students;
}
const size_t& University::getNumberOfStudents() const {
    return this->numberOfStudents;
}
const Teacher* const University::getTeachers() const {
    return this->teachers;
}
const size_t& University::getNumberOfTeachers() const {
    return this->numberOfTeachers;
}
const Subject* const University::getSubjects() const {
    return this->subjects;
}
const size_t& University::getNumberOfSubjects() const {
    return this->numberOfSubjects;
}

void University::addStudent(const Student& student) {
    if(contains(student)) {
        return;
    }
    Student* newStudents = new Student[numberOfStudents + 1];
    for (size_t i = 0; i < numberOfStudents; i++) {
        newStudents[i] = this->students[i];
    }
    newStudents[numberOfStudents++] = student;
    delete[] this-> students;
    this->students = newStudents;
}
void University::addStudent(const Student& student, Subject& subject) {
    assert(contains(student));
    subject.addStudent(student);
}

// could use optimisation. just for testing
std::ostream& operator << (std::ostream &out, const University& university) {
    std::cout << "Students\n";
    for (size_t i = 0; i < university.numberOfStudents; i++) {
        out << university.students[i];
    }
    
    std::cout << "Teachers\n";
    for (size_t i = 0; i < university.numberOfTeachers; i++) {
        out << university.teachers[i];
    }

    std::cout << "Subject\n";
    for (size_t i = 0; i < university.numberOfSubjects; i++) {
        out << university.subjects[i];
    }
}
bool University::contains(const Student& student) const {
    for (size_t i = 0; i < numberOfStudents; i++) {
        if(students[i] == student) {
            return true;
        }
    }
    return false;    
}

// Couldn't think of a proper way to implement == in subject without extra members
bool University::contains(const Subject& subject) const {
    return true;
}
void University::copy(const Student* const students, const size_t& numberOfStudents,
               const Teacher* const teachers, const size_t& numberOfTeachers,
               const Subject* const subjects, const size_t& numberOfSubjects) {
        this->students = new Student[numberOfStudents];
        for (size_t i = 0; i < numberOfStudents; i++) {
            this->students[i] = students[i];
        }
        this->numberOfStudents = numberOfStudents;
        this->teachers = new Teacher[numberOfTeachers];
        for (size_t i = 0; i < numberOfTeachers; i++) {
            this->teachers[i] = teachers[i];
        }
        this->numberOfTeachers = numberOfTeachers;
        this->subjects = new Subject[numberOfSubjects];
        for (size_t i = 0; i < numberOfSubjects; i++) {
            this->subjects[i] = subjects[i];
        }
        this->numberOfSubjects = numberOfSubjects;
}
void University::copy(const University& other) {
    copy(other.students, other.numberOfStudents, other.teachers, 
    other.numberOfTeachers, other.subjects, other.numberOfSubjects);
}
void University::freeMemory() {
    if(this->students != nullptr) {
        delete[] this->students;
    }
    if(this->teachers != nullptr) {
        delete[] this->teachers;
    }
    if(this->subjects != nullptr) {
        delete[] this->subjects;
    }   
}
