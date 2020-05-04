#ifndef _STUDENT_HH
#define _STUDENT_HH

#include <iostream>
#include "User.h"

class Student: public User {

    private:

    int facNumber;
    int course;
    int* grades;
    size_t numberOfGrades;

    public:
    Student();
    Student(const char* const firstName, const char* const lastName, const char* const password, 
        const int facNum, const int course, const int* const grades, const size_t numberOfGrades);
    Student(const Student&);
    ~Student();
    Student& operator = (const Student&);
    Student(Student&&);
    Student& operator = (Student&&);

    friend std::ostream& operator << (std::ostream&, const Student&);
    friend std::istream& operator >> (std::istream&, Student&);
    bool operator== (const Student&) const;

    // Public methods

    bool isInCourse(const int course) const {
        return course == this->course;
    }

    double averageGrade() const;

    private:

    // Private Methods

    void copy(const int facNum, const int course, 
        const int* const grades, const size_t& numberOfGrades);
    void copy(const Student&);
    void freeMemory();
};
#endif