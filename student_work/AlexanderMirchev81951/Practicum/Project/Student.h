#ifndef _STUDENT_HH
#define _STUDENT_HH

#include <iostream>

class Student {

    private:

    char* firstName;
    char* lastName;
    int facNumber;
    int* grades;
    size_t numberOfGrades;

    public:
    Student();
    Student(const char* const firstName, const char* const lastName, const int facNum, 
            const int* const grades, const size_t numberOfGrades);
    Student(const Student&);
    ~Student();
    Student& operator = (const Student&);
    Student(Student&&);
    Student& operator = (Student&&);

    friend std::ostream& operator << (std::ostream&, const Student&);
    friend std::istream& operator >> (std::istream&, Student&);
    bool operator== (const Student&) const;

    // Public methods

    double averageGrade() const;

    private:

    // Private Methods

    void copy(const char* const firstName, const char* const lastName, const int facNum, 
            const int* const grades, const size_t& numberOfGrades);
    void copy(const Student&);
    void freeMemory();
};
#endif