#include <cassert>
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "University.h"
University::University(const Student* const students, const size_t& numberOfStudents,
               const Teacher* const teachers, const size_t& numberOfTeachers,
               const Course* const courses, const size_t& numberOfCourses) {
                   copy(students, numberOfStudents, teachers, numberOfTeachers, courses, numberOfCourses);
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
const Course* const University::getCourses() const {
    return this->courses;
}
const size_t& University::getNumberOfCourses() const {
    return this->numberOfCourses;
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
void University::addStudent(const Student& student, const size_t& courseIndex) {
    assert(contains(student) && (courseIndex < numberOfCourses));
    courses[courseIndex].addStudent(student);
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

    std::cout << "Course\n";
    for (size_t i = 0; i < university.numberOfCourses; i++) {
        out << university.courses[i];
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

// Couldn't think of a proper way to implement == in course without extra members
bool University::contains(const Course& course) const {
    return true;
}
void University::copy(const Student* const students, const size_t& numberOfStudents,
               const Teacher* const teachers, const size_t& numberOfTeachers,
               const Course* const courses, const size_t& numberOfCourses) {
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
        this->courses = new Course[numberOfCourses];
        for (size_t i = 0; i < numberOfCourses; i++) {
            this->courses[i] = courses[i];
        }
        this->numberOfCourses = numberOfCourses;
}
void University::copy(const University& other) {
    copy(other.students, other.numberOfStudents, other.teachers, 
    other.numberOfTeachers, other.courses, other.numberOfCourses);
}
void University::freeMemory() {
    if(this->students != nullptr) {
        delete[] this->students;
    }
    if(this->teachers != nullptr) {
        delete[] this->teachers;
    }
    if(this->courses != nullptr) {
        delete[] this->courses;
    }   
}
